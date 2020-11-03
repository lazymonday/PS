import sys

num_of_member = 4
num_of_pair = 6

# pair = '0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5'
pair = '0 1 1 2 2 3 3 0 0 2 1 3'


def pair_to_array(pair_str):
    are_friends = [[False for i in range(num_of_member)] for i in range(num_of_member)]
    split_str = pair.split(' ')
    for i in range(0, len(split_str), 2):
        if i < len(split_str) - 1:
            are_friends[int(split_str[i])][int(split_str[i+1])] = True
            are_friends[int(split_str[i+1])][int(split_str[i])] = True

    return are_friends


def find_first_member(taken):
    for idx in range(len(taken)):
        if not taken[idx]:
            return idx
    return -1


def count_pairings(member_count, are_they_friends, is_taken):
    first_member_not_taken = find_first_member(is_taken)
    if first_member_not_taken == -1:
        return 1

    ret = 0

    for index in range(first_member_not_taken + 1, member_count):
        if is_taken[first_member_not_taken] == False and \
                is_taken[index] == False and \
                are_they_friends[first_member_not_taken][index]:
            is_taken[index] = is_taken[first_member_not_taken] = True
            ret += count_pairings(member_count, are_they_friends, is_taken)
            is_taken[index] = is_taken[first_member_not_taken] = False

    return ret


taken = [False for i in range(num_of_member)]
are_friends = pair_to_array(pair)
num_of_pair = count_pairings(num_of_member, are_friends, taken)
print('Number of pairs : ' + str(num_of_pair))