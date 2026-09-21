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
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        stack<ListNode*> st;
        while(temp){
            n++;
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        int i=n/2;
        if(n%2) i++;
        while(i-1){
            st.top()->next=temp->next;
            temp->next=st.top();
            temp=st.top()->next;
            st.pop();
            st.top()->next=nullptr;
            i--;
        }
    }
};