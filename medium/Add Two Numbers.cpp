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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
        int mem = 0;
        while (l1 || l2 || mem > 0) {
            int val1 = 0, val2 = 0;
            if (l1) val1 = l1->val;
            if (l2) val2 = l2->val;
            int digit = (val1 + val2 + mem) % 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
            mem = (val1 + val2 + mem) / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return res->next;
    }
};
