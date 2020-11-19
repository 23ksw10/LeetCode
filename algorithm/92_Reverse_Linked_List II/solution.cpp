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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)return head;
		ListNode *p = new ListNode(0);
		ListNode *c = head;
		ListNode *ans = p;
		p->next = c;
		while (m > 1) {
			c = c->next;
			p = p->next;
			m--;
			n--;
		}
		ListNode* t = c;
		ListNode* t2 = c;
		c = c->next;
		t->next = nullptr;
		while (n > 1) {
			ListNode *tmp = c;
			c = c->next;
			tmp->next = t;
			t = tmp;
			n--;
		}
		p->next = t;
		t2->next = c;

		return ans->next;
	}
};