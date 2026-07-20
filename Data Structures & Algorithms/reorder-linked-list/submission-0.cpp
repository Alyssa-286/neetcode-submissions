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
    ListNode* slow=head;
    ListNode* fast=head;
    
    if(head==nullptr||head->next==nullptr)
        return;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* second=slow->next;
    slow->next=nullptr;
    ListNode* next=nullptr;
    ListNode* cur=second;
    ListNode* prev=nullptr;
    while(cur!=nullptr)
    {
        next=cur->next;
       cur->next=prev;
        prev=cur;
        cur=next;
    }
    second=prev;
    ListNode* first=head;
    ListNode* temp1=first->next;
    ListNode* temp2=second->next;
    while(second!=nullptr)
    {
       /* head->next=second;
        second->next=temp1;
        temp1->next=temp2;
        temp2->next=temp1->next;
        temp1=temp1->next;
        temp2=temp2->next;*/
        ListNode* temp1 = first->next;   
        ListNode* temp2 = second->next;
        
        first->next = second;           
        second->next = temp1;        
        
        first = temp1;                 
        second = temp2;
    }
    return;


        
    }
};
