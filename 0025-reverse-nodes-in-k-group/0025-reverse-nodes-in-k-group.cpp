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
    ListNode* reverse(ListNode* head){
        if(head->next == nullptr) return head;
        ListNode* front = head;
        ListNode* prev = nullptr;
        while(head != nullptr){
            front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
     }
    
    ListNode* findKthNode(ListNode* head, int k){
        while(k > 1){
            if(head){
                head = head->next;
                k--;
            }
            else{
                return nullptr;
            }
        }
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp,k);
            if(kthNode == nullptr){
                prevNode->next = temp;
                return head;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverse(temp);
            if(head == temp) head = kthNode;
            else{
                if(prevNode) prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }    
        return head;
    }
};