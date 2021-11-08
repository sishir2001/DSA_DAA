# using lumuto's partition .
def partitionL(arr,l,h):
    # ! selecting the last element as pivot 
    pivot = arr[h]
    i = l-1
    for j in range(l,h):
        if arr[j] < pivot:
            i += 1
            arr[i],arr[j] = arr[j],arr[i] # switching the places 

    i+=1
    arr[i],arr[h] = arr[h],arr[i]
    return i

def quickSortL(arr,l,h):
    if l < h:
        # above is the base condition 
        q = partitionL(arr,l,h)
        quickSortL(arr,l,q-1)
        quickSortL(arr,q+1,h)


# main 
arr = [1,5,2,3,6,6,4]
quickSortL(arr,0,len(arr)-1)
print(arr)
