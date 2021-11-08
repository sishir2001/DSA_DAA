# doubly Linked List 
class Node :
    def __init__(self,data):
        self.data = data
        self.next = None
        self.previous = None

class doublyLL:
    def __init__(self,data):
        self.head = Node(data)
        self.tail = self.head
        self.count = 1

    def appendLL(self,data):
        newNode = Node(data)
        self.tail.next = newNode
        newNode.previous = self.tail
        self.tail = newNode # updating the tail pointer
        self.count += 1

    def insertAtBegin(self,data):
        newNode = Node(data)
        newNode.next = self.head
        self.head.previous = newNode
        self.head = newNode # updating the head pointer 
        self.count += 1

    def printLL(self):
        curr = self.head
        while curr != self.tail :
            print(curr.data,end=" ")
            curr = curr.next
        print(curr.data)

    def insertAt(self,data,pos):
        if pos >=1 and pos <= self.count :
            if pos == 1:
                # inserting at head
                self.insertAtBegin(data)
            else :
                newNode = Node(data)
                currCount = 2
                curr = self.head.next
                while curr :
                    if pos == currCount :
                        prev = curr.previous
                        newNode.next = curr
                        newNode.previous = prev
                        prev.next = newNode
                        curr.previous = newNode
                        self.count += 1
                        break

                    curr = curr.next
                    currCount += 1

    def deleteAtBegin(self):
        if self.count > 0:
            curr = self.head
            self.head = self.head.next
            curr.next = None
            self.head.previous = None
            del curr
            self.count -= 1
    def deleteAtEnd(self):
        if self.count > 0:
            curr = self.tail
            self.tail = self.tail.previous
            self.tail.next = None
            curr.previous = None
            del curr
            self.count -= 1
    def deleteAt(self,pos):
        # indexing in LL starts from 1
        if self.count > 0 and pos > 0 and pos <= self.count :
            if pos == 0:
                self.deleteAtBegin()
            elif pos == self.count:
                self.deleteAtEnd()
            else :
                currPos = 2
                curr = self.head.next
                while curr.next :
                    if pos == currPos :
                        prev = curr.previous
                        prev.next = curr.next
                        curr.next.previous = prev
                        curr.next = None
                        curr.previous = None
                        del curr
                        self.count -= 1
                        break
                    curr = curr.next
                    currPos +=1

    def reverseLL(self):
        revCurr = self.tail
        revHead = doublyLL(revCurr.data)
        revCurr = revCurr.previous
        while revCurr:
            revHead.appendLL(revCurr.data)
            revCurr = revCurr.previous
        return revHead

# main 

head = doublyLL(1)
head.appendLL(2)
head.appendLL(3)
head.appendLL(4)
head.appendLL(5)
head.appendLL(6)
head.insertAtBegin(0)
head.printLL()
print(f"Deleting begins ")
head.deleteAtBegin()
head.deleteAtEnd()
head.printLL()
print(f" No of node in LL : {head.count}")
head.deleteAt(4)
print(f"deleted node at pos 4")
head.printLL()
print(f" No of node in LL : {head.count}")
print(f"Reverse of a Linked List :")
revHead = head.reverseLL()
revHead.printLL()
