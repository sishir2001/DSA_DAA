class trees:
    def __init__(self,data):
        self.data = data
        self.children = []
n1 = trees(5)
n2 = trees(6)
n3 = trees(7)
n1.children.append(n2)
n1.children.append(n3)


def sumnodes(root):
    if root == None:
        return 0
    sum1 = root.data
    for child in root.children:
        sum1 = sum1 + sumnodes(child)
    return sum1


# main
print(sumnodes(n1))