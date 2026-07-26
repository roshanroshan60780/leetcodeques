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
private:
    pair<ListNode* , ListNode*> reverse(ListNode* head, int k){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=nullptr;
        while(k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        return {prev,curr};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        temp=dummy;
        while(n>=k){
            pair<ListNode*,ListNode*> rev=reverse(temp->next,k);
            ListNode* newtemp=temp->next;
            temp->next->next=rev.second;
            temp->next=rev.first;
            temp=newtemp;
            n-=k;
        }
        return dummy->next;
    }
};