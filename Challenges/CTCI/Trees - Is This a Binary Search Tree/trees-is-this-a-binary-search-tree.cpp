/**
    Checks that all sub-tree nodes of the passed in node conform to the
    requirements of a binary search tree. This variation avoids checking against
    INT_MIN and INT_MAX which would not typically be available if you are
    comparing nodes that contain non-integer values.

    @param node the (root) node of a binary tree.
    @param min the "left" sibling node to compare against; defaults to nullptr.
    @param max the "right" sibling node to compare against; defaults to nullptr.
    @returns true if the given node satisfies the conditions of a
             binary search tree, or false otherwise.
 */
bool checkBST(Node* node, Node* min = nullptr, Node* max = nullptr) {

    // Either this is a leaf node or the tree is empty.
    if (node == nullptr) {
        return true;
    }

    // In a Binary Search Tree (BST), the key in each node must be greater than
    // or equal to any key stored in the left sub-tree, and less than or equal
    // to any key stored in the right sub-tree. If the current node does not
    // meet this criteria, we should return false.
    if (min && node->data <= min->data
     || max && node->data >= max->data) {
        return false;
    }

    // Perform an in-order traversal of the binary tree.
    return checkBST(node->left, min, node)
        && checkBST(node->right, node, max);
}

// Hypothetically your call stack would be something like this:
checkBST(root, nullptr, nullptr);
checkBST(root->left, nullptr, root);
// ...
checkBST(root->left->left, nullptr, root->left);
// This would return false, so you'd back up one and check the right-side node:
checkBST(root->left->right, root->left, nullptr);
// At this point you'd be checking (via line 23) that the left sibling node
// is not greater than the current (i.e. right) sibling node. Similar, though
// inverted logic would apply when you check the right-subtree.
