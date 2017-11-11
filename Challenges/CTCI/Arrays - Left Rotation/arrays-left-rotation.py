def array_left_rotation(a, n, k):

    # In Python, we can take advantage of slicing.
    # Alternately, use the deque container.
    return a[k:] + a[:k]

n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k);
print(*answer, sep=' ')
