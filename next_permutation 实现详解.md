bool next_permutation(nums.begin(),nums.end()),返回一个有序排列的下一个字典排序，如果返回的nums是有序的，则此函数返回false；

说明调用该函数之前nums需要进行排序，作为初始值，之后一直循环调用ner_permutation()即可获取nums的所有字典排序; 也就是全排列(还可以过滤掉重复的排列)， 可解 leetcode 46,47