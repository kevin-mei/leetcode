### 题目
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

```
class Solution {
public:
    string reverseWords(string s) {
	}
};
```
### 题目解释：
给定一个字符串,字符串里有很多单词，单词之间使用空格分隔，可能两个单词之间有多个空格，或者有最后一个单词到字符串末尾也有空格；  需要做的是： 将这个字符串中按照单词翻转，且翻转后的字符串单词之间只能有一个空格，首尾不能有空格，具体可看给出的示例结果

解决思路一：
一拿到题目，发现自己之前做过给定字符串和分隔符，返回一个vector数组，存放着按照分隔符分开的子串（[具体见此链接](https://blog.csdn.net/Kevin__Mei/article/details/89480509)）；amazing,完全可以套用，都拿到分隔后的子串了，我在倒叙输出到string里，这还不是分分钟的事情，走你~

```
class Solution {
public:
    string reverseWords(string s) {
        string strRes;
		vector<string> VectStrRes;
		char cFlag = ' ';
		GetSeparateInfo(s, cFlag, VectStrRes);

		// 这里用了迭代器的rbegin rend,真香，好用，从最后一个元素遍历到第一个元素，和正序遍历完全没有区别，STL真香 
		for (auto iter = VectStrRes.rbegin();
			iter != VectStrRes.rend(); iter++)
		{
        	// rend 是begin的前一个元素，这就判断如果当前iter已经是第一个元素，则直接添加到结果字符串上，不用加空格分隔符
			if (iter+1 == VectStrRes.rend())
			{
				strRes.append(*iter);
			}else
			{
				strRes.append(*iter +" ");
			}
		}
		return strRes;
	}

	/************************************************************************/
	/* 在一串字符中根据分隔符的位置提取相应内容 保存在vector<string>中
	/************************************************************************/
	void GetSeparateInfo(const string SourceStr, char cFlag, vector<string> &VectStrRes) {

		string key;
		string::size_type nBeginPos = 0;
		string::size_type nEndPos = 0;
		int nNum = count(SourceStr.begin(), SourceStr.end(), cFlag);
		for (int i = 0; i <= nNum; i++) {
			key.clear();
			// 每次从分隔符的下个位置直到SourceStr的末尾 拷贝成子串，
			string SourceStrCopy(SourceStr, nBeginPos);
			nEndPos = SourceStrCopy.find(cFlag);
			if (string::npos != nEndPos) {
				// 从SourceStr 的下标nBeginPos开始，直到下标nEndPos，赋值给key
				key.assign(SourceStr, nBeginPos, nEndPos);
				nBeginPos += nEndPos + 1;
				std::cout << key.c_str() << std::endl;
			}
			else if (i == nNum) {
				// 已经找完的所有分隔符，剩余最后一个分隔符和行尾的子串
				key = SourceStrCopy;
				std::cout << key.c_str() << std::endl;
			}
			else {
				std::cout << "没有分隔符" << endl;
			}
            // 处理两个单词间多个空格问题，如果得到的key长度为空，则放弃，反之就是只保存长度不为0的子串
			if(0 != key.length())
				VectStrRes.push_back(key);
		}
	}
};
```

只是这个结果不完美,时长比较多，占用了额外的空间，多用了n个分隔符数目的string SourceStrCopy，还用了vector<string>，最后返回strRes，原字符串s为n空间的话，我这个空间复杂度是0（n<sup>2</sup>）,时间复杂度，用了两个循环，都是N,总计为o(n) 这个o（n）并不准确，因为涉及到STL的find,assign操作，这都是算法，不能单纯的当成0（1）操作，所以用时还是比较多的

```
25 / 25 个通过测试用例
状态：通过
执行用时：32 ms
```

### 解决思路二：
看看大佬的解释（[点此戳大佬博客](https://www.cnblogs.com/grandyang/p/4606676.html)）， 可以翻转两次，先翻转一次，如 "the sky is blue" ->"euld si yks eht" ，接着翻转每个单词，可以根据分隔符确认要反转的下标范围，这时候如果结尾多个空格，像"hello world! " 翻转后为" !dlrow olleh" 那么走到while那里，storeIndex=0,j=1;  感觉这里想着就比较费劲了，边界条件还是要理清楚，跟着代码调试一遍才明白，接着自己手敲一遍，仔细想想边界条件，想清楚了
```
class Solution {
public:
    string reverseWords(string s) {
        int storeIndex = 0, n = s.size();
        string strRes = s;
        reverse(strRes.begin(), strRes.end());
        for (int i = 0; i < n; ++i) {
            if (strRes[i] != ' ') {
                if (storeIndex != 0) strRes[storeIndex++] = ' ';
                int j = i;
                while (j < n && strRes[j] != ' ') strRes[storeIndex++] = strRes[j++];
                reverse(strRes.begin() + storeIndex - (j - i), strRes.begin() + storeIndex);
                i = j;
            }
        }
        strRes.resize(storeIndex);
        return strRes;
	}
};
```
执行结果用时仅8ms,amazing,而且没有用到额外的存储空间， 我在leetcode中文版，返回值是string,大佬的返回值是void,直接在原字符串上上修改，空间复杂度0（1）,时间复杂度0（n）

### 解决思路三，四: 
利用istringstream, 因为分隔符刚好是空格，相当于字符串输入的时候，恰好可以利用空格符区作为结束一次输入，将string初始化为istringstream流，再从流中读取单词，利用这个特性，刚好过滤空格，后面再重新组字符串即可；这两个方法执行效率不高，都是24ms,也有限制，如果分隔符不是空格就没发复用了，个人觉得适用于这个题目，可以看看即可，<font color=red>利用流输入特性过滤空格还是很讨巧的</font>，厉害~

```
	string reverseWords(string s) {
		string strRes = s;
		istringstream is(strRes);
		string tmp;
		is >> strRes;
		while (is >> tmp)
		{
			strRes = tmp + " " + strRes;
		}
		if (!strRes.empty() && strRes[0] == ' ') strRes = "";
		return strRes;
	}
```

```
	string reverseWords(string s) {
		string strRes = s;
		istringstream is(strRes);
		strRes = "";
		string t = "";
		while (getline(is, t/*, ' '*/)) {
			if (t.empty()) continue;
			strRes = (strRes.empty() ? t : (t + " " + strRes));
		}
		return strRes;
	}
```


