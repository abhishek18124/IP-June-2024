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
	ListNode* oddEvenList(ListNode* head) {

		if (head == NULL or head->next == NULL) {
			return head;
		}

		ListNode* eh = head->next, *oh = head, *prev = NULL, *current = head, *nxt;

		int Jump = 0;

		while (current != NULL and current->next != NULL) {
			nxt = current->next;
			current->next = nxt->next;
			prev = current;
			current = nxt;
			Jump++;
		}

		if (Jump % 2 == 0) {
			current->next = eh;
		} else {
			prev->next = eh;
		}

		return oh;
	}
};




int main() {

}



//2 Type: BFS: DFS:


//2---->Bahut saare non doable Questions karo: Apti
//Patterns recognise honge: question: Editorial :

//2 Time Spend karo : Ek Idea

//Patience Level: Math / Apti.