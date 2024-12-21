#!/usr/bin/env python3

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
    rotation_root = node
    new_root = node.right

    if new_root.left:
        rotation_root.right = new_root.left
        new_root.left.parent = rotation_root
    else:
        rotation_root.right = None
    new_root.left = rotation_root

    new_root.parent = rotation_root.parent
    if rotation_root.parent:
        if rotation_root.parent.left == rotation_root:
            rotation_root.parent.left = new_root
        else:
            rotation_root.parent.right = new_root
    rotation_root.parent = new_root

def rotate_right(node):
    rotation_root = node
    new_root = rotatation_root.left

    if new_root.right:
        rotatation_root.left = new_root.right
        new_root.right.parent = rotatation_root
    else:
        rotatation_root.left = None
    new_root.right = rotatation_root
    new_root.parent = rotatation_root.parent
    if rotatation_root.parent:
        if rotatation_root.parent.right == rotatation_root:
            rotatation_root.parent.right == new_root
        else:
            rotatation_root.parent.left == new_root
    rotatation_root.parent = new_root

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

#print("before rotation: ")
#print_tree(root)

rotate_left(root)

#print("\nafter rotation: ")
#print_tree(new_root)

#2
class MySortedMap:

    def __init__(self):

        self.sorted_list = []

    def find_index(self, key):
        low = 0
        high = len(self.sorted_list) - 1

        while low <= high:
            mid = (high-low)//2
            if self.sorted_list[mid][0] == key:
                return mid
            elif key > self.sorted_list[mid][0]:
                low = mid + 1
            elif key < self.sorted_list[mid][0]:
                high = mid - 1

        return low


    def insert(self, key, value):

        index = self.find_index(key)

        if index < len(self.sorted_list) and self.sorted_list[index][0] == key:

            self.sorted_list[index] = (key, value)

        else:

            self.sorted_list.insert(index, (key, value))

    def print(self):

        for t in self.sorted_list:

            print(t)

sorted_map = MySortedMap()

sorted_map.insert("2024-11-04T15:10:42Z", "Transaction D")

sorted_map.insert("2024-11-03T15:10:42Z", "Transaction C")

sorted_map.insert("2024-11-02T15:10:42Z", "Transaction B")

sorted_map.insert("2024-11-01T15:10:42Z", "Transaction A")



sorted_map.insert("2024-11-02T15:10:42Z", "Transaction B New")

sorted_map.insert("2024-11-01T15:10:42Z", "Transaction A New")

sorted_map.insert("2024-10-31T15:10:42Z", "Transaction Before A")

sorted_map.print()

import random

class SkipListNode:

    def __init__(self, value, level):
        self.value = value
        self.next = [None] * (level+1)

    def __repr__(self):
        return f"{self.value}"

class SkipList:

    def __init__(self, max_level = 4, p=0.5):
        self.max_level = max_level
        self.p = p
        self.head = SkipListNode(float('-inf'), max_level)
        self.tail = SkipListNode(float('inf'), max_level)

        for i in range(max_level + 1):
            self.head.next[i] = self.tail

    def get_level(self):

        level = 0
        while random.random() < self.p and level < self.max_level:
            level += 1

        return level

    def display(self):
        for i in range(self.max_level, -1, -1):
            current = self.head
            print(i, end=' -> ')
            while current:
                print(current, end=' -> ')
                current = current.next[i]
            print(None)

    def insert(self, new_val):

        update_node_list = [None] * (self.max_level+1)

        current = self.head

        # we need to get the node just before the one to be inserted on each level
        for i in range(self.max_level, -1, -1):
            while current.next[i].value < new_val:
                current = current.next[i]
            update_node_list[i] = current

        # create a new node
        level = self.get_level()
        new_node = SkipListNode(new_val, self.max_level)

        # put the new node on each level
        for i in range(level+1):
            new_node.next[i] = update_node_list[i].next[i]
            update_node_list[i].next[i] = new_node

if __name__ == '__main__':

    skip_list = SkipList()
    skip_list.insert(20)
    skip_list.insert(30)
    skip_list.insert(10)
    skip_list.insert(50)
    skip_list.insert(8)
    skip_list.insert(200)

    skip_list.display()

