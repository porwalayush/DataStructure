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
    int leng(ListNode* head)
    {
        int tmp=0;
        while(head!=NULL)
        {
            head=head->next;
            tmp++;
        }
        return tmp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)                    // for empty list
            return head;
        int l=leng(head);
        k=k%l;                          // for tle 
        for(int i=1;i<=k;i++)
        {
            ListNode* cur=head->next;
            int prev=head->val;
            while(cur!=NULL)
            {
                int tmp=cur->val;
                cur->val=prev;
                prev=tmp;
                cur=cur->next;
            }
            head->val=prev;
        }
        
        return head;
        
    }
};