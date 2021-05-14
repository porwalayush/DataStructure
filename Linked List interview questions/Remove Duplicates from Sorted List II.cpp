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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre= new ListNode();
        pre->next=head;
        ListNode* ans=pre;
        while(head!=NULL)
        {
            if(head->next!=NULL && head->val == head->next->val)
            {
                while(head->next!=NULL && head->val == head->next->val)
                {
                    head=head->next;
                }
                pre->next=head->next;   // head->next can be nextone 
            }
            else
            {
                pre=pre->next;       
            }
            head=head->next;
        }
        return ans->next;
    }
};