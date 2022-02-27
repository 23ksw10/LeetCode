#include <iostream>
#include <vector>


using namespace std;

class TrieNode {
public:
	bool end;
	int child[26];
	TrieNode() {
		end = false;
		for (int i = 0; i < 26; i++) {
			child[i] = -1;
		}
	}
};

class Trie {
public:
	vector<TrieNode>t;
	Trie() {
		newTrie();
	}
	int newTrie() {
		TrieNode tmp;
		t.push_back(tmp);
		return t.size() - 1;
	}
	void insert(string s, int index, int node) {
		if (s.size() == index) {
			t[node].end = true;
			return;
		}
		int c = s[index] - 'a';
		if (t[node].child[c] == -1) {
			int next = newTrie();
			t[node].child[c] = next;
		}
		insert(s, index + 1, t[node].child[c]);
	}
	string search(string s) {
		int next = 0;
		string suc = "";
		for (int i = 0; i < s.size(); i++) {
			int c = s[i] - 'a';
			if (t[next].child[c] == -1)return s;
			suc += s[i];
			next = t[next].child[c];
			if (t[next].end == true)return suc;
		}
		return s;
	}

};


class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		string ans = "";
		Trie a;
		for (auto &d : dictionary) {
			a.insert(d, 0, 0);
		}
		string word = "";
		for (auto &w : sentence) {
			if (w != ' ')word += w;
			else {
				string tmp = a.search(word);
				ans += tmp;
				ans += ' ';
				word = "";
			}
		}
		string tmp = a.search(word);
		ans += tmp;
		return ans;
	}
};