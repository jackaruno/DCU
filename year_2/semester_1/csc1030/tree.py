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
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)

    return root


def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if root is None:
        return True
    if not min_val < root.val < max_val:
        return false
    return (is_valid_bst(root.left, min_val, root.val) and is_valid_bst(root.right, root.val, max_val))


def inorder_tranversal(root):
    if root:
        return inorder_tranversal(root.left) + [root.val] + inorder_tranversal(root.right)
    else:
        return []

find_kth_smallest(root, k):
    return inorder_tranversal(root)[k-1]

def is_balanced(root):
    def check_balance(node):
        left_height, left_balanced = check_balance(node.left)
        right_height, right_balanced = check_balance(node.right)

        balanced = (left_balanced and right_balanced and abs(right_height-left_height) <= 1)
        return max(left_height, right_height) + 1, balanced
    
    _, is_bal = check_balance(root)
    return is_bal

def iterative_in_order_tranversal(root):
    stack = []
    current = root
    in_order_values = []
    while current is not None or stack:
        while current is None:
            stack.append(current)
            current = current.left
        current = stack.pop()
        in_order_values.append(current.val)

        current = current.right
    return in_order_values