#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		help(head);
		return head;



	}
	void help(ListNode* &head)
	{
		if (head&&head->next)
		{
			ListNode* m = nullptr;
			m = head->next;

			head->next = m->next;
			m->next = head;
			head = m;
			help(head->next->next);


		}
	}

};