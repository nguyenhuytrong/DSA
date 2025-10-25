#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Node { 
        int val;
        Node* prev;
        Node* next;
        Node (int v): val(v), prev(nullptr), next(nullptr) {}
    };

    Node* buildList(const vector<int>& nums) {
        if (nums.empty()) return nullptr;
        Node* head = new Node(nums[0]);
        Node* curr = head;
        for (int i=1; i<nums.size(); i++) {
            Node* n = new Node(nums[i]);
            curr->next = n;
            n->prev = curr;
            curr = n;
        }
        return head;
    }

    bool isSorted(Node* head) {
        Node* curr= head;
        while (curr && curr->next) {
            if (curr->val > curr->next->val) return false;
            curr = curr->next;
        }
        return true;
    }

    Node* findMinPair(Node* head) {
        Node* curr = head;
        Node* best = head;
        int minSum = head->val + head->next->val;
        while (curr && curr->next) {
            int s = curr->val + curr->next->val;
            if (s < minSum) {
                best = curr;
                minSum = s;
            }
            curr = curr->next;
        }
        return best;
    }

    void mergeList(Node* head, Node*a) {
        Node* b = a->next;
        if (!b) return;
        a->val += b->val;
        a->next = b->next;
        if (b->next) b->next->prev = a;
        delete b;
    }

public: 
    int minimumPairRemoval(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        Node* head = buildList(nums);
        int ans = 0;

        while (!isSorted(head)) {
            Node* minPair = findMinPair(head);
            mergeList(head,minPair); 
            ans ++;
        }

        // Giải phóng danh sách
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        return ans;
    }
};