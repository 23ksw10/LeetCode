#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int n=fruits.size();
        set<int>check;
        int ind=0;
        int last=-1;
        int first=0;
        for(int i=0;i<n;i++){
            check.insert(fruits[i]);
            if(check.size()>2){
                check.clear();
                check.insert(last);
                check.insert(fruits[i]);
                ans=max(ans,i-ind+1);
                first=ind;
                last=fruits[i];
                ind=i;
            }
            else{
                ans=max(ans,i-first+1);
                if(last==fruits[i])continue;
                last=fruits[i];
                ind=i;
            }
        }
        return ans;
    }
};