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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *a=l1, *b=l2;
        ListNode *head= new ListNode(-1);
        ListNode *temp=head;
        int carry=0;
        while(a!=nullptr || b!=nullptr || carry>0)
        {
            int sum = carry;
            if(a!=nullptr)
            {
                sum+=a->val;
                a=a->next;
            }
            if(b!=nullptr)
            {
                sum+=b->val;
                b=b->next;
            }
            temp->next = new ListNode(sum%10);
            carry=sum/10;
            temp=temp->next;
        } 
        return head->next;
    }
};