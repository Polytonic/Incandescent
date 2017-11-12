"""See C++ Solution for Detailed Explanation"""
def checkBST(node, min=None, max=None):
    if not node:
        return True

    if (min and node.data <= min.data or
        max and node.data >= max.data):
        return False

    return (checkBST(node.left, min, node) and
            checkBST(node.right, node, max))
