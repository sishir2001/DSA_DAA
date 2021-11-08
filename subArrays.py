# program to find all the subarrays of a given array 
class sub:
    def __init__(self):
        self.listofSubarray = []
    def subArr(self,arr,l,h):
        if l<=h:
            pl = [arr[x] for x in range(l,h+1)]
            print(pl)
            self.listofSubarray.append(pl)
            if l==0:
                self.subArr(arr,l,h-1)
            self.subArr(arr,l+1,h)
    def getSubArrays(self):
        return self.listofSubarray


#main
arr = [-68,41,42,7]
s = sub()
s.subArr(arr,0,len(arr)-1)
print(s.getSubArrays())
