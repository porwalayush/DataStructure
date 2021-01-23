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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* list1=reverseList(l1);
        ListNode* list2=reverseList(l2);
        ListNode* ans=NULL;
        int carry=0;
        while(list1!=NULL || list2!=NULL || carry!=0)
        {
            ListNode* node= new ListNode();
            int sum=0;
           if(list1!=NULL)
           {
              sum+=list1->val;
               list1=list1->next;
           }
           if(list2!=NULL)
           {
              sum+=list2->val;  
               list2=list2->next;
           }
            sum+=carry;
            node->val=sum%10;
            node->next=ans;
            ans=node;
            carry=sum/10;
        }
        return ans;
        
    }
    
        ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};