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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp) {
            v.push_back({temp->val});
            temp = temp->next;
        }

        for(int i = 0; i < v.size(); i++){
            int sum = 0;
            for(int j = i; j < v.size(); j++){
                sum += v[j];
                if(sum == 0){
                    v.erase(v.begin() + i, v.begin() + j + 1);
                    i--;
                    break;
                }
            }
        }
        for(auto& i : v) cout<<i<<" ";
        if(v.size() == 0) return NULL;
        ListNode* ll = new ListNode(v[0]);
        ListNode* node = ll;
        for(int i = 1; i < v.size(); i++) {
            ListNode* ll = new ListNode(v[i]);
            node->next = ll;
            node = node->next;
        }
        
        return ll;
    }
};