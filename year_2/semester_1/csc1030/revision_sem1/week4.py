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
        if (self.is_empty()):
            return
        temp = self.item[-1]
        self.deque()
        self.reverse()
        self.enqueue(temp)

    def _push_to_last(self, q_size):
        if q_size <= 0:
            return
        self.items.append(self.items.pop(0))
        self._push_to_last(q_size-1)


    def _enqueue_conditioned(self, temp, q_size):
        if self.is_empty() or q_size == 0:
            self.items.append(temp)
            return
        elif temp < self.items[0]:
            self.items.append(temp)
            self.items._push_to_last(q_size)
        else:
            self.items.append(self.items.pop(0))
            self.items._enqueue_conditioned(temp, q_size-1)

    def sort(self):
        if self.is_empty():
            return
        temp = self.items[0]
        self.sort()
        self._enqueue_conditioned(temp, self.size())
    def reverse(self):
        if (self.is_empty()):
            return
        temp = self.items[-1]
        self.dequeue()
        self.reverse()
        self.enqueue(temp)

    def reverse_k_element(self, k):
        temp = Queue()
        to_be_reversed = self.items[0:k]
        temp.items = to_be_reversed
        temp.reverse()
        temp.items.extend(self.size()):
        for _ in range(self,size()):
            self.dequeue()
            self.enqueue(temp.dequeue())

if __name__ == '__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(q.size())
    print(q.is_empty())
    print(q.size())
    q.reverse()

def generate_binary_nums(n):
    q = Queue()
    q.enqueue(1)
    result = []
    for _ in range(n):
        curr = q.dequeue()
        result.append(curr)
        q.enqueue(curr + '0')
        q.enqueue(curr + '1')
    return result


lass Stack:
    '''Python implementation the stack'''

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[-1]

    def size(self):
        return len(self.items)




def evaluate_postfix(formula):
    OPERATORS = set(['+', '-', '*', '/', '(', ')', '^'])
    c = {'+': a + b, '-': a - b, '*': a * b, '/': a / b, '^': a ** b}
    stack = STACK()
    for ch in formula:
        if ch not in OPERATORS:
            stack.push(float(ch))
        else:
            b = stack.pop()
            a = stack.pop()
            c[ch]
            stack.push(c)
    return stack.pop()



exp = "1432^*+147--+"
obj = evaluate_postfix(exp)
print("\nPostfix evaluation: %d" % obj)
