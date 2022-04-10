#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        vector<long long>one(2, 0);
        vector<long long>two(2, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                one[0]++;
                if (one[1])two[0] += one[1];
                ans += two[1];
            }
            else {
                one[1]++;
                if (one[0])two[1] += one[0];
                ans += two[0];
            }
        }
        return ans;
    }
};

