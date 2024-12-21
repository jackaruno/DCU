#!/usr/bin/env python3
#1
def sum_q1(n):
    if n <= 1:
        return n
    else:
        ans = sum_q1(n-1)
    return n + ans

#print(sum_q1(6))
#2
def rev(i, n=0):
    if i == 0:
        return n
    else:
        n = n * 10 + i % 10
        return rev(i//10, n)
#print(rev(1234))
#3
def rev_str(s):
    if len(s) == 1:
        return s[0]
    return rev_str(s[1:]) + s[0]

#print(rev_str("abcdef"))

#4
def rev_list(l):
    if len(l) == 0:
        return []
    elif len(l) == 1:
        return l
    return [l[len(l) - 1]] + rev_list(l[:len(l)-1])
    
#print(rev_list([1,2,3,4]))

def multiply(x, y):
    if x == 0:
        return 0
    if x < 0:
        return -(x - multiply(y+1, x))
    return y + multiply(x-1, y) 

#print(multiply(3,10))
#print(multiply(-2,10))

def is_heteromecic(n, temp=0):
    if n == temp*(temp+1):
        return True
    elif n < (temp * (temp+1)):
        return False
    return is_heteromecic(n, temp+1)


print(is_heteromecic(30))

#7
def length(s):
    if len(s) == 1:
        return 1
    return length(s[:-1]) + 1
print(length("slfjdk"))