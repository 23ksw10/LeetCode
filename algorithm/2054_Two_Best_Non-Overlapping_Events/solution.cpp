#include <iostream>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        sort(events.begin(), events.end());
        map<long long, int>m;
        m[0] = 0;
        int n = events.size();
        int previous_max = 0;
        for (int i = n - 1; i >= 0; i--) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];
            previous_max = max(previous_max, value);
            auto it = m.upper_bound(end);
            if (it != m.end()) {
                ans = max(ans, value + it->second);
            }
            else ans = max(ans, value);
            m[start] = previous_max;
        }
        return ans;
    }
};