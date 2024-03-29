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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* p = head->next;
        ListNode* q = head;

        while(p != NULL) {
            p = p->next;
            if(p != NULL) p = p->next;
            q = q->next;
        }

        return q;
    }
};