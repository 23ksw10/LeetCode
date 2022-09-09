#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int mi=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<mi)return false;
            mi=max(mi,nums[i-1]);
        }
        return true;
    }
};
