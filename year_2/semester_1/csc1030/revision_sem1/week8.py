#!/usr/bin/env python3
class Postion:
    def __init__(self, key, value, parent=None):
        self.key = key
        self.value = value
        self.parent = parent
        self.left = None
        self.right = None
    def __repr__(self):
        return f"({self.key}, {self.value})"

class BinarySearchTree:
    def __init__(self):
        self.root = None
    def _internal_upsert(self, key, value, node, parent=None):
        if not root:
            return Postion(key, value, node)
        elif key < node.key:
            node.left = Postion(key, value, node.left, node)
        elif key > node.key:
            node.right = Position(key, value, node.right, node)
        elif key == node.key:
            node.value = value
        return node

    def upsert(self, key, value):
        if self.root is None:
            self.root = Position(key, value)
            return self.root
        return self._internal_upsert(key, value, self.root)

    def _internal_in_order(self, node, in_order_list):
        if node is None:
            return
        self._internal_in_order(node.left, in_order_list)
        in_order_list.append(node.key)
        self._internal_in_order(node.right, in_order_list)
    
    def in_order(self):
        in_order_list = []
        self._internal_in_order(self.root, in_order_list)
        return in_order_list
    def _internal_first(self, node):
        if not node.left:
            return node
        return self._internal_first(node.left)

    def first(self, node=None):
        if not node:
            node = self.root
        return self._internal_first(node)
    def _internal_last(self, node):
        if not node.right:
            return node
        return self._internal_last(node.right)
    def last(self, node=None):
        if not node:
            node = self.root
        return self._internal_last(node)

    def _after_no_right(self, node):
        if not node:
            return None
        elif not node.parent:
            return None
        elif node.parent.left == node:
            return node.parent
        return _after_no_right(node.parent)

    def after(self, node):
        if not node:
            return None
        if node.right:
            return self.first(node.right)
        return _after_no_right(node)

    def in_order_using_after(self, node=None):
        if not node:
            node = self.root
        in_order_list = []
        current = self.first(node)
        while current:
            in_order_list.append(current.key)
            current = self.after(current)
        return in_order_list


    def _before_no_left(self, node):
        if not node:
            return None
        elif not node.parent:
            return None
        elif node.parent.right == node:
            return node.parent
        return self._before_no_left(node.parent)

    def before(self, node):
        if node is None:
            return None
        if node.left:
            return self.last(node.left)
        return self._before_no_left(node)


    def in_order_using_before(self, node=None):
        if not node:
            node = self.root
        in_order_list = []
        current = self.last(node)
        while current:
            in_order_list.append(current.key)
            current = self.before(current)
        in_order_list.reverse()
        return in_order_list

    
    def _find_internal(self, key, node):
        if not node:
            return None

        if key < node.key:
            return self._internal_first(key, node.left)
        elif key > node.key:
            return self._internal_first(key, node.right)
        elif key == node.key:
            return node

    def find(self, key, node=None):
        if not node:
            self.root = node
        if not node:
            return None
        return self._find_internal(key, node)
    def _internal_preorder(self, node, result_list):
        if node is None:
            return
        result_list.append(node.key)
        self._internal_preorder(node.left, result_list)
        self._internal_preorder(node.right, result_list)
        return preorder

    def preorder(self, node=None):
        if not node:
            node = self.root
        preorder = []
        self._internal_preorder(node, preorder)
        return preorder

    def _internal_postorder(self, node, result_list):
        if node is None:
            return
        self._internal_postorder(node.left, result_list)
        self._internal_postorder(node.right, result_list)
        result_list.append(node.key)

    def postorder(self, node=None):
        if not node:
            node = self.root
        postorder = []
        self._internal_postorder(node, postorder)
        return postorder

    
    def delete(self, node):
        if not node:
            return
        if node.left and node.right:
            before = self.before(node)
            node.value = before.value
            node.key = before.key
            self.delete(before)
        else:
            if self.root == node:
                if node.left:
                    self.root = node.left
                if node.right:
                    self.root = node.right
                else:
                    self.root = None
            else:
                if node.parent.left == node:
                    if node.left:
                        node.parent.left = node.left
                    else:
                        node.parent.left = node.right
                elif node.parent.right == node:
                    if node.right:
                        node.parent.right = node.right
                    else:
                        node.parent.right = node.left

#2
def basic_hash(chars):
    total = 0
    for c in chars:
        total += ord(c) 
    return total

def postion_hash(chars):
    total = 0
    prime = 13
    for i in range(len(chars)):
        total += (ord(chars[i]) * (prime**i))
    return total

def compression(hash, buckets, str):
    count = len(buckets)
    hash_index = hash % count
    buckets[hash_index].append(str)

def insert(str, buckets):
    hash = postion_hash(str)
    compression(hash, buckets, str)


count = 11
buckets = [[] for _ in range(count)]
insert('stop', buckets)
insert('tops', buckets)
insert('pots', buckets)
insert('spot', buckets)
print(buckets)
