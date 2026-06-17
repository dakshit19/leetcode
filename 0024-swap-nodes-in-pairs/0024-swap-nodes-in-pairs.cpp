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
        if (!head || !head->next) return head;

        ListNode* temp= head;
        head= temp->next;
        temp->next= head->next;
        head->next= temp;

        while(temp->next){
            ListNode* p= temp->next;
            if (p->next == nullptr) return head;
            temp->next = p->next;
            p->next= temp->next->next;
            temp->next->next= p;
            p= nullptr;
            delete p;
            temp= temp->next->next;
        }

        return head;
    }
};