class TreeNode:

    def __init__(self, key, value, parent=None):

        self.key = key

        self.value = value

        self.left = None

        self.right = None

        self.parent = parent

    def __repr__(self):

        left_key = self.left.key if self.left else None

        right_key = self.right.key if self.right else None

        parent_key = self.parent.key if self.parent else None

        return f"key: {self.key}, value: {self.value}, left: {left_key}, right: {right_key}, parent: {parent_key}"

def rotate_left(node):

    # ************************ Implement Me *******************************

    pass

def print_tree(node, level=0):

    if not node:

        return

    indent = " " * (4 * level)

    print(f"{indent}{node}")

    if node.left:

        print_tree(node.left, level + 1)

    if node.right:

        print_tree(node.right, level + 1)

root = TreeNode(10, '10_val')

new_root = TreeNode(20, '20_val', root)

root.right = new_root

new_root.right = TreeNode(30, '30_val', new_root)

print("before rotation: ")

print_tree(root)

rotate_left(root)

print("\nafter rotation: ")

print_tree(new_root)
print(11)