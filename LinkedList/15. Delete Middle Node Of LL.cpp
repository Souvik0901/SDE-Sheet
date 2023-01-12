class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next== NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;

        return head;
    }
};
