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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node1 = list1;
        ListNode* node2 = list1;
        for (int i = 0; i < a - 1; i++) {
            node1 = node1->next;
        }
        for (int i = 0; i <= b; i++) {
            node2 = node2->next;
        }
        node1->next = list2;
        while (node1->next != NULL) {
            node1 = node1->next;
        }
        node1->next = node2;
        return list1;
    }
};