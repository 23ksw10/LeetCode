#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n=s.size();
        string ans="";
        int r=0;
        int l=0;
        for(int i=0;i<n;i++){
            r+=(s[i]==letter);
        }
        
        for(int i=0;i<n;i++){
            while(ans.size()&&ans.back()>s[i]){
                if(ans.back()==letter&&l+r==repetition)break;
                if(ans.size()+(n-i)<=k)break;
                l-=(ans.back()==letter);
                
                ans.pop_back();
            }
            if(ans.size()<k){
                if(s[i]==letter){
                    ans+=s[i];
                    l++;
                    r--;
                }
                else{
                    int q=k-ans.size();
                    int w=repetition-l;
                    if(q>w){
                        ans+=s[i];
                    }
                }
            }
            else{
                if(s[i]==letter){
                                        
                    r--;
                }
            }
            
        }
        return ans;
    }
};