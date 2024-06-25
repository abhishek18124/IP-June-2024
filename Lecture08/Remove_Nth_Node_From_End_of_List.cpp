//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include<bits/stdc++.h>
using namespace std;
const int N = 0;


// Definition for singly-linked list.
class ListNode {
public:
	//Data Members:
	int val;
	ListNode *next;

	//Constructors:
	ListNode() {
		val = 0;
		next = NULL;
	}
	ListNode(int x) {
		val = x;
		// val(x);
		next = NULL;
	}
	ListNode(int x, ListNode *n) {
		val = x;
		next = n;
	}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode *p = head, *q = head;
	while (n--) {
		q = q->next;
	}
	if (!q) {
		return head->next;
	}

	while (q->next) {
		p = p->next;
		q = q->next;
	}

	ListNode* toDelete = p->next;
	p->next = p->next->next;
	delete toDelete;
	return head;
}


int main() {

}