# practice of linked list - DSA 
class Node:
    def __init__(self,k):
        self.key = k
        self.next = None

    def appendList(self,k):
        newNode = Node(k)
        currHead = self
        #traversing through the linked list
        while currHead.next :
            currHead = currHead.next
        currHead.next = newNode

    def printList(self):
        currHead = self
        while currHead:
            print(currHead.key,end = " ")
            currHead = currHead.next 
        print()


    def deleteLastNode(self):
        currNode = self
        prevNode = None
        while currNode.next :
            prevNode = currNode
            currNode = currNode.next
        prevNode.next = None
        print(f"Successfuly Deleted {currNode.key}")
        del currNode
    # search function , returns position of the key if present in LL or -1 . Positions starts from 1
    def search(self,searchKey):
        position = 1
        currNode = self
        while currNode :
            if currNode.key == searchKey :
                return position
            currNode = currNode.next
            position += 1

        if currNode == None :
            return -1
    
    # inserting a node at the begining of the list
    def insertAtBegin(self,k):
        currNode = self
        newNode = Node(k)
        newNode.next = currNode
        return newNode
    # deleting a node at the begining of the list
    def deleteAtBegin(self):
        currNode = self
        nextNode = currNode.next
        print(f"Successfuly deleted {currNode.key}")
        del currNode
        return nextNode
    # inserting a node at given position . 
    # if position is greater than the length of the LL , then insert at the last 
    # position starting from 1 
    def insertAtPos(self,key,pos):
        currHead = self
        if pos < 1 :
           print("Position < 1 , Position starts from 1")
           return currHead

        elif pos == 1 :

            # insert before head
            return self.insertAtBegin(key)

        lisPos = 2
        prev = self
        curr = prev.next
        if curr == None :
            # LL had only one node 
            newNode = Node(key)
            prev.next = newNode
            return prev
        while curr.next :
            if pos == lisPos :
                newNode = Node(key)
                newNode.next = curr
                prev.next = newNode
                break
            prev = curr
            curr = curr.next
            lisPos += 1

        if pos == lisPos :
            # inserting node at the last position 
            newNode = Node(key)
            newNode.next = curr
            prev.next = newNode
        elif pos > lisPos :
            newNode = Node(key)
            curr.next = newNode
            # appending at the last 
        return currHead
    
                    
        
    def sortedInsert(self,k):
        # insert according to ascending order
        currHead = self
        curr = currHead
        prev = None
        while curr :
            if k <= curr.key:
                newNode = Node(k)
                newNode.next = curr
                if prev == None:
                    return newNode
                prev.next = newNode
                break
            prev = curr
            curr = curr.next
        if curr == None :
            # given key greater than every key in LL 
            newNode = Node(k)
            prev.next = newNode 
            # inserting newNode at the last 
        return currHead

    def iReverseLL(self):
        currHead = self
        reverse = None
        prev = None
        while currHead :
            reverse = currHead
            currHead = currHead.next
            reverse.next = prev
            prev = reverse
        return reverse

    def rReverseLL(self,head):
        if head.next == None:
            return head
        rHead = self.rReverseLL(head.next)
        curr = head 
        # next node : nex
        nex = curr.next
        nex.next = curr
        curr.next = None
        return rHead
#main
head = Node(10)
head.appendList(20)
head.appendList(30)
head.appendList(40)
head.appendList(50)
head.appendList(60)
head.printList()
head.deleteLastNode()
head.printList()
print(head.search(80))
print(head.search(20))
print("Inserting a new node at the begining")
head = head.insertAtBegin(0)
head.printList()
print("Deleting a node at the begining")
head = head.deleteAtBegin()
head.printList()
print("Inserting 100 at 1")
print("Inserting 90 at 3")
print("Inserting 80 at 8")
head = head.insertAtPos(100,1)
head = head.insertAtPos(90,3)
head = head.insertAtPos(80,9)
head.printList()
rHead = head.iReverseLL()
rHead.printList()

# new LL 
print()
print("New Linked List")
head1 = Node(8)
head1.printList()
head1 = head1.sortedInsert(1)
head1.printList()
head1 = head1.sortedInsert(9)
head1.printList()
head1 = head1.sortedInsert(5)
head1.printList()
rHead1 = head1.rReverseLL(head1)
rHead1.printList()
