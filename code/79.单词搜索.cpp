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
        // 深度优先搜索遍历 这里考虑用 递归的方式
        // 新建一个函数bool check(i,j,k) 标识从board[i][j]出发，能否访问到word[k]直到word结尾
        // 外层调用它，需要从从第一个单元格开始，从从左至右，上到下开始访问，调用check(i,j,0) 
        // 如果有返回true的，则说明存在，直接退出循环
        int m = board.size();
        int n = board[0].size();
        // 初始化一个m*n bool 二维数组，表示单元格是否访问过
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = check(board, visited, word, i, j, 0);
                if (res)
                {
                    return res;
                }
            }
        }

        return res;
    }


    bool check(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int i, int j, int k)
    {
        bool res = false;
        // 先比较board[i][j]和word[k],不相等则返回false,  如果visited[i][j]已经访问过了，也返回false
        // 相等时先判断是否k==word.size()-1，是最后一个，说明完整找到word，返回true, 不是最后一个，则先visited[i][j]=true
        // 然后四个方向各调用下check(new_i,new_j,k+1);有true时说明找到，直接返回
        if(board[i][j] != word[k] || visited[i][j])
            return false;
        else if(k==word.size()-1) // 这里就暗含board[i][j] == word[k]
            return true;
        // 下面是board[i][j] == word[k] 且k不是word最后一个元素下标的处理
        visited[i][j] = true;
        vector<pair<int,int>> directors = {{0,1},{0,-1},{-1,0},{1,0}}; // 定义4个方向 上下左右
        for(pair<int,int> director : directors)
        {
            int new_i = i+ director.first, new_j = j+director.second;
            // 判断新坐标的合法性 且visited[new_i][new_i]没有被访问过
            if(new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size())
            {
                res = check(board, visited, word, new_i, new_j, k+1);
                if(res)
                    return res;
            }
        }
        // 如果四个方向都走完了，没有找到路径，会自然退出循环,说明从[i][j]开始没法找到，这时候visited[i][j] = false；做别人的临结点访问
        visited[i][j] = false;
        return res;
    }


};
// @lc code=end

