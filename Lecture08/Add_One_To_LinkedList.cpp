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




class Solution {
	int FindCarry(ListNode* head) {
		// Base case
		if (head == NULL) {
			return 0;
		}
		if (head->next == NULL) {
			head->val += 1;
			int x = head->val / 10;
			head->val %= 10;
			return x;
		}
		// Recursive case
		int Carry = FindCarry(head->next);
		head->val += Carry;
		int x = head->val / 10;
		head->val %= 10;
		return x;
	}
public:
	ListNode* plusOne(ListNode* head) {
		int Carry = FindCarry(head);
		if (Carry == 1) {
			ListNode* n = new ListNode(1);
			n->next = head;
			head = n;
		}
		return head;
	}
};


int main() {

}