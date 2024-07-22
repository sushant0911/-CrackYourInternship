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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head_0 = lists[0];
        for(int i = 1 ; i < lists.size() ; i++){
            ListNode* head_i = lists[i];
            ListNode* dummyNode = new ListNode(-1);
            ListNode* temp = dummyNode;
            while(head_0 && head_i){
                if(head_0->val <= head_i->val){
                    temp->next = head_0;
                    temp = head_0;
                    head_0 = head_0->next;
                }
                else{
                    temp->next = head_i;
                    temp = head_i;
                    head_i = head_i->next;
                }    
            }
            if(head_i == nullptr){
                temp->next = head_0;
            }
            if(head_0 == nullptr){
                temp->next = head_i;
            }
            head_0 = dummyNode->next;
        }
        return head_0;
    }
};