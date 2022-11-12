#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




 class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            int l=0;
            int r=i-1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]<target){
                    ans+=r-l;
                    l++;
                }
                else r--;
            }
        }
        return ans;
    }
};