#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
// #include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> v;
    if (root == NULL) return v;

    vector<int> level;
    level.push_back(root->val);
    v.push_back(level);

    vector<vector<int>> left_v = levelOrder(root->left);
    vector<vector<int>> right_v = levelOrder(root->right);
    int level_num = (left_v.size() > right_v.size())?left_v.size():right_v.size();
    // int level_num = 1;

    vector<int> left_level, right_level;

    for (int i = 0; i < level_num; i++) {

        if ((i > left_v.size() - 1) || left_v.size() == 0) {
            left_level = vector<int>();
        } else {
            left_level = left_v[i];
        }
        if ((i > right_v.size() - 1) || right_v.size() == 0) {
            right_level = vector<int>();
        } else {
            right_level = right_v[i];
        }
        left_level.insert(left_level.end(), right_level.begin(), right_level.end());
        v.push_back(left_level);

    }
    return v;
    
}

int main(int argc, char const *argv[])
{   
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(1);
    q->left = p;
    vector<vector<int>> v = levelOrder(q);
    return 0;
}