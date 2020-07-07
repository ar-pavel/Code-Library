if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    mx = max(arr)
    p=-200
    for i in arr:
        if i<mx and i>p:
            p = i
            
    print(p)
