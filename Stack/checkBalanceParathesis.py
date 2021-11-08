# check if the string of brackets is balanced or not 
# data structures used : list and stack 

# stack based on list 
class Stack:
    def __init__(self):
        self.l = []
        self.lastIndex = -1 # useful for size and isEmpty 
    def push(self,x):
        self.l.append(x)
        self.lastIndex += 1
    def isEmpty(self):
        if self.lastIndex == -1:
            return True
        return False
    def pop(self):
        # check if the stack is empty 
        if self.isEmpty() == True:
            return None # none for stackunderflow 
        value = self.l.pop()
        self.lastIndex -= 1 # index decreasing 
        return value
    def peek(self):
        if self.isEmpty() == True:
            return None # none for stackunderflow 
        return self.l[self.lastIndex]

def checkBalancePar(s):
    # s is the string of brackets
    # TODO : make two lists of opening and closing brackets
    opening = ["(","{","["]
    closing = [")","}","]"]
    
    # TODO : create a stack .
    # TODO : parse the string and add only opening characters to stack
    # TODO : when encountered closing characters compare it with the top of the stack .
    
    st = Stack()
    
    for i in s:
        if i in opening:
            st.push(i)
        elif i in closing:
            # TODO : get the index of i in closing 
            closeIndex = closing.index(i) 
            # TODO : peek the stack and get that index to comapare 
            openChar = st.peek() 
            # checking whether st was empty 
            if openChar == None:
                return False 

            openIndex = opening.index(openChar)
            if closeIndex == openIndex :
                st.pop()
            else:
                return False # closing and opening do not match
        # TODO : stack empty -> True else False
        else:
            # not a valid character 
            return False
    return st.isEmpty()
#main
p = ["{{{}}}","[[[]]]","(())","}{","((())","([)]","{}([()])"]
for x in p:
    print(f" {x} : {checkBalancePar(x)} ")
