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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check=head;
        for(int i=0;i<k;i++)
        {
            if(check==nullptr)
            {
                return head;
            }
            check=check->next;
        }
      
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        ListNode* cur=head;
        for(int i=0;i<k;i++)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        if(next!=nullptr)
        {
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
        
    }
};
