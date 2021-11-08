 #implementing stack using single LL .
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
        self.size = 0
        # initial values .

    def push(self,x):
        # adding a node at the head
        newNode = Node(x)
        newNode.next = self.head
        self.head = newNode # updating the node , this will work even if the head == None
        self.size += 1

    def isEmpty(self):
        if self.head == None:
            return True
        return False

    def pop(self):
        if self.isEmpty() == False :
            curr = self.head
            self.head = self.head.next
            curr.next = None
            value = curr.data
            del curr
            self.size -= 1
            return value
        return None

    def peek(self):
        if self.isEmpty() == False:
            return self.head.data
        return None
    def getSize(self):
        return self.size

# main
s = Stack() 
s.push(10)
s.push(20)
s.push(30)
print("peek:")
print(s.peek())
print("pop:")
print(s.pop())
print(s.peek())
print("size:")
print(s.getSize())

