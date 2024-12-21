#!/usr/bin/env python3

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    def find(self, item):
        current = self
        while current != None:
            if current.data == item:
                return current
            current = current.next

        



#1
head = Node(0)
current = head
for i in range(1,51):
    current.next = Node(i*2)
    current = current.next
current = head
#while current != None:
#    print(current.data)
#    current = current.next


#2



head = Node("Dublin")
another_node = Node("Galway")
head.next = another_node
a_third_node = Node("Cork")
another_node.next = a_third_node

result = head.find("Galway")
#print(result.data)

#3

class SwapNodesInPairs:
    def swap_pairs(self, head):
        dummy = Node(0)
        dummy.next = head
        current = dummy
        while current.next is not None and current.next.next is not None:
            a = current.next
            b = current.next.next
            a.next = b.next
            current.next = b
            current.next.next = a
            current = current.next.next
        return dummy.next


    def print_list(self, head):
        temp = head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()


s = SwapNodesInPairs()
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
#s.print_list(head)
#s.print_list(s.swap_pairs(head))


#4

def remove_nth_from_end(head, n):
    fast = slow = head
    for _ in range(n):
        fast = fast.next
    if not fast:
        return head.next
    while fast.next:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return head


head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

output = remove_nth_from_end(head, 3)





class Node:
    
    def __init__(self, data, prev=NONE, next=NONE):
        self.data = data
        self.prev = prev
        self.next = next
    def __repr__(self):
        return f"{self.data}"

class DoublyLinkedList:
    def __init__(self):
        self.size = 0
        self.head = None
        self.tail = None
    def add_first(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.heat
            self.head.prev = new_node
            self.head = new_node
        self._size += 1
    def add_last(self, data):
        new_node = Node(data)
        if not self.tail:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self._size += 1
    def remove_first(self):
        if not self.head:
            return
        if self.head == self.head:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self._size -= 1
    def remove_last(self):
        if not self.tail:
            return
        if self.tail = self.head:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self._size -= 1
    def insert_before(self, node, data):
        new_node = Node(data)
        if not node.prev:
            self.head = new_node
        else:
            node.prev.next = new_node
            new_node.prev = node.prev

        new_node.next = node
        node.prev = new_node

        self._size += 1


    def insert_after(self, node, data):
        new_node = Node(data)
        if not node.next:
            new_node.prev = node
            self.tail = new_node
        else:
            new_node.prev = node
            new_node.next = node.next
            node.next.prev = new_node
        node.next = new_node
        self._size += 1


    def add_sorted(self, data):
        if not self.head:
            new_node = Node(data)
            self.head = new_node
            self.tail = new_node
            self._size += 1
        else:
            current = self.head
            while current and current.data < data:
                current = current.next
            if not current:
                self.add_last(data)
            else:
                self.insert_before(current, data)
    def display(self):
        current = self.head
        while current:
            print(str(current.data), end="-->")
            current = current.next
        print(None)