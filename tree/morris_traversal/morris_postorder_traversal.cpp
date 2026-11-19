vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    TreeNode* curr = root;

    // Step 1: Collect "Root -> Right -> Left" (Mirrored Morris Preorder)
    while (curr != nullptr) {
        if (curr->right == nullptr) {
            postorder.push_back(curr->val);
            curr = curr->left;
        } else {
            // Find leftmost node in the right subtree
            TreeNode* prev = curr->right;
            while (prev->left != nullptr && prev->left != curr) {
                prev = prev->left;
            }

            if (prev->left == nullptr) {
                // First visit: record Root BEFORE going Right
                postorder.push_back(curr->val);
                prev->left = curr;
                curr = curr->right;
            } else {
                // Second visit: cut the thread and go Left
                prev->left = nullptr;
                curr = curr->left;
            }
        }
    }

    // Step 2: Reverse "Root -> Right -> Left" into "Left -> Right -> Root"
    reverse(postorder.begin(), postorder.end());
    return postorder;
}