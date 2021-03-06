/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 *
 * https://leetcode-cn.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (71.47%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    65.8K
 * Total Submissions: 92.1K
 * Testcase Example:  '2'
 *
 * 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
 * 
 * 最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
 * 
 * 
 * 选出任一 x，满足 0 < x < N 且 N % x == 0 。
 * 用 N - x 替换黑板上的数字 N 。
 * 
 * 
 * 如果玩家无法执行这些操作，就会输掉游戏。
 * 
 * 只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 False。假设两个玩家都以最佳状态参与游戏。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：2
 * 输出：true
 * 解释：爱丽丝选择 1，鲍勃无法进行操作。
 * 
 * 
 * 示例 2：
 * 
 * 输入：3
 * 输出：false
 * 解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        // f[i] 给定的数为i时，爱丽丝是否赢得比赛/ 一定有最优解
        // 任何数都可以被1整除，只要爱丽丝收到的数>1,她就可以继续往下走
        vector<bool> f(N+1, false);
        if(1 == N)
            return false;
        f[1] = false;
        // 1 false 
        // 2 可选1 选1留1 给ball, return !f(1) = true
        // 3 false 选1留2 ball
        // 4 可选1,2 选1留3给ball,return !f(3) = true
        // 5 可选1   选1留4给ball return !f(4) = false
        // 6 可选1，2，3，留5，4，3，留5，3当中任意一个，即可获胜，所以f(6) true
        for(int i=2; i <= N; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(0 == i%j && !f[i-j])
                    f[i]  = true;
            }
        }
        return f[N];
    }
};
// @lc code=end

