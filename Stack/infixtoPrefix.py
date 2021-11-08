# this is a program to convert infix expression to prefix expression 

def paranthesize(s):
    # s here is the string 
    operators = ["+","-","*","/","^"]
    if "(" not in s and ")" not in s :
        # TODO : traverse s to find out the operators in s 
        d  = [] # empty list for adding the operators indexs in s
        for i in range(len(s)):
            if s[i] in operators:
                d.append(i)

        # assuming only two operators will be present in the expression 
        # TODO : getting the indexes of operators in operators list 
        fi = operators.index(s[d[0]])
        si = operators.index(s[d[1]])

        openIndex = -1
        closeIndex = -1 # indexes of opening and closing brackets 
        if fi == si and fi == 4:
            # the operators are ^ 
            openIndex = d[1] - 1
            closeIndex = d[1] + 1
        elif fi == 4:
            # first operator is ^
            openIndex = 0 # append the character after the bracket
            closeIndex = 2  # append the bracket after character 
        elif si == 4:
            # second operator is ^
            openIndex = d[1] - 1 # append the character after the bracket
            closeIndex = d[1]+1  # append the bracket after character 
        elif fi%2 == 0 and si%2 == 0:
            if fi == si :
                # both have same precedence , so associativity L to R
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            elif fi > si :
                # fi has higher precedence
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            else :
                # si has higher precedence
                openIndex = d[1] - 1 # append the character after the bracket
                closeIndex = d[1]+1  # append the bracket after character 
        
        elif fi%2 == 1 and si%2 == 1:
            if fi == si :
                # both have same precedence , so associativity L to R
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            elif fi > si :
                # fi has higher precedence
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            else :
                # si has higher precedence
                openIndex = d[1] - 1 # append the character after the bracket
                closeIndex = d[1]+1  # append the bracket after character 

        elif fi%2 == 0 and si%2 == 1:
            if si - fi == 1 or fi - si == 1:
                # have same precedence or fi has higher precedence
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            else :
                # si has high precedence
                openIndex = d[1] - 1 # append the character after the bracket
                closeIndex = d[1]+1  # append the bracket after character 
                
        elif fi%2 == 1 and si%2 == 0:
            if fi - si == 1 :
                openIndex = 0 # append the character after the bracket
                closeIndex = 2  # append the bracket after character 
            else :
                openIndex = d[1] - 1 # append the character after the bracket
                closeIndex = d[1]+1  # append the bracket after character 
        # adding the paranthesis now :
        s1 = ""
        for i in range(len(s)):
            if i == openIndex:
                s1 = s1 + "(" + s[i]
            elif i == closeIndex :
                s1 = s1 + s[i] + ")"
            else :
                s1 += s[i]
        s = s1
    # now adding the last parenthesis
    s = "(" + s + ")"
    return s

def infixtoPrefix(s):
    # time complexity - O(n)
    s = paranthesize(s) # the string is fully paranthesized # O(n) -> timecomplexity 
    # TODO : push characters to stack till ) is encountered 
    stack = [] # list based stack 
    for i in range(len(s)):
        if s[i] == "(":
            continue
        elif s[i] == ")":
            t1 = stack.pop()
            t2 = stack.pop()
            t3 = stack.pop()
            s1 = t2 + t3 + t1
            stack.append(s1)
        else:
            stack.append(s[i])
    # if the algo is correct then stack should contain the postfix expression 
    return stack.pop()

#main
l = ["a*b+c","(a+b)*c","a^b^c","(a+b)*(c+d)","a*b^c","a^b*c"]
for i in l:
    print(f" {i} : {paranthesize(i)} ")
    print(f" {i} : {infixtoPrefix(i)} ")



                

