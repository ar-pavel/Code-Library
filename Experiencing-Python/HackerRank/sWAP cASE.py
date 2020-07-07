def swap_case(s):
    #print(s)
    a = ""
    for c in s:
        if c.isupper():
            a += c.lower()
        elif c.islower():
            a += c.upper()
        else: 
            a += c
    
    return a
 
