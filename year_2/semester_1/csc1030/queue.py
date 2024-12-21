#!/usr/bin/env python3

class Queue:
    def __init__(self):
        self.items = []
    def is_empty(self):
        return self.items == []
    def enqueue(self, item):
        self.items.insert(0, item)
    def dequeue(self):
        return self.items.pop()
    def size(self):
        return len(self.items)
    def reverse(self):
        if self.is_empty():
            return
        temp = self.items[-1]
        self.dequeue()
        self.reverse()
        self.enqueue(temp)
    def reverse_kth_element(self, k):
        tmp = Queue()
        items_to_be_reversed = self.items[0:k]
        tmp.items = items_to_be_reversed
        tmp.reverse()
        tmp.extend(self.items[k:])
        for _ in range(self.size()):
            self.dequeue()
            self.enqueue(tmp.dequeue())
    def push_to_last(self, q_size):
        if q_size <= 0:
            return
        self.items.append(self.items.pop(0))
        self.push_to_last(q_size-1)

    def enqueue_conditioned(self, temp, q_size):
        if self.is_empty() or q_size == 0:
            self.items.append(temp)
        elif temp <= self.items[0]:
            self.items.append(temp)
            self.push_to_last(q_size)
        else:
            self.items.append(self.items.pop(0))
            self.enqueue_conditioned(temp, q_size - 1)
    
    
    
    def sort_queue(self):
        if self.is_empty():
            return
        temp = self.items.pop(0)
        self.sort_queue()
        self.enqueue_conditioned(temp, self.size())     

def generate_binary_numbers(n):
    q = queue()
    q.enqueue('1')
    result = []
    for _ in range(n):
        curr = q.dequeue()
        result.append(curr)
        q.enqueue('0')
        q.enqueue('1')
    return result

class Stack:
    def __init__(self):
        self.items = []
    def __str__(self):
        ans = ""
        for i in range(self.size()):
            ans += self.items[i]
        return ans
    def is_empty(self):
        return self.items == []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def top(self):
        return self.items[len(self.items)-1]
    def size(self):
        return len(self.items)
if __name__ == '__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6)
    #print(q.size())
    #print(q.is_empty())
    #print(q.size())
    #print(q.items)
    #q.reverse_kth_element(4)
    #print(q.items)
    s = Stack()
    output = []
    sequence = 'EAS*Y*QUE***ST***IO*N***'
    for i in sequence:
        if i != "*":
            s.push(i)
        else:
            output.append(s.pop())
    #print(output)

    s = Queue()
    sequence = 'EAS*Y*QUE***ST***IO*N***'
    for i in sequence:
        if i != "*":
            s.enqueue(i)
        else:
            output.append(s.dequeue())
    print(output)

    def reverse(input):
        n = len(input)
        stack = Stack()

        for i in range(0, n, 1):
            stack.push(input[i])
        input = ""
        for i in range(0, n, 1):
            input += stack.pop()
        return input
    
    def evaluate_postfix(formula):
        OPERATORS = set(['+', '-', '*', '/', '(', ')', '^'])
        stack = Stack()
        for ch in formula:
            if ch not in OPERATORS:
                stack.push(float(ch))
            else:
                b = stack.pop()
                a = stack.pop()
                c = {'+': a+b, '-':a-b}[ch]
                stack.push(c)
        return stack.pop()





