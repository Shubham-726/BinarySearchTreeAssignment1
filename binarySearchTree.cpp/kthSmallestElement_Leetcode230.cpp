class Solution
{
public:
    // bst ka inorder sorted hota hai, use that property
    int k, ans = -1;
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        k--;
        if (k == 0)
            ans = root->val;
        helper(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        this->k = k;
        helper(root);
        return ans;
    }
};