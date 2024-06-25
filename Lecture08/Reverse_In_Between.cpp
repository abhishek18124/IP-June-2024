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


// You have created a data type of ListNode.
// int x;

// //Static Variable
// ListNode x;
// x.val;

// Dynamic Variable:
// int *ptr = new int(10);

// ListNode* n = new ListNode(20);

// cout << n ?? : Pointer that stores an address;

// is Address par vo value padi hain uska data member fetch karo.


// (*n).val; Ye bhi likh sakte ho
//n->val :


class Solution {
public :
    ListNode* left = NULL;
    bool complete = 0;

    void Solve(ListNode* right, int m, int n) {

        if (n == 1) {
            return;
        }

        right = right->next;

        if (m > 1) {
            left = left->next;
        }


        Solve(right, m - 1, n - 1);

        //If I am Standing here that means I am At the the correct Position.

        if (left == right or right->next == left) {
            //You have done the task.
            complete = 1;
        }

        if (complete == 0) {
            //Swap Karn hain.
            int temp = left->val;
            left->val = right->val;
            right->val = temp;

            left = left->next;
        }
    }


    ListNode* reverseBetween(ListNode* head, int m, int n) {
        left = head;
        Solve(head, m, n);
        return head;
    }
};

class Solution {
public :


    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* current = head, *prev = NULL;
        int counter = n - m;//Main is Counter number of times reverse karna chahta hu.

        //Reach at the left/m position.

        while (m > 1) {
            prev = current;
            current = current->next;
            m--;
            n--;
        }

        //Reverse Part:
        ListNode* Pehle = prev;
        ListNode* tail = current;
        ListNode* nxt = NULL;

        while (n > 0) {

            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;

            n--;
        }

        //Breaking Part.
        if (pehla != NULL) {
            pehla->next = prev;
        } else {
            head = prev;
        }

        tail->next = current;
        return head;
    }
};




int main() {

}





//1->2->3->4->5->6->7->8->NULL;


// m = 1
//     n = 4

//         Jab tak mera n > 0 tab tak nodes ko reverse karo.