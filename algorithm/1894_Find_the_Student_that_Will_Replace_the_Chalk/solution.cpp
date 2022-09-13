#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long>v(n);
        v[0]=(long long)chalk[0];
        for(int i=1;i<n;i++){
            v[i]=chalk[i]+v[i-1];
        }
        long long m=k%v[n-1];
        auto it = upper_bound(v.begin(),v.end(),m)-v.begin();
        return it;
    }
};