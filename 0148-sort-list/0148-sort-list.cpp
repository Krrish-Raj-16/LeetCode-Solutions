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
    ListNode * getMiddle(ListNode* head)
    {
        ListNode* slow= head;
        ListNode* fast = head;
        ListNode* prev=slow;
        while(fast!=nullptr && fast->next !=nullptr)
        {
            prev=slow;
            slow= slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    ListNode* mergeLL(ListNode* left, ListNode*right)
    {
        ListNode* head= new ListNode(-1);
        ListNode * temp = head;
        while(left!=nullptr && right!=nullptr)
        {
            if(left->val <= right->val)
            {
                temp->next=left;
                left=left->next;
            }
            else
            {
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left!=nullptr)
        {
            temp->next=left;
        }
        if(right!=nullptr)
        {
            temp->next=right;
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode *middle = getMiddle(head);
        ListNode *left = head;
        ListNode* right=middle->next;
        middle->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return mergeLL(left, right);
    }
};