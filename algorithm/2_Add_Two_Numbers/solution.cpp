#include <iostream>




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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0);
		ListNode* tmp = ans;
		int up = 0;
		while (l1 || l2 || up) {
			int i1 = 0, i2 = 0;
			if (l1) {
				i1 = l1->val;
				l1 = l1->next;
			}
			if (l2) {
				i2 = l2->val;
				l2 = l2->next;
			}
			if (i1 + i2 + up > 9) {
				ans->next = new ListNode(i1 + i2 + up - 10);
				ans = ans->next;
				up = 1;
			}
			else {
				ans->next = new ListNode(i1 + i2 + up);
				ans = ans->next;
				up = 0;
			}
		}
		return tmp->next;
	}
};