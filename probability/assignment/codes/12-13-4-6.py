from math import comb

dist=[]
p = 1/5
q = 4/5
flRange = range(5)

for i in flRange:
    val = comb(4,i)*(p**i)*(q**(4-i))
    dist.append(round(val,4))

print(dist)
