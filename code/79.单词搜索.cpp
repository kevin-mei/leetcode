/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    680
 * Dislikes: 0
 * Total Accepted:    118.9K
 * Total Submissions: 272.1K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
#include "pch.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        // 深度优先搜索遍历  使用stack
        int m = board.size();
        int n = board[0].size();
        stack<char> stack_data;
        // 初始化一个m*n bool 二维数组，表示单元格是否访问过
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // 栈里面存什么？
        // 存访问过的数据，从第一个节点开始，从从左至右，上到下开始访问，直到访问到word的字符，存如栈中
        // 然后栈不为空，且word没找完的情况下，从栈顶元素的上下左右找，是否存在word下一个字符
        // 是，则入栈，进入下一个循环，visited[i][j] = true;否，则弹栈,对应的visited[i][j]=false;
        



        return res;
    }


};
// @lc code=end

