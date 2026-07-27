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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) return head;
        ListNode* dummy=new ListNode(-1,head);
        ListNode* temp=dummy;
        int i=0;
        while(i<left-1){
            temp=temp->next;
            i++;
        }
        ListNode* beforeleft=temp;
        ListNode* nodeforright=temp->next;
        ListNode *curr=temp->next,*prev=NULL,*next=NULL;
        while(curr && i!=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        beforeleft->next=prev;
        nodeforright->next=curr;
        return dummy->next;
    }
};