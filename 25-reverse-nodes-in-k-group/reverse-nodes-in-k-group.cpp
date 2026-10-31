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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=NULL;
        ListNode* cur=head;
        int c=0;
        ListNode* t=head;
        for(int i=0;i<k;i++){
            if(t==NULL)
            return head;
            t=t->next;
        }
        c=0;
        ListNode* next=NULL;
        while(cur && c<k){
            next=cur->next;
            cur->next=temp;
            temp=cur;
            cur=next;
            c++;
        }
        if(next)
        head->next=reverseKGroup(next,k);
        return temp;
    }
};