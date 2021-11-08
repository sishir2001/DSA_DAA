# x^n = x^n/2 * x^n/2
def exp(x,n):
    if n == 0:
        return 1
    elif n == 1:
        return x
    if n%2 == 0:
        return exp(x,n//2) * exp(x,n//2)
    elif n%2 == 1:
        return x * exp(x,n-1)
    
    
#main 
x = 2
n = 3
print(exp(x,n))