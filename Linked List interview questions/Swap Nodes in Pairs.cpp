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
    ListNode* swapPairs(ListNode* head) {
        ListNode* itr=head;
        while(itr!=NULL && itr->next!=NULL)
        {
            int temp=itr->val;
            itr->val=itr->next->val;
            itr->next->val=temp;
            itr=itr->next->next;
        }
        return head;
    }
};