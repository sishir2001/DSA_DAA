# min max problem using D and C approach

def MinMax(arr,l,h):
    # ? arr is a list of integers
    #  ? l : lower index
    #  ? h : higher index 
    # ! Base case 
    if l >= h:
        # mini = arr[l] if arr[l] < arr[h] else arr[h]
        # maxi = arr[h] if arr[h] > arr[l] else arr[l]
        # return mini,maxi
        return arr[h],arr[h]
    # ! division 
    m = (l+h)//2 # integer division 
    (minl,maxl) = MinMax(arr,l,m);
    (minr,maxr) = MinMax(arr,m+1,h);

    # ! conquer 
    mini = minl if minl < minr else minr
    maxi = maxl if maxl > maxr else maxr
    return mini,maxi


#*main 
arr = [1,2,8,4,7,6,7]
print(f"min , max : {MinMax(arr,0,len(arr)-1)}")



