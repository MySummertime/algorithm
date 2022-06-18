// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* cur = head;
        while (cur->next != head) {
            int val = cur->val;
            int next_val = cur->next->val;
            if (next_val < val) {
                if (next_val >= insertVal || (val <= insertVal)) {
                    break;
                }
            }
            if (val <= insertVal && insertVal <= next_val) {
                break;
            }
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};