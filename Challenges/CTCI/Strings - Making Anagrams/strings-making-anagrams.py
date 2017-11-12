def number_needed(a, b):
    symbols = {}
    for s in a:
        if not s in symbols:
            symbols[s] = 0
        symbols[s] += 1
    for s in b:
        if not s in symbols:
            symbols[s] = 0
        symbols[s] -= 1
    return sum([abs(v) for k, v in symbols])


a = input().strip()
b = input().strip()

print(number_needed(a, b))
