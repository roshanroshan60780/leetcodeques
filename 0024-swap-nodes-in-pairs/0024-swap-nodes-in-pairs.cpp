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
        if(!head || !head->next) return head;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* node=head;
        ListNode* nextpairstart;
        while(node && node->next){
            temp->next=node->next;
            temp=temp->next;
            nextpairstart=temp->next;
            temp->next=node;
            temp=node;
            temp->next=nextpairstart;
            node=nextpairstart;
        }
        return dummy->next;
    }
};