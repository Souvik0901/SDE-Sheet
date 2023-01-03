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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p=head;
        ListNode* q=head;
        while(n--) q=q->next;

        if(!q) return head->next;
        while(q->next){
            p=p->next;
            q=q->next;
        }
        ListNode* dummy = p->next;
        p->next= dummy->next;

        delete dummy;
        return head;
    }
};
