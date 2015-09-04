/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {

        // vector<vector<int>> v;
        // if (root == NULL) return v;

        // vector<int> level;
        // level.push_back(root->val);
        // v.push_back(level);

        // vector<vector<int>> left_v = levelOrder(root->left);
        // vector<vector<int>> right_v = levelOrder(root->right);
        // int level_num = (left_v.size() > right_v.size())?left_v.size():right_v.size();

        // vector<int> left_level, right_level;

        // for (int i = 0; i < level_num; i++) {

        //     if (i < left_v.size()) {
        //         left_level = left_v[i];
        //     } else {
        //         left_level = vector<int>();
        //     }
        //     if (i < right_v.size()) {
        //         right_level = right_v[i];
        //     } else {
        //         right_level = vector<int>();
        //     }
        //     left_level.insert(left_level.end(), right_level.begin(), right_level.end());
        //     v.push_back(left_level);

        // }
        // return v;
        
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> v;
        if (root == NULL) return v;

        queue<TreeNode *> current, next;
        current.push(root);
        vector<int> level; 

        while (!(current.empty())) {
            while (!(current.empty())) {
                TreeNode *t = current.front();
                level.push_back(t->val);
                if (t->left != NULL) next.push(t->left);
                if (t->right != NULL) next.push(t->right);
                current.pop();
            }
            v.push_back(level);
            level.clear();
            swap(next, current);
        }

        return v;
        
    }
};