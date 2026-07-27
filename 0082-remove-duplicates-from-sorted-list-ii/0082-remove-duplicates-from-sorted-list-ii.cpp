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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* node=head;
        int dup;
        while(node && node->next){
            if(node->val == node->next->val){
                dup=node->val;
                while(node && node->val==dup){
                    ListNode* tofree=node;
                    node=node->next;
                    delete tofree;
                }

            }
            else{
                temp->next=node;
                temp=node;
                node=node->next;
            }
        }
        if(node) temp->next=node;
        else temp->next=nullptr;
        return dummy->next;
    }
};