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
public:
	ListNode* partition(ListNode* head, int x) {

		ListNode* bh = NULL, *b = NULL, *ch = NULL, *c = NULL, *nxt;

		while (head != NULL) {
			nxt = head->next;
			if (head->val < x) {

				if (c == NULL) {
					ch = c = head;
					head->next = NULL;
					head = nxt;
				} else {
					c->next = head;
					head->next = NULL;
					c = head;
					head = nxt;
				}

			} else {

				if (b == NULL) {
					bh = b = head;
					head->next = NULL;
					head = nxt;
				} else {
					b->next = head;
					head->next = NULL;
					b = head;
					head = nxt;
				}
			}
		}

		if (c != NULL) {
			c->next = bh;
			return ch;

		} else {
			return bh;
		}

	}
};

int main() {

}