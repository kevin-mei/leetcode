/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
//#include "pch.h"

class Solution {
    typedef int T;
    typedef int Rank;
public:
    vector<int> sortArray(vector<int>& nums) {
        _elem = &nums[0];
        //mergeSort(0, nums.size());
        //bubbleSort(0, nums.size()); // 冒泡排序 超出时间限制
        //shellSort(0, nums.size());  // 希尔排序
        //selectionSort(0, nums.size());  // 选择排序 超出时间限制
        quickSort(0, nums.size());
        return nums;
    }

    // 归并排序
    void mergeSort(Rank lo, Rank hi)
    {           //0 <= lo < hi <= size
        /*DSA*/ //printf ( "\tMERGEsort [%3d, %3d)\n", lo , hi );
        if (hi - lo < 2)
            return;             //单元素区间自然有序，否则...
        int mi = (lo + hi) / 2; //以中点为界
        mergeSort(lo, mi);
        mergeSort(mi, hi); //分别排序
        merge(lo, mi, hi); //归并
    }

    // 归并
    void merge(Rank lo, Rank mi, Rank hi)
    { //[lo, mi)和[mi, hi)各自有序，lo < mi < hi
        Rank i = 0;
        T *A = _elem + lo; //合并后的有序向量A[0, hi - lo) = _elem[lo, hi)，就地
        Rank j = 0, lb = mi - lo;
        T *B = new T[lb]; //前子向量B[0, lb) <-- _elem[lo, mi)
        for (Rank i = 0; i < lb; i++)
            B[i] = A[i]; //复制自A的前缀
        Rank k = 0, lc = hi - mi;
        T *C = _elem + mi;                             //后子向量C[0, lc) = _elem[mi, hi)，就地
        while ((j < lb) && (k < lc))                   //反复地比较B、C的首元素
            A[i++] = (B[j] <= C[k]) ? B[j++] : C[k++]; //将更小者归入A中
        while (j < lb)                                 //若C先耗尽，则
            A[i++] = B[j++];                           //将B残余的后缀归入A中——若B先耗尽呢？
        delete[] B;                                    //释放临时空间：mergeSort()过程中，如何避免此类反复的new/delete？
    }

    // 冒泡排序
    void bubbleSort(Rank lo, Rank hi)
    { //assert: 0 <= lo < hi <= size
        for (Rank last = --hi; lo < hi; hi = last)
            for (Rank i = last = lo; i < hi; i++)
                if (_elem[i] > _elem[i + 1])             //若逆序，则
                    swap(_elem[last = i], _elem[i + 1]); //经交换使局部有序
    }

    // 希尔排序
    void shellSort(Rank lo, Rank hi)
    { //0 <= lo < hi <= size <= 2^30
        /*DSA*/// printf("\tSHELLsort [%3d, %3d)\n", lo, hi);
        for (int d = 0x3FFFFFFF; 0 < d; d >>= 1) //PS Sequence: { 1, 3, 7, 15, ..., 1073741823 }
            for (int j = lo + d; j < hi; j++)
            { //for each j in [lo+d, hi)
                T x = _elem[j];
                int i = j - d;
                while (lo <= i && _elem[i] > x)
                {
                    _elem[i + d] = _elem[i];
                    i -= d;
                }
                _elem[i + d] = x; //insert [j] into its subsequence
            }
    }

    // 选择排序
    void selectionSort(Rank lo, Rank hi)
    { //0 <= lo < hi <= size
        /*DSA*///printf("\tSELECTIONsort [%3d, %3d)\n", lo, hi);
        while (lo < --hi)
            swap(_elem[max(lo, hi)], _elem[hi]); //将[hi]与[lo, hi]中的最大者交换
    }

    Rank max(Rank lo, Rank hi)
    { //在[lo, hi]内找出最大者
        Rank mx = hi;
        while (lo < hi--)              //逆向扫描
            if (_elem[hi] > _elem[mx]) //且严格比较
                mx = hi;               //故能在max有多个时保证后者优先，进而保证selectionSort稳定
        return mx;
    }

    // 快速排序
    void quickSort(Rank lo, Rank hi)
    {           //0 <= lo < hi <= size
        /*DSA*/ //printf ( "\tQUICKsort [%3d, %3d)\n", lo, hi );
        if (hi - lo < 2)
            return;                  //单元素区间自然有序，否则...
        Rank mi = partition(lo, hi); //在[lo, hi)内构造轴点
        quickSort(lo, mi);           //对前缀递归排序
        quickSort(mi + 1, hi);       //对后缀递归排序
    }

    //轴点构造算法：通过调整元素位置构造区间[lo, hi)的轴点，并返回其秩
    Rank partition(Rank lo, Rank hi)
    {                                                    //DUP版：可优化处理多个关键码雷同的退化情况
        swap(_elem[lo], _elem[lo + rand() % (hi - lo)]); //任选一个元素与首元素交换
        hi--;
        T pivot = _elem[lo]; //以首元素为候选轴点——经以上交换，等效于随机选取
        while (lo < hi)
        { //从向量的两端交替地向中间扫描
            while (lo < hi)
                if (pivot < _elem[hi]) //在大于pivot的前提下
                    hi--;              //向左拓展右端子向量
                else                   //直至遇到不大于pivot者
                {
                    _elem[lo++] = _elem[hi];
                    break;
                } //将其归入左端子向量
            while (lo < hi)
                if (_elem[lo] < pivot) //在小于pivot的前提下
                    lo++;              //向右拓展左端子向量
                else                   //直至遇到不小于pivot者
                {
                    _elem[hi--] = _elem[lo];
                    break;
                }          //将其归入右端子向量
        }                  //assert: lo == hi
        _elem[lo] = pivot; //将备份的轴点记录置于前、后子向量之间
        return lo;         //返回轴点的秩
    }
    
    int *_elem;
};
// @lc code=end

