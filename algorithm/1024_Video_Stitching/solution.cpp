#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		int ans = 0;
		int spot = 0;

		sort(clips.begin(), clips.end());
		if (clips[clips.size() - 1][1] < T)return -1;
		while (spot < T) {
			int max_end = 0;
			for (int i = 0; i < clips.size(); i++) {

				if (clips[i][0] <= spot) {
					if (clips[i][1] >= spot) {
						max_end = max(max_end, clips[i][1]);

					}

				}
				else {
					ans++;
					if (spot == max_end)return -1;
					spot = max_end;

					break;
				}
				if (i == clips.size() - 1) {
					ans++;
					spot = max_end;
				}

			}


		}
		return ans;
	}
};