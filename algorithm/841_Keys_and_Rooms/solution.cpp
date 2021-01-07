#include <iostream>
#include <vector>





using namespace std;



class Solution {
public:

	void dfs(int roomNumber, vector<vector<int>>& rooms, vector<int>&check) {
		check[roomNumber] = 1;
		for (int i = 0; i < rooms[roomNumber].size(); i++) {
			if (check[rooms[roomNumber][i]] == 0)dfs(rooms[roomNumber][i], rooms, check);
		}
	}
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		vector<int>check(n, 0);
		dfs(0, rooms, check);
		for (auto &c : check) {
			if (c == 0)return false;
		}
		return true;
	}
};