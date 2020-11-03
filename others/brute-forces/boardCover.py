import sys

max_white_board = 50
'''
board_height = 8
board_width = 10
board_str = ["##########",
             "#........#",
             "#........#",
             "#........#",
             "#........#",
             "#........#",
             "#........#",
             "##########"]
'''
board_height = 3
board_width = 5
board_str = ["#..##",
             "#.#.#",
             "##..#"]
black = True
white = False


def make_board_from(board_str):
    if len(board_str) == 0:
        return None

    height = len(board_str)
    width = len(board_str[0])

    my_board = [[False for i in range(width)] for i in range(height)]

    for i in range(height):
        board_line = board_str[i]
        for j in range(width):
            if board_line[j] == "#":
                my_board[i][j] = black
            else:
                my_board[i][j] = white

    return my_board


first_L = [[0, 0], [1, 0], [1, 1]]
second_L = [[0, 0], [0, 1], [1, 1]]
third_L = [[0, 0], [1, 0], [0, 1]]
fourth_L = [[0, 0], [0, 1], [-1, 1]]

block_L = [first_L, second_L, third_L, fourth_L]


def count_remain_white_blocks(my_board, width, height):
    remain_count = 0
    for i in range(height):
        for j in range(width):
            if my_board[i][j] == white:
                remain_count += 1

    return remain_count


def can_cover_with_l(my_board, width, height, x, y, L_block):
    for (delta_x, delta_y) in L_block:
        new_x = x + delta_x
        new_y = y + delta_y
        if new_x >= width or new_y >= height:
            return False

        if my_board[new_y][new_x] == black:
            return False

    return True


def cover_with_l(board, x, y, L_block, white_or_black):
    for (delta_x, delta_y) in L_block:
        new_x = x + delta_x
        new_y = y + delta_y
        board[new_y][new_x] = white_or_black


def find_first_white_cell_in_board(board, width, height):
    for i in range(height):
        for j in range(width):
            if board[i][j] == white:
                return j, i

    return -1, -1


def board_cover(board, width, height):
    # basis condition
    # number of white blocks should be multiplied by 3
    # can't cover current L block

    '''
    remain_count = count_remain_white_blocks(board, width, height)
    if remain_count == 0:
        return 1

    if remain_count % 3 != 0:
        return 0
    '''

    x, y = find_first_white_cell_in_board(board, width, height)
    if x == -1:
        return 1

    number_of_cover_combination = 0

    for i in range(4):
        L_block = block_L[i]
        if can_cover_with_l(board, width, height, x, y, L_block):
            cover_with_l(board, x, y, L_block, black)
            number_of_cover_combination += board_cover(board, width, height)
            cover_with_l(board, x, y, L_block, white)

    return number_of_cover_combination


board = make_board_from(board_str)
ret = board_cover(board, board_width, board_height)
print("# of covers : " + str(ret))
