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
    ListNode* reverse(ListNode* temp){
        if(temp == nullptr || temp->next == nullptr){
            return temp;
        }
        ListNode* x = reverse(temp->next);
        ListNode* front = temp->next;
        front->next = temp;
        temp->next = nullptr;
        return x;
    }

    ListNode* reverseList(ListNode* head) {
        // Recursive Solution

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverse(head);
        return newHead;


        // Iterative Solution
        
        // if(head == nullptr || head->next == nullptr) return head;
        // ListNode* temp = head;
        // ListNode* prev = nullptr;
        // ListNode* front = nullptr;
        // while(temp != nullptr){
        //     front = temp->next;
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }
        // return prev;
    }
};