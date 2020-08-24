#### 题目

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

合并两个有序的数组nums1,nums2， 将nums2的内容合并到nums1中

解法一(二货解法,面试不推荐使用)：
拿到题目，第一眼的就是，nums2放在nums1里，然后利用STL的sort排序(默认是升序，nice)，bingo~

```
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		auto iter = nums1.begin();
		while (iter != nums1.begin() + m)
			iter++;
		int nCount = 0;
		for (auto i : nums2)
		{
			nCount++;
			if (nCount > n)
				break;
			*iter = i;
			iter++;
		}
		sort(nums1.begin(), nums1.end());
	}
};
```

解法二：
单独一个数组nums3保存nums1的前m个元素，从前往后一次比较nums2,nums3的元素，谁小就排谁，之后依次比较插入即可； 第一个循环后，有可能i 或者j还没达到n或者m, 如果有，对应将其放在排好序的数组后即可， 空间复杂度o(m)，时间复杂度o(m+n)


```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0, k = 0; //下标从0开始
		vector<int> nums3(nums1.begin(), nums1.begin()+m);
		while (i < m && j < n) {
			if (nums3[i] < nums2[j]) {
				nums1[k++] = nums3[i++];
			}
			else {
				nums1[k++] = nums2[j++];
			}
		}

		while (j < n ) {
			nums1[k++] = nums2[j++];
		}
		while (i < m) {
			nums1[k++] = nums3[i++];
		}
    }
};
```



解法三：
从后往前一次比较两个数组的元素，谁大就排谁，nums1的空间是足够大的，所以这个从m+n处开始排就好， 这样的好处是不牵扯到排好的数组覆盖到nums1原有数据，所以不用额外的变量保存；
第一个循环后，有可能i,或j不为0，i不为0，不用管，本身就在nums1里; j不为0，依次从后往前填充即可；空间复杂度为0；时间复杂度o(m+n)

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1; //下标从0开始

		while (i >= 0 && j >= 0) {
			if (nums1[i] < nums2[j]) {
				nums1[k--] = nums2[j--];
			} else {
				nums1[k--] = nums1[i--];
			}
		}

		while (j >= 0) {
			nums1[k--] = nums2[j--];
		}
	}
};
```