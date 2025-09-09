#include<bits/stdc++.h>
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
    ListNode* removeElements(ListNode* head, int val) {
        // Dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                // Remove node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  // free memory
            } 
            else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // cleanup dummy
        return newHead;
    }
};