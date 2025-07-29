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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode* odd= new ListNode(-1);
        ListNode* oddtail= odd;
        ListNode* even = new ListNode(-1);
        ListNode* eventail= even;
        ListNode* temp;
        int cur=1;
        while(head!=nullptr)
        {
            temp=head;
            head=head->next;
            temp->next=nullptr;
            if(cur&1)
            {
                oddtail->next=temp;
                oddtail=temp;
            }
            else
            {
                eventail->next=temp;
                eventail=temp;
            }
            cur++;
        }
        oddtail->next=even->next;
        return odd->next;
    }
};