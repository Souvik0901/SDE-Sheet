
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* first= head;
        ListNode* slow =head;

        while(first and first->next){
            slow= slow->next;
            first= first->next->next;
            if(slow == first) return true;
        }
        return false;
    }
};
