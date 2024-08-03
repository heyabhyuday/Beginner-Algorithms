import sys

def MCM(p):
    n = len(p)
    table = [[0 for x in range(n)] for y in range(n)]

    for chainlen in range(2, n):
        for i in range(1, n - chainlen + 1):
            j = i + chainlen - 1
            table[i][j] = sys.maxsize
            for k in range(i, j):
                cost = table[i][k] + table[k + 1][j] + p[i - 1] * p[k] * p[j]
                if cost < table[i][j]:
                    table[i][j] = cost
    # To view the table, uncomment following two lines and run
    # for row in table[:-1]:
    #     print(row)
    return table[1][n-1]

test1 = [1, 2, 3, 4, 5]
print(str(MCM(test1)))
