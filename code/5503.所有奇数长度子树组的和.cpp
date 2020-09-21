// 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

// 子数组 定义为原数组中的一个连续子序列。

// 请你返回 arr 中 所有奇数长度子数组的和 。

 

// 示例 1：

// 输入：arr = [1,4,2,5,3]
// 输出：58
// 解释：所有奇数长度子数组和它们的和为：
// [1] = 1
// [4] = 4
// [2] = 2
// [5] = 5
// [3] = 3
// [1,4,2] = 7
// [4,2,5] = 11
// [2,5,3] = 10
// [1,4,2,5,3] = 15
// 我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
// 示例 2：

// 输入：arr = [1,2]
// 输出：3
// 解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
// 示例 3：

// 输入：arr = [10,11,12]
// 输出：66
 

// 提示：

// 1 <= arr.length <= 100
// 1 <= arr[i] <= 1000


//5503
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        // 偶数的话，最长的奇数数组长度为arr.size()-1
        // 奇数的话，最长长度是它本身
        int maxlenth = arr.size();
        if (0 == arr.size() % 2)
        {
            maxlenth = arr.size() - 1;
        }

        int sum = 0;

        for(int  m = 1; m <= maxlenth; m=m+2)
        {
            // 从n = arr.size() 中取出m个元素，组合数为：n!/(m!*(n-m)!)
            // 每种怎么求 有子树组的限制，也就是数必须连续
            vector<int> newarr; 
            
            for(int l = 0; l + m <= arr.size(); l++)
            {
                sum = std::accumulate(arr.begin()+l,arr.begin()+l+m, sum);
            }
        }

        return sum;
        
    }

    map<int,int> mem;
    int fac(int n)
    {
        if(n < mem.size())
        {
            return mem[n];
        }
        if (1 == n || 0 == n)
        {
            mem[0]=1;
            mem[1]=1;
            return 1;
        }
        else
        {
            int res =  n * fac(n - 1);
            mem[n]=res;
            return res;
        }
    }
};

int main()
{
    vector<int> vect = {10,11,12}; 

    Solution sol;
    int res = sol.sumOddLengthSubarrays(vect);
    std::cout << res << std::endl;
    return 0;
}


