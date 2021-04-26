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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode();
        pre->next=head;
        ListNode* ans=pre;
        while(head!=NULL)
        {
            if(head->val==val)
            {
                pre->next=head->next;
            }
            else
            {
                pre=head;
            }
            head=head->next;
        }
        return ans->next;
    }
};