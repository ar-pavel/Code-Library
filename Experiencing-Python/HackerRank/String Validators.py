if __name__ == '__main__':
    S = input()
    
    print(any(map(str.isalnum, S)))
    print(any(map(str.isalpha, S)))
    print(any(map(str.isdigit, S)))
    print(any(map(str.islower, S)))
    print(any(map(str.isupper, S)))

    """
    t = False
    for c in s:
        if c.isalnum():
            print("True")
            t = True;
            break
    if t==False:
        print("Fasle")

    t = False    
    for c in s:
        if c.isalpha():
            print("True")
            t = True;
            break
    if t==False:
        print("Fasle")

    t = False
    for c in s:
        if c.isdigit():
            print("True")
            t = True;
            break
    if t==False:
        print("Fasle")

    t = False
    for c in s:
        if c.isupper():
            print("True")
            t = True;
            break
    if t==False:
        print("Fasle")

    t = False
    for c in s:
        if c.islower():
            print("True")
            t = True;
            break
    if t==False:
        print("Fasle")
"""
