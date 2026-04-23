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
    bool isPalindrome(ListNode* head) {
         if (!head || !head->next) return true;

         ListNode* fast=head;
         ListNode *slow=head;

         while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
         }

         ListNode* secondhalf=reverse(slow->next);

         ListNode* firsthalf=head;
         ListNode* temp=secondhalf;

         while(temp){
            if(temp->val !=firsthalf->val) return false;
            temp=temp->next;
            firsthalf=firsthalf->next;
         }
         return true;
    }

    private: 
            ListNode* reverse(ListNode* head){
                ListNode* prev = NULL;
             while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    
    }
};