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
        ListNode* fhead=head;
        ListNode* pre= head;
        while(head!=NULL)
        {
            if(pre->val==head->val)
            {
                pre->next=head->next;
            }
            else
            {
                pre=head;
            }
            head=head->next;
        }
        return fhead;
    }
};