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

_________________________________________________________________________________

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases (like removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 1: Move fast ahead by n+1 steps so that slow is just before target
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 2: Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Remove the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;  // Free memory

        return dummy->next; // Return new head
    }
};

_________________________________________________________________________________

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* start = new ListNode(); // taking an empty listnode
        start->next =  head;     //make it's next to head pointer

        ListNode* fast= start;
        ListNode* slow = start;

        while(n--)fast= fast->next;

        while(fast->next!=NULL){
            fast=fast->next;
            slow= slow->next;
        }
        slow->next= slow->next->next;

        return start->next;
    }

};
View
