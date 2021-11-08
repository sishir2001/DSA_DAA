# practice code for singly linked list 
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class CircularLL:
    def __init__(self,data):
        self.head = Node(data)
        self.tail = self.head
        self.count = 1

    def printLL(self):
        currStart = self.head
        currEnd = self.tail
        while currStart != currEnd :
            print(currStart.data , end="->")
            currStart = currStart.next
        print(currStart.data)

    def appendLL(self,data):
        # time complexity : O(1) as we maintain a tail referrence
        newNode = Node(data)
        self.tail.next = newNode
        newNode.next = self.head
        self.tail = newNode #updating the self.tail
        self.count += 1

    def insertAtBegin(self,data):
        # time complexity : O(1) as we maintain a tail referrence
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode # updating the self.head 
        self.tail.next = self.head
        self.count += 1
    def insertAt(self,data,pos):
        # indexing of LL starting from 1
        if pos >= 1 and pos <= self.count :
            if pos == 1:
                self.insertAtBegin(data)
            else :
                newNode = Node(data)
                prev = self.head
                curr = prev.next
                currPos = 2
                while curr != self.head :
                    if pos == currPos :
                       newNode.next = curr
                       prev.next = newNode
                       self.count += 1
                       break
                    prev = curr
                    curr = curr.next
                    currPos += 1

    def deleteAtBegin(self):
        #time complexity : O(1)
        if self.count == 2:
            curr = self.head
            self.head = self.tail
            self.head.next = None
            curr.next = None
            del curr
        else:
            curr = self.head
            self.tail.next = curr.next
            self.head = curr.next
            curr.next = None
            del curr
        self.count -= 1

    def deleteAtEnd(self):
        # time complexity : O(n)
        if self.head == self.tail :
            # only one node 
            self.tail = None
            curr = self.head
            self.head = None
            del curr
        elif self.count == 2:
            curr = self.tail
            self.tail = self.head
            self.head.next = None
            curr.next = None
            del curr
        else:
            prev = self.head
            curr = prev.next
            while curr.next != self.head:
                prev = curr
                curr = curr.next
            prev.next = self.head
            self.tail = prev
            curr.next = None
            del curr
        
        self.count -= 1
    def deleteAt(self,pos):
        if pos >= 1 and pos <= self.count:
            if pos == 1:
                self.deleteAtBegin()
            elif pos == self.count :
                self.deleteAtEnd()
            else :
                prev = self.head
                curr = prev.next
                currPos = 2
                while curr != self.tail :
                    if pos == currPos :
                        prev.next = curr.next
                        curr.next = None
                        del curr
                        self.count -= 1
                        break
                    prev = curr
                    curr = curr.next
                    currPos += 1
                    
            
# main 
l1 = CircularLL(1)
l1.appendLL(2)
l1.appendLL(3)
l1.printLL()
l1.insertAtBegin(0)
l1.appendLL(4)
l1.printLL()
print(l1.count)
l1.insertAt(14,5)
print(l1.count)
l1.insertAt(10,2)
print(l1.count)
l1.printLL()
l1.deleteAtBegin()
l1.printLL()
l1.deleteAtEnd()
l1.printLL()
print(l1.count)
print(f"deleting at 3")
l1.deleteAt(3)
l1.printLL()


l2 = CircularLL(1)
l2.appendLL(2)
print()
print(" L2 : ")
l2.printLL()
l2.deleteAtEnd()
l2.printLL()
print(f"{l2.head.data} , {l2.tail.data}, {l2.head.next},{l2.tail.next}")
print(l2.count)
