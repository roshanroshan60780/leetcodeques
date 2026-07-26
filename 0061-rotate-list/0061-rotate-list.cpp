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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n=0;
        ListNode* temp = head;
        ListNode* prev=nullptr; //to store last node
        while(temp){
            n++;
            prev=temp;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        int i=1;
        temp=head;
        while(i!=n-k){   //n-k is no. of steps to move
            temp=temp->next;
            i++;

        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        prev->next=head;
        return newhead;
    }
};