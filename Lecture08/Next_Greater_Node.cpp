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


//N*N:

//Stack is the most optimised way.

//Kitna bar aapka Prgram kaam kar raha hain computations vs input ka graph ka relation.

//x y z t m

//x: next greater : 4:
//y: 3
//z: 2
//t: 1

//n = 5:
//4+3+2+1:

//n=100:
//99+98+97+96+95+94................1

//n*(n+1)/2:

//n: Input : n*(n+1)/2:

//Input : N: Computation: (N*N+N)~~~~ N*N:


class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {

		vector<int>ans;

		while (head != NULL) {

			ListNode* temp = head;

			//Find the next greater element for the current head through traversal.

			while (temp != NULL and temp->val <= head->val) {
				temp = temp->next;
			}

			if (temp != NULL) {
				ans.push_back(temp->val);
			} else {
				ans.push_back(0);
			}

			//Next head ke liye next greater element nikalo.
			head = head->next;

		}

		return ans;
	}
};


int main() {

}