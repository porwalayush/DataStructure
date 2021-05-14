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
        ListNode* dummy = new ListNode();   // for n= length of linkedlist
        dummy->next=head;
        ListNode* i1= dummy;
        ListNode* i2=dummy;
        for(int i=1;i<=n+1;i++)
        {
            i2=i2->next;
        }
        while(i2!=NULL)
        {
            i2=i2->next;
            i1=i1->next;
        }
        i1->next=i1->next->next;
        return dummy->next;      // not head because     [1],n=1
    }
};