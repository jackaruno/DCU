#!/usr/bin/env python3

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return TreeNode(key)
    else:
        if val < root.val:
            root.left = insert(root.left, key)
        else:
            root.right = insert(root.left, key)
    return root

def is_valid_bst(root, min_val=float("-inf"), max_val=float("inf")):
    if root is None:
        return True
    if not (min_val < root.val < max_val):
        return False
    return is_valid_bst(root.left, min_val, root.val) and is_valid_bst(root.right, root.val, max_val)

def inorder_transversal(root):
    return inorder_transversal(root.left) + [root.val] + inorder_transversal(root.right) if root else []

def find_kth_element(root, k):
    return inorder_transversal(root)[k-1]

def is_balanced(root):
    def check_balance(node):
        if node is None:
            return 0, True
        left_height, left_balanced = check_balance(node.left)
        right_height, right_balanced = check_balance(node.right)

        balanced = (left_balanced and right_balanced and abs(left_height-right_height) <= 1)
        return max(left_height, right_height) + 1, balanced
    
    _, is_bal = check_balance(root)
    return is_bal


def iterative_inorder_transversal(root):
    stack = []
    current = root
    in_order_values = []
    while current is not None or stack:
        while current is not None:
            stack.append(current)
            current = current.left
        current = stack.pop()
        in_order_values.append(current.val)
        current = current.right
    return in_order_values


def binary_tree_paths(root):
    def construct_paths(node, path):
        if node:
            path += str(node.val)
            if not node.left and not node.right:
                paths.append(path)
            else:
                path += '->'
                construct_paths(node.left, path)
                construct_paths(node.right, path)
    
    paths = []
    construct_paths(root, '')
    return paths

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)
print(binary_tree_paths(root))