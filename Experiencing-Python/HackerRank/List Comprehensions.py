a = int(input())
b = int(input())
c = int(input())
n = int(input())

ComprehensionedList = [[i,j,k] for i in range(a+1) for j in range(b+1) for k in range(c+1) if i+j+k != n]

print (ComprehensionedList )
