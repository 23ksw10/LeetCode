#include <iostream>
#include <stack>






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
	stack< ListNode* > s;
	ListNode* reverseList(ListNode* head) {
		reverseListStack(head);
		ListNode* ans = NULL;
		revListAns(ans);

		return ans;


	}
	void reverseListStack(ListNode* head) {
		if (head)
		{
			s.push(head);
			reverseListStack(head->next);
		}

	}
	void revListAns(ListNode* &ans)
	{
		if (!s.empty())
		{
			ans = s.top();
			s.pop();
			ans->next = NULL;
			revListAns(ans->next);
		}
		return;
	}
};