# recursive implementation
def binpow(a, b):
    if b == 0:
        return 1
    res = binpow(a, b//2)
    if b % 2:
        return res * res * a
    else:
        return res * res
    
# non-recursive implementation
def binpow2(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res = res * a
        a *= a
        b >>= 1
    return res

# modulo does not interfere with multiplication


a, b = [int(x) for x in input('').split(' ')]
print(binpow(a, b))
print(binpow2(a, b))