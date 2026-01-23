class Solution {
public:
    // merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // find middle of list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;   // split list
        return mid;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // split
        ListNode* mid = getMid(head);

        // sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // merge
        return merge(left, right);
    }
};
