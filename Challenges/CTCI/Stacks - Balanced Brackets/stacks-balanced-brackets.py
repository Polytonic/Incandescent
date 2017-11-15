def is_matched(expression):

    if (len(expression) % 2 != 0):
        return False

    stack = []
    for symbol in expression:
        if   symbol == "{": stack.append("}")
        elif symbol == "[": stack.append("]")
        elif symbol == "(": stack.append(")")
        elif len(stack) == 0 or symbol != stack[-1]:
            return False
        else:
            stack.pop()

    return len(stack) == 0

t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
