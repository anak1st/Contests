from fractions import Fraction
a=input().split(".")[1]
n=int(input())
r=(Fraction(int(a),10**len(a))-Fraction(1,10**100)).limit_denominator(n)
print(r.numerator,r.denominator)
