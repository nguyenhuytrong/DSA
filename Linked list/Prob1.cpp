#include <bits/stdc++.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curN = head;
        ListNode* temp = nullptr;

        while (curN != nullptr && curN->next != nullptr) {
            if (curN->val == curN->next->val) {
                temp = curN->next->next;
                curN->next = temp;
            } else {
                curN = curN->next;
            }
        }

        return head;
    }
};