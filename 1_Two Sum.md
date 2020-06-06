#### 题目

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (0 == nums.size())
		{
			return nums;
		}
		vector<int> *vectRes = new vector<int>();

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i == j)
				{
					continue;
				}
				else if (target == nums[i] + nums[j])
				{
					vectRes->push_back(i);
					vectRes->push_back(j);
					return *vectRes;
				}

			}
		}

		return *vectRes;
    }
};
```