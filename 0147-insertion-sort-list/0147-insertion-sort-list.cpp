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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0), *cur = head;
        while (cur != NULL){
            ListNode *prev = dummy, *next = cur->next;
            while (prev->next != NULL && prev->next->val < cur->val){
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next = cur;
            cur = next; 
        }
        return dummy->next;
    }
};