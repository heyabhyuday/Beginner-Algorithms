import string
import random
    
def LCS(A, B, a, b): 
    if a == 0 or b == 0: 
        return 0
    elif A[a-1] == B[b-1]: 
        return 1 + LCS(A, B, a-1, b-1) 
    else: 
        return max(LCS(A, B, a, b-1), LCS(A, B, a-1, b)) 


# s1 = 'stone'
# s1 = int(input('Enter string 1: '))
nums = [x for x in range(20)]
N1 = random.choice(nums)
s1 = ''.join(random.choices(string.ascii_uppercase, k=N1))
sl1 = len(s1)
# s2 = 'longest'
# s2 = int(input('Enter string 2: '))
N2 = random.choice(nums)
s2 = ''.join(random.choices(string.ascii_uppercase, k=N2))
sl2 = len(s2)
print(LCS(s1, s2, sl1, sl2))


