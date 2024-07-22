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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* front = head;
        while(head != nullptr){
            front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* head1 = head;
        head = new ListNode(-1);
        ListNode* curr = head;
        while(head1 || head2){
            if(head1){
                curr->next = head1;
                curr = head1;
                head1 = head1->next;
            }
            if(head2){
                curr->next = head2;
                curr = head2;
                head2 = head2->next;
            }
        }
        return;
    }
};