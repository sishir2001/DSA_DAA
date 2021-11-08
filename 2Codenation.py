import math
class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
    # @return a list of integers
    def __init__(self):
        self.listofSubarrays = []
        self.startIndex = 0
    # A function for listing all the subarrays 
    def subArr(self,arr,l,h):
        if l<=h:
            pl = [arr[x] for x in range(l,h+1)]
            print(f"sub: {pl}")
            self.listofSubarrays.append(pl)
            if l==self.startIndex:
                self.subArr(arr,l,h-1)
            self.subArr(arr,l+1,h)
    
    def calculateMysticalEnergy(self,arr):
        energy = 0
        for j in range(len(arr)):
            if j%2 == 0:
                energy += arr[j]
            else :
                energy -= arr[j]
        return energy
            
    def solve(self, A, B):
        returnArray = [] # to return the result 
        for i in B :
            if i[0] == 1: # replacement
                A[i[1]-1] = i[2] # query 1
             
            elif i[0] == 2 : # query 2
                # giving indexes to subarrays 
                self.startIndex = i[1]-1
                self.subArr(A,i[1]-1,i[2]-1)
                print(f"listofSub : {self.listofSubarrays}")
                maxMysticalEnergy = - math.inf
                # with above function , all the subarrays are stored in self.listofSubarrays
                for k in self.listofSubarrays :
                    
                    calEnergy = self.calculateMysticalEnergy(k)
                    print(f"Subarray : {k} and calene: {calEnergy}")
                    if calEnergy > maxMysticalEnergy :
                        maxMysticalEnergy = calEnergy
                print(f"maxMysticalEnergy : {maxMysticalEnergy}")
                returnArray.append(maxMysticalEnergy%1000000007)
                self.listofSubarrays = [] # again making the subarray list empty
        return returnArray

s = Solution()
A = [70,-68,41,42,17,-56,89,-27,-23,-17]
B = [[2,1,10],[2,2,5],[2,7,9],[2,8,9]]
print(f"res = {s.solve(A,B)}")
