#include <algorithm>
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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* x= head;
        while (x){
            v.push_back(x->val);
            x= x->next;
        }
        sort(v.begin(), v.end());
        int i=0;
        x= head;
        while (x){
            x->val= v[i];
            x= x->next;
            i++;
        }
        return head;
    }
};