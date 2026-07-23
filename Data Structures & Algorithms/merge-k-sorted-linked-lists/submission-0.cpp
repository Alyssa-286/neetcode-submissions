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
ListNode* merge2lists(ListNode* list1,ListNode* list2)
        { 
        ListNode dummy(0);
        ListNode* tail=&dummy;
        if(list1==nullptr&&list2==nullptr)
        return nullptr;
        while(list1!=nullptr&&list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                list1=list1->next;
            }
            else
            {
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
            if(list1!=nullptr)
            tail->next=list1;
        else
            tail->next=list2;
        return dummy.next;
        }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //this is the only thing i remember heheee i'm fooling aroung i know i should merge a vector of lists into a biggg list
        if(lists.empty())
        return nullptr;
        while(lists.size()>1)
        {
            vector<ListNode*>mergedlists;
            for(int i=0;i<lists.size();i+=2)
            {
                ListNode* l1=lists[i];
                ListNode* l2=(i+1<lists.size())?lists[i+1]:nullptr;
                mergedlists.push_back(merge2lists(l1,l2));
            }
            lists=mergedlists;
        }
        return lists[0];
    }
};
