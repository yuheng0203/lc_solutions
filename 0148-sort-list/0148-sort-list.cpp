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
    ListNode* sortList(ListNode* head) {
    int n = 0;
    for (ListNode* cur = head; cur; cur = cur->next) n++;

    for (int i = 1; i < n; i *= 2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        
        int cnt = ceil(1.0 * n / (2 * i));
        while (cnt--) {
            ListNode *p = head, *q = head;
            for (int j = 0; j < i && q; j++) q = q->next;

            ListNode *next = q;
            for (int j = 0; j < i && next; j++) next = next->next;

            int l = 0, r = 0;
            while (l < i && r < i && p && q) {
                if (p->val <= q->val) cur = cur->next = p, p = p->next, l++;
                else cur = cur->next = q, q = q->next, r++;
            }

            while (l < i && p) cur = cur->next = p, p = p->next, l++;
            while (r < i && q) cur = cur->next = q, q = q->next, r++;

            head = next;
        }
        cur->next = nullptr;
        head = dummy->next;
    }
    return head;
}
};