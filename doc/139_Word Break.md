#### 题目
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

使用记忆数组memo的递归写法和使用dp数组的迭代写法，是解动态规划题目的两大神器；

算法描述：
1. 将vector 单词字典 放入 hash表中，方便后续常数级查找
2. 定义记忆数组，memo,长度为字符串的大小， 第i位用来标记，[i,n] (n为字符串的长度)之间的子字符串(必须以i为子串的开始位置，长度变化直到N)能不能拆分成功（是否可以在单词字典中找到），初始化为-1，如果可以拆分，则赋值为1，反之为0；
3. 递归函数
	结束条件：
    1. 当要检查的子串起始位置start已经超过了原始字符串的大小，则说明所有的子串都匹配成功，返回成功
	2. 当要检查的子串起始位置start处的memo记忆数组已经不为-1，则说明 该位置 作为子串开始位置，在字典中是否存在，已经有结果了，直接读取记忆数组的结果即可
    for循环：
    循环条件：起始位置start固定，由递归函数传入， i从start后第一个字符开始，直到字符串结尾
    循环内的内容：
    i和start之间的内容组成子串，然后看字典里有没有，如果有，则以i的位置为子串的起始位置，递归调用，看看以i为起始位置的，子串能不能切分；如果没有，进入下一次循环，直到i到原始字符串的长度



    
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet, 0, memo);
    }
    bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start + 1; i <= s.size(); ++i) {
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};
```
Dynamic Programming
博主曾经说玩子数组或者子字符串且求极值的题，基本就是 DP 没差了



十万个为什么上线，这道题让我看了一整天，才看出点眉目，
> 1. <font color=red>确认下这里的hash 表 为啥用的unordered_set而不是map,set之类的？ </font> 
> 答：map是一对键值，key-value类型，这里用的话，就得key是原始字符串的size，value是结果; 用set 的话，默认它的下标刚好和字符串的size是一一对应的，也讨巧; 
贴个执行结果：
>|hash表类型|执行时间|查找时间复杂度|
|-|-|-|
|unordered_set|36ms|O(1)|
|set|52ms|O(logn)|
> 2. <font color=red>关于算法的时间复杂度很多都用包含O(logN)这样的描述，但是却没有明确说logN的底数究竟是多少?</font> 
> **解答：
算法中log级别的**时间复杂度都是由于使用了分治思想,这个底数直接由分治的复杂度决定。
如果采用二分法,那么就会以2为底数,三分法就会以3为底数,其他亦然。
不过无论底数是什么,log级别的渐进意义是一样的。
也就是说该算法的时间复杂度的增长与处理数据多少的增长的关系是一样的。
> **我们先考虑**O(logx(n))和O(logy(n))，x!=y，我们是在考虑n趋于无穷的情况。
求当n趋于无穷大时logx(n)/logy(n)的极限可以发现，极限等于lny/lnx，也就是一个常数，
也就是说，在n趋于无穷大的时候，这两个东西仅差一个常数。
所以从研究算法的角度log的底数不重要。
> **最后，结合上面**，我也说一下关于大O的定义（算法导论28页的定义），
注意把这个定义和高等数学中的极限部分做比较，
显然可以发现，这里的定义正是体现了一个极限的思想，
假设我们将n0取一个非常大的数字，
显然，当n大于n0的时候，我们可以发现任意底数的一个对数函数其实都相差一个常数倍而已。
所以书上说写的O（logn）已经可以表达所有底数的对数了，就像O(n^2)一样。
没有非常严格的证明，不过我觉得这样说比较好理解，如果有兴趣证明，完全可以参照高数上对极限趋于无穷的证明。
> 问题2转自 [https://blog.csdn.net/jdbc/article/details/42173751](https://blog.csdn.net/jdbc/article/details/42173751)