Approach 1: 
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
    bool isPalindrome(ListNode* head) {
       
        vector<ListNode*>nums;

        while(head){
            nums.push_back(head);
            head= head->next;
        }

        for(int i=0; i<nums.size()/2; i++){
           if(nums[i]->val!= nums[nums.size()-1-i]->val)
           return false;
        }
        return true;
        
    }
};



Approach 2:

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
    bool isPalindrome(ListNode* head) {
       
        vector<int>nums;

        while(head){
            nums.push_back(head->val);
            head= head->next;
        }

        for(int i=0; i<nums.size()/2; i++){
           if(nums[i]!= nums[nums.size()-1-i])
           return false;
        }
        return true;
        
    }
};
