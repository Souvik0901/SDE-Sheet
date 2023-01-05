/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


Brute Force Approach 1: 
                           Time Complexity: 0(m*n)
                           Space Complexity: 0(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* temp;  // New Node declaired
      
      //Until NULL , headA node.
        while(headA!= NULL)
        {
           temp = headB;
          
          // Until NULL , Temp node copy of headB
           while(temp!= NULL)
           {
              if(headA == temp) return headA;
              temp = temp->next;
           }
          
          headA = headA->next;  
        }
       
      return NULL;
    }

};



Approach 2: Two pointer Solution

Time Complexity : 0(m+n)
Space Complexity : 0(1)
  
  

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *ptr1= headA;
        ListNode *ptr2= headB;

        while(ptr1 != ptr2)
        {
            if(ptr1== NULL) ptr1= headB;
            else ptr1= ptr1->next;

            if(ptr2== NULL) ptr2 = headA;
            else ptr2= ptr2->next;
        }
        return ptr1;
        
    }
};



Approach 3: Using HashMap

Time Complexity : 0(m+n)
Space Complexity : 0(1)
  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, int>mp;

        while(headA!= NULL)
        {
            mp[headA]++;
            headA= headA->next;
        }

        while(headB!= NULL)
        {
            if(mp[headB]>0) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
