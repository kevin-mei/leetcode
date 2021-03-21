#include "pch.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 对比两个结点中公共的即可
        int res = -1;
        int count = edges.size();
        if(0 == count)
            return res;
        if(1 == count)
            return edges[0][0];
        
        vector<int> nodes(count+2,0);
        for(auto edge : edges)
        {
            for(int cutnode : edge)
            {
                nodes[cutnode]++;
                if(nodes[cutnode]>1)
                    res=cutnode;
            }
        }
        if(-1 != res && count != nodes[res])
            res = -1;
        return res;
    }
};

int main()
{
    
//{{1,2},{5,1},{1,3},{1,4}}
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    Solution sol;
    int res = sol.findCenter(edges);
    cout << res << endl; 
}   