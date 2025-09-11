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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        if(list2->val <= list1->val)
        {
            list2->next= mergeTwoLists(list2->next, list1);
            return list2;
        }
        return NULL;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKListsHelper(lists, left, mid);
        ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
};

//Divide and Conquer Approach( Using Recursion)
//Time Complexity: 0(N LogK)
//Space Complexity: 0(LogK)
______________________________________________________________________________________

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        if(list2->val <= list1->val)
        {
            list2->next= mergeTwoLists(list2->next, list1);
            return list2;
        }
        return NULL;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        for(int i=1; i<lists.size(); i++){
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }

};

//Iterative Merge 
//Time Complexity: 0(N K)
//Space Complexity: 0(1)

______________________________________________________________________________


