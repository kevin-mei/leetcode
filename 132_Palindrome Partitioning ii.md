#### 题目

Given a string s, partition s such that every substring of the partition is a palindrome.



Return the minimum cuts needed for a palindrome partitioning of s.



Example:



Input: "aab"

Output: 1

Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


求回文字符串的最小分割数；
要用动态规划去做， 那就要想到状态转移方程；

状态转移数组的定义也是关键，这里使用一个一维数组dp[i] 定义 [0,i]位置的最小分隔数； 字符串大小为n,我们最终要返回的是dp[n-1];

d[i] = 1+d[i-1]  吗？  
d[i] = 1+ 1 + d[i-2]  
...
d[i] = i+d[0] ？？？  显然，不是的，这是分隔次数最多的情况，每个字符都分隔，单个字符当然是回文串；

正确的状态方程：
假设j 属于 [0,i]， d[i]被分为[0,j] ,[j,i] 两部分， 如果[j,i]之间的数组是回文串，那么 d[i] = d[j]+1;  注意，这里有一个[j,i]回文串判断的过程， 这就跟上面的推断不一样；

如果我们从0->n开始遍历， 对某一点i来说，d[j]总是已知的; 因为先求的是d[j],j从0位置开始

接下来问题来了，如何判断[j,i]是否为回文串？

再用一个dp数组，二维的数组 p[n][n], 其中p[i][j] ，其中0<i<j<n, 表示 从 [i,j]之间的子串是不是回文串；

它的状态方程为：
如果s[i] == s[j] ，那么 s[i,j] = s[i+1, j-1], 然后一次可以递推；

s[i,j] = (s[i] == s[j]) && s[i+1, j-1]; 

第一层循环 i 属于 [0,n]

第二次循环，j 属于 0到i，第一次判断s[j]== s[i], 且 i-j<2; s[j][i]=true;

这样的循环，能让p[j][i] 从 p[0][0] p[0][1]  p[1][1] p[0][2]  p[1][1] p[1][2] p[2][2] 一次求出来， 其实p[i][i],只有一个字符，必然是回文串，这个也可以直接在初始化为true

代码如下：
```
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n));
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
                    p[j][i] = true;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
```


也是看了大神的解释 看了两个小时，才看明白，整理成上面的个人理解；

附上大神的链接：https://www.cnblogs.com/grandyang/p/4271456.html

