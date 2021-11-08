# implementing stack using list 

class Stack:
    def __init__(self):
        self.l = []
        self.lastIndex = -1
    def push(self,x):
        self.lastIndex += 1
        self.l.append(x)
    def isEmpty(self):
        if self.lastIndex == -1:
            return True
        else:
            return False

    def pop(self):
        # check if the list isnt empty 
        if self.isEmpty() == False:
            self.lastIndex -= 1
            x = self.l.pop()
            return x
        return None # if the list is empty
    def peek(self):
        if self.isEmpty() == False:
            return self.l[self.lastIndex]
        else:
            return None # if the list is empty
            
    def getSize(self):
        return self.lastIndex + 1

        
#main

s = Stack()
s.push(1)
s.push(2)
s.push(3)
print(s.peek())
print(s.lastIndex)
print(s.l)
s.push(4)
print(s.l)
print(s.getSize())
print(s.pop())
print(s.l)
print(s.pop())
print(s.l)
print(s.pop())
print(s.l)
print(s.pop())
print(s.l)
print(s.pop())
