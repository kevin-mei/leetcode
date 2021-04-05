#include "pch.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // 同一用户在同一分钟内执行多个操作
        // 要统计的是：用户的分钟活跃数
        // 每个用户有自己的map，每个map 分钟数，分钟的操作数
        // 如果对应的分钟key已经有值了，那就不再计数
        // 最后返回<用户，map.size()>
        unordered_map<int, unordered_map<int,int>> user_map;
        for(vector<int> curlog : logs)
        {
            int id= curlog[0];
            int time= curlog[1];
            if (std::end(user_map) == user_map.find(id))
            {
                unordered_map<int,int> time_count;
                time_count[time]++;
                user_map.insert({id, time_count});
            }
            else
            {
                 if (std::end(user_map[id]) == user_map[id].find(time))
                 {
                     user_map[id].insert({time,1});
                 }
            }
        }
        vector<int> res(k,0);
        for (auto curuse : user_map)
        {
            if (curuse.second.size() > 0 && curuse.second.size() <= k)
                res[curuse.second.size() - 1]++;
        }

        return res;
    }
};

int main()
{
    // {{0,5},{1,2},{0,2},{0,5},{1,3}}
    vector<vector<int>> logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    Solution sol;
    vector<int> res = sol.findingUsersActiveMinutes(logs,5);
    cout << res.size();
    return 0 ;

}