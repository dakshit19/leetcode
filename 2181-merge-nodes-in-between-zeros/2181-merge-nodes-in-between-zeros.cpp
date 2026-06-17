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
    ListNode* mergeNodes(ListNode* head) {
        int curr_sum=0;
        ListNode* newlist= new ListNode(0);
        ListNode* x= newlist;
        ListNode* temp= head->next; // traverse through original list 

        while(temp){
            if (temp->val == 0){
                ListNode* newnode= new ListNode(curr_sum);
                x->next= newnode;
                x =x->next;
                curr_sum=0;
            } else curr_sum += temp->val;
            
            temp= temp->next; //goto next list item
        }

        return newlist->next;
    }
};