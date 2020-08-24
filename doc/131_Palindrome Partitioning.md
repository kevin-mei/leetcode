#### 题目

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

理解题意：拆分回文串，给定一个字符串s，要求返回一个二维数组，每一行是由s的子串组成，且每一行可以拼接成完整字符串s,每个子串都是回文数，也就是问：将s拆分成回文子串，有多少种拆法(二维数组的行数)，并且给出每一种拆法的结果(二维数组的每行内容)

那么，怎么做？

1. 如何判断一个串是不是回文串，给定字符串s,从它的开头start和结尾end处开始遍历，如果相同，则开头，结尾分别+1，-1，不同返回错误，直到开头和结尾相遇； 偶数位字符串会相遇中间两点上，下一个循环start>end，奇数位字符串会相遇到中间一点上,start=end;下一次start>end, 最后循环结束条件就是start>end

2. 需要遍历字符串s，然后组子串，判断是否为回文串？如果不是，则子串内容+1，如果是，则分下一波；

3. 如何得到多种分法?
> for (int i = start; i < s.size(); ++i) {   //相当于最外层循环，开始分隔字符子串大小从1,2,3直到源串s的大小，这个保证遍历所有分法

```
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> out;
		helper(s, 0, out, res);
		return res;
	}
	void helper(string s, int start, vector<string>& out, vector<vector<string>>& res) {
		if (start == s.size()) { res.push_back(out); return; }
		for (int i = start; i < s.size(); ++i) {   //相当于最外层循环，开始分隔字符子串大小从1,2,3直到源串s的大小，这个保证遍历所有分法
			string substr = s.substr(start, i - start + 1);
			if (!isPalindrome(substr)) continue;
			out.push_back(substr);  // 如果有一次分法的第一个子串是回文串，这个递归保证这次分法 能遍历到字符串的尾部，确认分法是否成功
			helper(s, i + 1, out, res);
			out.pop_back();
		}
	}

	bool isPalindrome(string s) {
		int start = 0, end = s.size()-1;

		while (start < end) {
			if (s[start] != s[end]) return false;
			++start; --end;
		}
		return true;
	}
};
```

可以增加记忆数组 提升效率

接下来是错误示范：
有人想到用vector<string>去存放已经判断是回文串的子串，然后来了回文串和这个字符串数组去对比，看看是否在这个里面， 本身可以做，但是随着数据量的增加，这个方法只会越变越慢，你去对比新来的子串是否是回文串的时候，要去遍历这个数组，还要去对比两个string对象是否相等， 这带来的时间复杂度绝对比 直接看回文串要大的多；

正解：
记忆数据，emmm , 因为题里要求是需要拿到所有的子串，那你就不能用 从位置i到末尾是否有可以组成回文串来判断； 再看看现有的代码，你得到子串的时候是通过substr得到的，两个参数是：开始位置，加偏移位数， 那么你能知道你的子串的前后下标是什么; 那么可以用 dp[i][j]表示从源串的位置i到位置j （闭区间，dp[0][0] 就表示sting 的第一个字符是否为回文串； dp[0][3] 就表示下标为0123共4个位置的子串是否为回文串）的子串是否为回文串， 这是一个bool的二维数组； 通过下标访问 时间复杂度为o(1)， 判断是否为1即可，因此才会提升效率


bool的二维数组,emmm,二维数组，int a[3][4]; 这种定义不行啊，我们的二维数组大小是string的长度，动态的，得new， emmm， 怎么new来着？ 复习一下：

```
// 已知string s
// 行列都不知道的大小的
bool **dp1 = new bool* [s.size()];
for (int i = 0; i < s.size(); i++)
{
    dp1[i] = new bool[s.size()];
}

// 行列大小固定的  emmmm， mmp, 行列大小固定谁用new去，直接创建就好了，new什么new
int (*dp2)[5] = new int[5][10];
```

不过都9102年了，来，C++替代数组的是啥？ vector，哎，对了，走你
```
// 已知sting s
vector<vector<bool> > dp(s.size(), vector<bool>(s.size()));
```

**那么问题来了，是先创建好数组呢**（从两重循环，确认是否为回文串，然后对比）
**还是边填元素，边比对呢?**（数组初始都为false, 如果对比数组元素不成功，再判断回文串然后将数组对应元素置为true, 如果对比数组元素成功，直接放入out）


答案是，都可以，测试了下，先还是边填元素，边比对的会快一丢丢；贴上两种方式代码

```
// 先创建好记忆数组再对比
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string> > res;
		vector<string> out;
		vector<vector<bool> > dp(s.size(), vector<bool>(s.size()));
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i+1; j <= s.size(); j++)
			{
				if (!isPalindrome(s.substr(i, j-i)))
					continue;
				else
					dp[i][j-1] = true;
			}
		}

		helper(s, 0, out, res, dp);
		return res;
	}

	void helper(string s, int start, vector<string>& out, vector<vector<string> >& res, vector<vector<bool> >& dp) {
		if (start == s.size()) 
		{ 
			res.push_back(out); return; 
		}
		for (int i = start; i < s.size(); ++i) {
			string substr = s.substr(start, i - start + 1);

			if (!dp[start][i])
			{
				continue;
			}
			out.push_back(substr);
			helper(s, i + 1, out, res,dp);
			out.pop_back();
		}
	}
    	bool isPalindrome(string s) {
            int start = 0, end = s.size()-1;

            while (start < end) 
            {
                if (s[start] != s[end]) return false;
                ++start; --end;
			}
		return true;
	}
};

```

```
// 记忆数组边填元素边对比
class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
		vector<string> out;
		vector<vector<bool> > dp(s.size(), vector<bool>(s.size()));
		helper(s, 0, out, res, dp);
		return res;
	}

	void helper(string s, int start, vector<string>& out, vector<vector<string> >& res, vector<vector<bool> >& dp) {
		if (start == s.size()) { res.push_back(out); return; }
		for (int i = start; i < s.size(); ++i) {
			string substr = s.substr(start, i - start + 1);

			if (!dp[start][i]) {
				if(!isPalindrome(substr))
					continue;
				else
					dp[start][i] = true;
			}

			out.push_back(substr);
			helper(s, i + 1, out, res,dp);
			out.pop_back();
		}
	}
    	bool isPalindrome(string s) {
		int start = 0, end = s.size()-1;

		while (start < end) {
			if (s[start] != s[end]) return false;
			++start; --end;
		}
		return true;
	}
};

```





