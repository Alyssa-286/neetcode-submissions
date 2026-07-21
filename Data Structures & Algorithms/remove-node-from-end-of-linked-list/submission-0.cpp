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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* my first intuition wronggggg///
        ListNode* temp=head;
        ListNode* front=head;
        auto length = std::distance(ListNode.begin(), ListNode.end()); 
        int count=length;
        int key=length;
        if(head==nullptr||head->next==nullptr)
        {
            head=nullptr;
            return;
        }
        while(temp!=nullptr)
        {
            temp=temp->next;
            
        }
        while(temp!=head && front!=nullptr)
        {
            n--;
            temp=temp->next;
            front=front->next;
            if(n==0)
        }
        */
        ListNode dummy(0,head);
        ListNode* left=&dummy;
        ListNode* right=&dummy;
        if(head==nullptr||head->next==nullptr)
        {
            head=nullptr;
            return head;
        }
        for(int i=0;i<=n;i++)
        {
            right=right->next;
            
        }
        while(right!= nullptr)
            {
                left=left->next;
                right=right->next;
            }
        left->next=left->next->next;//if you do right it points to null
        return dummy.next;



        
    }
};
