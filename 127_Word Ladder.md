#### 题目
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


单词一个一个字符改变

第一层循环：遍历单词第一个字符到最后一个字符，
第二层循环：修改当前字符的，从a->z
查找字典里有没有修改后的字母，有的话跳出，进行下一轮查找

BFS 广度优先遍历

字典里找单词，怎么就成广度优先搜索了？

这种情况使用BFS呢？  理解不了啊????

再想想 BFS的经典套路，就是二叉树的层序遍历，遍历到第一个叶子结点，那么它的深度 也就是树的到叶子结点的最短深度

现在要求的是也最短路径，遍历到第一个结果--》成功到达目标字符串，就是最短路径？ 从例子看起：

beginWord = "aot",
endWord = "cog",
wordList = ["hot" "got" "god" "cod" "cog"]

amazing? 想一想，再想一想，emmmmm, hit 到 cog, 先将hit ，"" （空字符串）压入队列
"" （空字符串）是每层的分隔字符串


|出队列 |入队列  | 层数|
|--|--|--|
|hit | hot got ""| 1层|  
|hot |无入队||
|got |god cod ""|  二层|
|god | cod上一个已经被删了，所以这一波，无入队 ||
|cod | cog，最终结果，bingo~ | 三层 |


这一波下来，不就是 广度优先搜索遍历么，层序遍历有木有， 其实我觉得自己想还是挺难想到的，代码里while中的两层for循环挺重要，每一波循环相当于把每一个位置上，修改一个字符且存在于字典的 单词都给放入的队列里。

```
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (0 == start.size() || 0 == end.size()) return 0;
        if(dict.find(end) == dict.end()) return 0;
        queue<string> wordQ;
        wordQ.push(start);  // 先进先出   每一个单词 用""空字符串分隔
        wordQ.push("");
        int Path = 1;

        // 这样一波，怎么就保证是最短路径了？  
        //
        while (!wordQ.empty()) {
          string str = wordQ.front();
          wordQ.pop();

          if (str != "") {
            int len = str.size();
            // 这每一波循环，相当于把每一个位置上，修改一个字符且存在于字典的 单词都给放入的队列里
            for (int i = 0; i < len; i++) {
              char tmp = str[i];  //保存要修改的字符

              for (char c = 'a'; c <= 'z'; c++) {
                if (c == tmp)
                  continue;
                str[i] = c;
                if (str == end)
                  return Path + 1;
                if (dict.find(str) != dict.end()) {
                  wordQ.push(str);
                  dict.erase(str); // 一个单词只能用一次
                }
              }
              str[i] = tmp; //恢复要修改的字符
            }
          } else if (!wordQ.empty()) {
            Path++;
            wordQ.push("");
          }
        }
        return 0;
    }
};
```









