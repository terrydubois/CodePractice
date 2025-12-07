'''
LeetCode 51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Example 2
Input: n = 1
Output: [["Q"]]

'''

def is_safe(board, row, col):

    # check for queens for each cell in this col (vertically)
    for i in range(row):
        if board[i][col] == 'Q':
            return False

    # check for queens diagonally, going down-left
    row_check = row
    col_check = col
    while row_check < len(board) and col_check >= 0:
        if board[row_check][col_check] == 'Q':
            return False
        row_check += 1
        col_check -= 1

    # check for queens diagonally, going up-right
    row_check = row
    col_check = col
    while row_check >= 0 and col_check < len(board):
        if board[row_check][col_check] == 'Q':
            return False
        row_check -= 1
        col_check += 1

    # check for queens diagonally, going up-left
    row_check = row
    col_check = col
    while row_check >= 0 and col_check >= 0:
        if board[row_check][col_check] == 'Q':
            return False
        row_check -= 1
        col_check -= 1

    # check for queens diagonally, going down-right
    row_check = row
    col_check = col
    while row_check < len(board) and col_check < len(board):
        if board[row_check][col_check] == 'Q':
            return False
        row_check += 1
        col_check += 1

    return True



def solve_n_queens(n: int) -> list[list[str]]:

    # make a sample board
    board = [['.' for _ in range(n)] for _ in range(n)]
    board[0][1] = 'Q'

    show_attacked_cells(board)

    return board

def show_attacked_cells(board: list[list[str]]):

    # loop through board and make all attacked cells an X
    for row_index in range(len(board)):
        row = board[row_index]
        for col_index in range(len(row)):
            cell = row[col_index]
            if cell == 'Q':

                # mark entire row as attacked
                for k in range(len(board)):
                    if k != col_index:
                        row[k] = 'X'

                # mark entire column as attacked
                for k in range(len(board)):
                    if k != row_index:
                        board[k][col_index] = 'X'
                
                # mark diagonal as attacked (down-right)
                row_diag_index = row_index + 1
                col_diag_index = col_index + 1
                while row_diag_index < len(board) and col_diag_index < len(board):
                    board[row_diag_index][col_diag_index] = 'X'
                    row_diag_index += 1
                    col_diag_index += 1

                # mark diagonal as attacked (down-left)
                row_diag_index = row_index + 1
                col_diag_index = col_index - 1
                while row_diag_index < len(board) and col_diag_index >= 0:
                    board[row_diag_index][col_diag_index] = 'X'
                    row_diag_index += 1
                    col_diag_index -= 1

                # mark diagonal as attacked (up-right)
                row_diag_index = row_index - 1
                col_diag_index = col_index + 1
                while row_diag_index >= 0 and col_diag_index < len(board):
                    board[row_diag_index][col_diag_index] = 'X'
                    row_diag_index -= 1
                    col_diag_index += 1

                # mark diagonal as attacked (up-left)
                row_diag_index = row_index - 1
                col_diag_index = col_index - 1
                while row_diag_index >= 0 and col_diag_index >= 0:
                    board[row_diag_index][col_diag_index] = 'X'
                    row_diag_index -= 1
                    col_diag_index -= 1

                    
                

def print_board(board: list[list[str]]):
    for row in board:
        print(' '.join(map(str, row)))
    


if __name__ == "__main__":
    input = 4
    output = solve_n_queens(input)
    print_board(output)
