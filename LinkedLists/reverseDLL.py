# reversing a doubly LL 
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None
    
    def printLL(self):
        curr = self
        while curr.next:
            print(curr.data,end=" ")
            curr = curr.next
        print(curr.data)

    def appendLL(self,data):
        newNode = Node(data)
        curr = self
        while curr.next :
            curr = curr.next
        curr.next = newNode
        newNode.prev = curr
def reverseDLL(head):
    if head == None:
        return None
    curr = head
    prev = None
    while curr:
        k = curr.prev
        curr.prev = curr.next
        curr.next = k
        prev = curr
        curr = curr.prev
    return prev

#main
head = Node(1)
head.appendLL(2)
head.appendLL(3)
head.appendLL(4)
head.appendLL(5)
head.printLL()
revHead = reverseDLL(head)
revHead.printLL()
