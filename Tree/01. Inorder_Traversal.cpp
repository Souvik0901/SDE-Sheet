/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

Iterative Approach:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;   
        stack<TreeNode*> s;
        
        while(true){
            if(root != NULL){
                s.push(root);
                root = root->left;
            }
            else{
                if(s.empty()) break;
                root = s.top();
                ans.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return ans;
    }


Recursive Approach:
class Solution {
public:
  void inorder(TreeNode* root, vector<int>& ans){
       if( root == NULL) return;
         
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
  }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>ans;   
        inorder(root, ans);
        return ans;
    }
};

Time Complexity: 0(N)
Space Complexity: 0(N)
  
