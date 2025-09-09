#include <bits/stdc++.h>
using namespace std;    

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Nếu node này đã được clone rồi -> return node clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Tạo clone của node hiện tại
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // Duyệt neighbors và clone từng cái
        for (auto neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};