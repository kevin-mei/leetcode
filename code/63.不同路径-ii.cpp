/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include "pch.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 还是动态规划  规定第一行，第一列
        // 定义 dp[i][j] 表示从[0,0]->[i-1,j-1]的不同路径数
        // 因为机器人每次只能向下或者向右移动一步，所以dp[i][j] 只能由它的上方的方格和左边的方格移动一步得到；
        // 所以dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        // 现在加上了障碍，那么有障碍的地方就不能走了
        // dp[i][j] = obstacleGrid[i][j] !=1?0:(dp[i-1][j] + dp[i][j-1]);
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 明确base case
        for (int j = 0; j < n; j++) // 初始化第一行  如果第一行某一格障碍，那障碍之后的方格都为0
        {
            dp[0][j] = mixedObstacle(obstacleGrid[0][j], 1);
            if (1 == obstacleGrid[0][j])
                break;
        }

        for (int i = 0; i < m; i++) // 初始化第一列 如果第一列某一格障碍，那障碍之后的方格都为0
        {
            dp[i][0] = mixedObstacle(obstacleGrid[i][0], 1);
            if (1 == obstacleGrid[i][0])
                break;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = mixedObstacle(obstacleGrid[i][j], dp[i-1][j] + dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    int mixedObstacle(int obstacleVaule, int value)
    {
        return obstacleVaule == 1 ? 0 : value;
    }
};
// @lc code=end

