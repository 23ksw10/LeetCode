#include <iostream>
#include <vector>
#include <queue>





using namespace std;



class Trie {
	vector<Trie *>child;
	bool isEnd;
	string word;
public:
	Trie() {
		isEnd = false;
		child.resize(26, nullptr);
	}
	void insert(string s) {
		Trie *tmp = this;
		for (auto &w : s) {
			int index = w - 'a';
			if (tmp->child[index] == nullptr) {
				tmp->child[index] = new Trie();
			}
			tmp = tmp->child[index];
		}
		tmp->isEnd = true;
		tmp->word = s;
	}
	string longest() {
		Trie *tmp = this;
		queue<Trie *>q;
		q.push(this);
		string ans;
		while (!q.empty()) {
			int s = q.size();
			auto a = q.front();
			q.pop();
			for (int i = 25; i >= 0; i--) {
				if (a->child[i] && a->child[i]->isEnd) {
					ans = a->child[i]->word;
					q.push(a->child[i]);
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	string longestWord(vector<string>& words) {
		Trie *t = new Trie();
		for (auto &w : words) {
			t->insert(w);
		}
		return t->longest();
	}
};