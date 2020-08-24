#### 题目
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4


解法一（虽然不合题目真正要求，但还是可以解）：
第一个感觉，可以使用哈希表，每次查找是否有相同的用o(1)的时间复杂度就可以，共查询n次， 加上第一个建立哈希表， 建立哈希表可以认为是1的时间复杂度  也就是o(n)的时间复杂度，空间复杂度o(n)

这个方法可以解single num i ii iii(修改下返回参数即可)  还是有通用性的~

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int nRes = -1;
        unordered_multiset<int> numdict(nums.begin(), nums.end());
        for(auto iter=nums.begin(); iter != nums.end(); iter++)
        {
        	if(1 == numdict.count(*iter))
            {
            	nRes=*iter;
                break;
            }
        }
        return nRes;
    }
};
```

注意：这里使用unordered_multiset 含有可能非唯一对象的集合;不能用unordered_set，它是非唯一对象的集合，2,2,1 放进set，就变成了2,1了，这里需要注意


解法二：
使用异或的特性，相同为0，不同为1； 0异或任何数都是任何数；异或满足交换律
我们可以使用按位异或，假设给了 a,b,b,a,c五个数； a^b^b^a^c = (a^a)^(b^b)^c = 0^0^c = c; 异或到最后的结果，也就是要求的数；

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int nRes = 0;
		for(auto iter=nums.begin(); iter != nums.end(); iter++)
        {
        	nRes^=*iter;
        }
        return nRes;
    }
};
```
