
N,P,Q,X,Y = map(int,input().split())

def fib(n):
    np=int(n/P)
    nq=int(n/Q)
    if n <= 0:
        return 1
    elif np < X:
        if nq < Y:
            return 2
        else:
            return 1+fib(nq-Y)
    elif nq < Y:
        return fib(np-X) + 1
    else:
        return fib(np-X) + fib(nq-Y)

print(fib(N))