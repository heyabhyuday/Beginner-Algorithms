# Problem 96: Su Doku
M = 9

board1 = []
for board_i in range(9):
    board_t = [int(board_temp) for board_temp in input().strip()]
    board1.append(board_t)


def solve(board, row, col, num):
    for x in range(9):
        if board[row][x] == num:
            return False

    for x in range(9):
        if board[x][col] == num:
            return False

    startrow = row - row % 3
    startcol = col - col % 3

    for i in range(3):
        for j in range(3):
            if board[i + startrow][j + startcol] == num:
                return False
    return True


def sudoku(board, row, col):
    if row == M - 1 and col == M:
        return True

    if col == M:
        row += 1
        col = 0

    if board[row][col] > 0:
        return sudoku(board, row, col + 1)

    for num in range(1, M + 1, 1):
        if solve(board, row, col, num):
            board[row][col] = num

            if sudoku(board, row, col + 1):
                return True

        board[row][col] = 0
    return False


def print_board(a):
    for i in range(M):
        for j in range(M):
            print(a[i][j], end="")
        print()


if sudoku(board1, 0, 0):
    print_board(board1)
