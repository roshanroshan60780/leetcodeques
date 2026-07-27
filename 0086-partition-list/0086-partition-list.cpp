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
    ListNode* partition(ListNode* head, int x){
        if(!head || !head->next) return head;
        ListNode* temp=head;
        ListNode* dummy=new ListNode(-1);
        ListNode *greater=dummy;
        while(temp && temp->val >= x){
            greater->next=temp;
            greater=temp;
            temp=temp->next;
        }
        head=temp;
        while(temp && temp->next){
            if(temp->next->val>=x){
                greater->next=temp->next;
                greater=temp->next;
                temp->next=temp->next->next;
            }
            else temp=temp->next;
        }
        greater->next=nullptr;
        if(!head) return dummy->next;
        temp->next=dummy->next;
        return head;
    }
};