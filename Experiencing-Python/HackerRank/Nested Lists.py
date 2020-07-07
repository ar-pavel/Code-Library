score = []
name = []
for _ in range(int(input())):
    name.append(input())
    score.append(float(input()))

mn = min(score)
sman = float('inf')

for i in score:
    if i<sman and i!=mn:
        sman = i    

#print(mn,sman)

lst = []

for i in range(len(score)):
    if score[i]==sman:
        lst.append(name[i])

lst.sort()

for i in lst:
    print(i)


