#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long,int>m;
        long long ans=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(m.count(nums[i]-i))ans+=m[nums[i]-i];
            m[nums[i]-i]++;
        }
        long long total=(long long)(n)*(n-1)/2;
        return total-ans;
    }
};
