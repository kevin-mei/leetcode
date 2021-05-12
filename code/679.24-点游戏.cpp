/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 *
 * https://leetcode-cn.com/problems/24-game/description/
 *
 * algorithms
 * Hard (54.18%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 43K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 * 
 * 示例 1:
 * 
 * 输入: [4, 1, 8, 7]
 * 输出: True
 * 解释: (8-4) * (7-1) = 24
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 1, 2]
 * 输出: False
 * 
 * 
 * 注意:
 * 
 * 
 * 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
 * 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1
 * 是不允许的。
 * 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
 * 
 * 
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        double eqs = 0.001;// 精度
        vector<double> nums(cards.begin(), cards.end());
        bool res = false;
        helper(nums, eqs, res);
        return res;
    }

    void helper(vector<double> &nums, double eqs, bool &res)
    {
        if(res) return;
        if(1 == nums.size())
        {
            if(abs(nums.front()-24)<eqs) 
                res = true;
            return;
        }

        for(int i = 1; i < nums.size();i++)
        {
            for(int j = 0; j < i; j++)
            {
                double opter1 = nums[j], opter2 = nums[i];
                // + - * / +*满足交换律，只需要加一次即可
                vector<double> t={opter1+opter2, opter1-opter2,opter2-opter1,opter1*opter2};
                //除法需要判断除数不为0的情况
                if(opter1 > eqs) t.push_back(opter2/opter1);
                if(opter2 > eqs) t.push_back(opter1/opter2);
                // 取出两个数，将+-*/之后的数放进nums，剩3个数，再进行递归运算
                // 这里删除的时候，先删下标大的，再删小的
                nums.erase(nums.begin()+i);
                nums.erase(nums.begin()+j);
                for(double result : t)
                {
                    nums.push_back(result);
                    helper(nums, eqs, res);
                    nums.pop_back();

                }
                // 恢复nums数组的时候，先加下标小的，再加大的
                nums.insert(nums.begin()+j, opter1);
                nums.insert(nums.begin()+i, opter2);
            }
        }
    }
};


class Solution {
public:
    vector<string> judgePoint24_All(vector<int>& nums) {
    	unordered_set<string> res;
		double eps = 0.001;
		vector<char> ops{'+', '-', '*', '/'};
		vector<double> arr(nums.begin(), nums.end());
		vector<string> vec;
		for (int num : nums) vec.push_back(to_string(num));
		helper(arr, ops, eps, vec, res);
		return vector<string>(res.begin(), res.end());
    }
	void helper(vector<double>& nums, vector<char>& ops, double eps, vector<string>& vec, unordered_set<string>& res) {
		if (nums.size() == 1) {
			if (abs(nums[0] - 24) < eps) res.insert(vec[0]);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i == j) continue;
				vector<double> t;
				vector<string> v;
				for (int k = 0; k < nums.size(); ++k) {
					if (k != i && k != j) {
						t.push_back(nums[k]);
						v.push_back(vec[k]);
					}
				}
				for (char op : ops) {
					if ((op == '+' || op == '*') && i > j) continue;
					if (op == '/' && nums[j] < eps) continue;
					switch(op) {
						case '+': 
							t.push_back(nums[i] + nums[j]);
							v.push_back("(" + vec[i] + "+" + vec[j] + ")");
							break;
						case '-': 
							t.push_back(nums[i] - nums[j]); 
							v.push_back("(" + vec[i] + "-" + vec[j] + ")");
							break;
						case '*': 
							t.push_back(nums[i] * nums[j]); 
							v.push_back("(" + vec[i] + "*" + vec[j] + ")");
							break;
						case '/': 
							t.push_back(nums[i] / nums[j]); 
							v.push_back("(" + vec[i] + "/" + vec[j] + ")");
							break;
					}
					helper(t, ops, eps, v, res);
					t.pop_back();
					v.pop_back();
				}
			}
		}
	}
};


// int main()
// {
//     Solution sol;
//     vector<int> nums = {4,1,8,7};
//     bool res = sol.judgePoint24(nums);
//     cout << res << endl;
// }
// @lc code=end

