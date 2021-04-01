/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    int uniquePaths_1(int m, int n) {
        // 还是动态规划  规定第一行，第一列
        // 定义 dp[i][j] 表示从[0,0]->[i-1,j-1]的不同路径数
        // 因为机器人每次只能向下或者向右移动一步，所以dp[i][j] 只能由它的上方的方格和左边的方格移动一步得到；
        // 所以dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        // 明确base case, dp[0][0],dp[0][1]....dp[0][n-1] =1; dp[1][0],dp[2][0]....dp[m-1][0] =1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) // 初始化第一行 全为1
            dp[0][j] = 1;
        for (int i = 0; i < m; i++) // 初始化第一列 全为1
            dp[i][0] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // 还是动态规划  规定第一行，第一列
        // 定义 dp[i][j] 表示从[0,0]->[i-1,j-1]的不同路径数
        // 因为机器人每次只能向下或者向右移动一步，所以dp[i][j] 只能由它的上方的方格和左边的方格移动一步得到；
        // 所以dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        // 明确base case, dp[0][0],dp[0][1]....dp[0][n-1] =1; dp[1][0],dp[2][0]....dp[m-1][0] =1;
        // 现在我想压缩dp数组，只用一维数组表示
        // 也就是我的dp[j] = dp[j]+dp[j-1];
        // 一维数组，初始化均为1，
        // 还是两层循环

        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++) // 初始化第一行 全为1
            dp[j] = 1;
        
        // dp[1][1] = dp[0][1]+dp[1][0] = 2;
        // 对应：dp[1] = dp[1]+dp[0] = 2;
        // dp[1][2] = dp[0][2]+dp[1][1] = 3;
        // 对应：dp[2] = dp[2]+dp[1] = 3

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

