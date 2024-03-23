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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return;
        ListNode* fast = head;
        stack<ListNode*> st;
        while(fast != NULL) {
            st.push({fast});
            fast = fast->next;
        }
        int sz = st.size();
        ListNode* res = head;
        int i = 0;
        while(i++ < sz/2) {
            auto temp = st.top();
            st.pop();
            temp->next = res->next;
            res->next = temp;
            res = res->next->next;
        }
        res->next = NULL;
    }
};