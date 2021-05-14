/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.58%)
 * Likes:    1307
 * Dislikes: 0
 * Total Accepted:    265.7K
 * Total Submissions: 469.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::unordered_map<char, string> hash_map = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
        vector<string> Combinations;
        if(0 == digits.length())
            return Combinations;
        int index = 0;
        string combination;
        backtrace(digits, hash_map, index, combination, Combinations);
        return Combinations;
    }

    void backtrace(const string &digits, std::unordered_map<char, string> &hash_map, int index, string &combination, vector<string> &Combinations)
    {
        if(index == digits.length())
        {
            Combinations.push_back(combination);
            return;
        }
            
        char cur_num = digits[index];
        string letter = hash_map[cur_num];
        for(char cur_ch : letter)
        {
            combination.push_back(cur_ch);
            backtrace(digits, hash_map, index+1, combination, Combinations);
            combination.pop_back();
        }
    }
};
// @lc code=end

