board1 = []
for board_i in range(9):
    board_t = [int(board_temp) for board_temp in input().strip()]
    board1.append(board_t)


def find_empty_location(board, l):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                l[0] = row
                l[1] = col
                return True
    return False


def checkrow(board, row, num):
    for i in range(9):
        if board[row][i] == num:
            return False
    return True


def checkcol(board, col, num):
    for i in range(9):
        if board[i][col] == num:
            return False
    return True


def checkbox(board, row, col, num):
    row -= row % 3
    col -= col % 3
    for i in range(3):
        for j in range(3):
            if board[i + row][j + col] == num:
                return False
    return True


def isSafe(board, row, col, num):
    return checkrow(board, row, num) and (checkcol(board, col, num) and checkbox(board, row, col, num))


def solve_sudoku(board):
    l = [0, 0]
    if not find_empty_location(board, l):
        return True

    row = l[0]
    col = l[1]

    for num in range(1, 10):
        if isSafe(board, row, col, num):
            board[row][col] = num

            if solve_sudoku(board):
                return True

            board[row][col] = 0
    return False


def print_grid(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end=" "),
        print()


if solve_sudoku(board1):
    print_grid(board1)
