/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {
        if (head == nullptr) return 0;
        int len = 1;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        int len = getLength(head);
        k = k % len;
        if (k == 0) return head;

        ListNode* cur = head;
        while (k > 0) {
            ListNode* slow_cur = nullptr;
            ListNode* st = cur;
            while (cur->next != nullptr) {
                slow_cur = cur;
                cur = cur->next;
            }
            cur->next = st;
            if (slow_cur) slow_cur->next = nullptr;
            k--;
        }
        return cur;
    }
};
