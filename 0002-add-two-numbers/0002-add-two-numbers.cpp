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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        /*
        ListNode* head = new Node(sum); because the first node is derived from the constraint of sum that is computed later
        */
        int carry = 0;
        int sum;
        ListNode* dummyNode = new ListNode(-1); // use this every time when a new list is asked to return 
        ListNode* curr = dummyNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != nullptr || temp2 != nullptr){
            sum = carry;
            if(temp1)  { // if we have temp1 != null then we add it's data and move ahead
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if(temp2){
                sum += temp2->val;
                temp2 = temp2->next;
            } 
        
            if(sum >= 10) { // if sum is greater than 10 then only store its x mod 10 value and carry is /10;
            // example 14: then 14%10 is 4 is sum and 14/10 is 1 is carry
                ListNode* newNode = new ListNode(sum%10);
                carry = sum/10;
                curr->next = newNode;
                curr = curr->next;
            }
            else{
                ListNode* newNode = new ListNode(sum);
                carry = 0;
                curr->next = newNode;
                curr = curr->next;
            }
        }
        if(carry){// at last if we have any carry left then print the carry as it is
            ListNode* newNode = new ListNode(carry);
            curr->next= newNode;
            curr = curr->next;
        }
        return dummyNode->next;
    }
};