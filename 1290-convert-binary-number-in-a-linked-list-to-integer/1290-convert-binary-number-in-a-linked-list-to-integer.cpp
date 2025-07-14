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
    int getDecimalValue(ListNode* head) 
    {
        int ans=0;
        int cur=1;
        while(head!=nullptr)
        {
            ans= ans*2+(head->val);
            // cur*=2;
            head=head->next;
        }
        
        return ans;
        
    }
};