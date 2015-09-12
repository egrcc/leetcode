/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        TreeNode *left;
        TreeNode *right;
        if (root != NULL) {
            int val = root->val;
            left = root->left;
            right = root->right;
            if (left == NULL && right == NULL) {
                s.push_back(to_string(val));
                return s;
            }
            vector<string> left_s = binaryTreePaths(left);
            vector<string> right_s = binaryTreePaths(right);
            string str = to_string(val) + "->";

            
            for (int i = 0; i < left_s.size(); i++) {
                left_s[i] = str + left_s[i];
            }
        
  
            for (int i = 0; i < right_s.size(); i++) {
                right_s[i] = str + right_s[i];
            }    
            
            left_s.insert(left_s.end(), right_s.begin(), right_s.end());
            s = left_s;
        }
        return s;   
    }
};