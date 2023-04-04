if __name__ == "__main__":
    while True:
        arr = input()
        if arr == ".":
            break
        res = []
        for i in arr:
            if (i == '(') or (i == '['):
                res.append(i)
            elif (i == ')') or (i == ']'):
                if len(res) == 0 or \
                        ((res[-1] == '(') and (i != ')')) or\
                        ((res[-1] == '[') and (i != ']')):
                    print("no")
                    break
                res.pop()
        else:
            if len(res) == 0:
                print("yes")
            else:
                print("no")