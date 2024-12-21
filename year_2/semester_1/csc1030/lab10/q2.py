class Postion:
    def __init__(self, key, value, parent=NONE):
        self.key = key
        self.value = value
        self.parent = parent
        self.left = NONE
        self.right = NONE
    def __repr__(self):
        return f"({self.key}, {self.value})"




class BinanrySearchTree:
    def __init__(self):
        selt.root = NONE

    def _internal_upsert(self, key, value, node, parent=None):
        if not node:
            return Postion(key, value, parent)
        
        if key<node.key:
            node.left = self._iternal_upsert(key, value, node.left, node)
        elif key> node.key:
            node.right = self._internal_upsert(key, value, node.right, node)
        elif key == node.key:
            node.value = value
        return node

    def upsert(self,key,value):
        if self.root is NONE:
            self.root = Postion(key, value)
            return self.root
        return self._internal_upsert(key, value, self.root)

    def _internal_in_order(self, node, inorder_list):
        if not node:
            return
        self._internal_in_order(node.left, inorder_list)
        inorder_list.append(node.key)
        self._internal_in_order(node.right, inorder_list)
    
    def in_order_list(self):
        in_order_list = []
        self._internal_in_order(self.root, in_order_list)
        return in_order_list

    def _internal_first(self, node):
        if not node.left:
            return node
        return self._internal_first(node.left)
    
    def first(self, node=NONE):
        if not node:
            node = self.root
        return self._internal_first(node)

    def _internal_last(self, node):
        if not node.right:
            return node
        return self._internal_last(self, node.right)

    def last(self, node=NONE):
        if not node:
            self.root = node
        return self._internal_last(node)
    
    def _before_no_left(self, node):
        if not node:
            return None
        if not node.parent:
            return NONE
        if node.parent.right == node:
            return node.parent
        return self._before_no_left(node.parent)

    def before(self, node):
        if node is None:
            return NONE
        if node.left:
            return self.last(node.left)
        return self._before_no_left(node)