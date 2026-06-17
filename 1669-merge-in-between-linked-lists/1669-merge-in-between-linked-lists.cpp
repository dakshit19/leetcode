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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p= list2; // p points to last of list2
        while(p->next) p= p->next;

        ListNode* q= list1; // q is for list1 
        for (int i=1; i<=min(a,b)-1; i++) q=q->next;
        
        ListNode* r= q->next;
        q->next= list2;

        int diff= max(b,a)-min(b,a);
        while(diff){
            r= r->next;
            diff--;
        }

        p->next= r->next;
        r->next= nullptr;

        return list1;
    }
};