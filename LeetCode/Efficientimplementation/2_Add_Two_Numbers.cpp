#include<iostream>
#include <string>

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

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
    
    ListNode* dummyHead = new ListNode(0); // initializer; This is something we will return.
    ListNode* current = dummyHead;
    int carry = 0; // store the carry value

    while( l1 || l2 || carry){
      int sum = carry; // Carry will be set to sum for second time of the loop, it can be helpful.

      if(l1){
        sum += l1->val;
        l1 = l1->next;
      }

      if(l2){
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10; // if sum = l1->val + l2->val = 6 + 9 = 15; we do 15/10 and store the Quotient. This is used for next step
      cout << carry << endl;

      current->next = new ListNode(sum % 10); // store the single digit. We store the remainider actually since that's the value on the Right Most Side
      current = current->next;

    }

    return dummyHead->next;

    }
};


int main(){

    Solution* newSol = new Solution;

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* printSol = newSol->addTwoNumbers(l1, l2);

    while(printSol){
      cout << printSol->val << "->";
      printSol = printSol->next;
    }
    cout << "NULL" << endl;

    return 0;
}
