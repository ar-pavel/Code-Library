def solve(s):   
    t=" "
    c = ""
    for i in s:       
        if t == ' ':
            c += i.upper()
        else:
            c += i
        t = i
    return c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
