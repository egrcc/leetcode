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

TreeNode* sortedArrayToBST(vector<int>& nums) {

    if (nums.size() == 0) return NULL;
    vector<int>::iterator mid = nums.begin() + (nums.size() - 1) / 2;
    TreeNode node(*mid);
    TreeNode *p = &node;
    cout << "aaa" << endl;
    if (nums.size() == 1) return p;
    cout << "aaa" << endl;
    vector<int> left_vec(nums.begin(), mid);
    vector<int> right_vec(mid + 1, nums.end());
    p->left = sortedArrayToBST(left_vec);
    p->right = sortedArrayToBST(right_vec);
    return p;
}

int main(int argc, char const *argv[])
{   
    // vector<int> v;
    // v.push_back(2);
    // v.push_back(5);
    // TreeNode *p = sortedArrayToBST(v);
    int A[5];
    A[1] += 2;
    cout << A[1] << endl;
    return 0;
}