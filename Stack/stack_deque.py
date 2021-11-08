# implementing stack using collections.deque
from collections import deque
stack = deque()
stack.append(10)
stack.append(20)
stack.append(30)
print(stack)
print("pop")
print(stack.pop())
print("top of the stack:")
print(stack[-1]) # top of the stack
print("size of the stack")
print(len(stack)) # size of the stack

