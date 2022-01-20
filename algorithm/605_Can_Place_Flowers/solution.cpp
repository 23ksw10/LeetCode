#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        int empty=0;
        int flower=0;
        for(int i=0;i<m;i++){
            if(i==m-1&&!flowerbed[i])n--;
            else if(i==m-1&&flowerbed[i])continue;
            else if(flowerbed[i]==0&&flowerbed[i+1]==0){
                n--;
                flowerbed[i+1]=2;
            }
            else if(flowerbed[i]==1)flowerbed[i+1]=2;
        }
        return n<=0 ? true:false;
    }

};
