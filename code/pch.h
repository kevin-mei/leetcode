#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <regex>
#include <map>
#include <numeric>
#include <functional>

using namespace std;


/*
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 