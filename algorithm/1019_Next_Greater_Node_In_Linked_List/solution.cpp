#include <iostream>
#include <vector>









using namespace std;





  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  class Solution {
  public:
	  vector<int> nextLargerNodes(ListNode* head) {
		  vector<int>ans;
		  vector<int>stack;
		  for (head; head != nullptr; head = head->next) {
			  while (stack.size() && ans[stack.back()] < head->val) {
				  ans[stack.back()] = head->val;
				  stack.pop_back();

			  }
			  stack.push_back(ans.size());
			  ans.push_back(head->val);

		  }
		  for (auto i : stack)ans[i] = 0;
		  return ans;
	  }
  };