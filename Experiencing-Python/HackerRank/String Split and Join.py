def split_and_join(line):
    s=""
    s= line.split(" ")
    s = "-".join(s)
    return s

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
