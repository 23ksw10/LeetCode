#include <iostream>
#include <string>
#include <vector>




using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        string ans = "";
        int n = s.size();
        vector<int>lps(n, 0);
        int i = 0;
        int j = 1;
        while (j < n) {
            if (s[i] == s[j]) {
                i++;
                lps[j] = i;
                j++;
            }
            else if (i > 0) {
                i = lps[i - 1];
            }
            else {
                lps[j] = 0;
                j++;
            }
        }
       
        return s.substr(0, lps[n - 1]);
    }
};