import sys

switches = [[0, 1, 2],
            [3, 7, 9, 11],
            [4, 10, 14, 15],
            [0, 4, 5, 6, 7],
            [6, 7, 8, 10, 12],
            [0, 2, 14, 15],
            [3, 14, 15],
            [4, 5, 7, 14, 15],
            [1, 2, 3, 4, 5],
            [3, 4, 5, 9, 13]]


def are_aligned(clocks):
    all_clock_is_twelve = True
    for clock in clocks:
        if clock != 12:
            all_clock_is_twelve = False
            break
    return all_clock_is_twelve


def press_switch(clocks_modified, switch_index, pressed):
    pressed[switch_index] = (pressed[switch_index] + 1) % 4

    for clock_index in switches[switch_index]:
        clocks_modified[clock_index] += 3
        if clocks_modified[clock_index] == 15:
            clocks_modified[clock_index] = 3


def clock_sync(pressed, switch_index, clocks_modified):

    if switch_index == len(switches):
        if are_aligned(clocks_modified):
            total_pressed = 0
            for pressed_count in pressed:
                total_pressed += pressed_count
            return total_pressed
        return sys.maxsize

    min_pressed = sys.maxsize

    for count in range(4):
        min_pressed = min(min_pressed, clock_sync(pressed, switch_index + 1, clocks_modified))
        press_switch(clocks_modified, switch_index, pressed)
        print(pressed)

    return min_pressed


switch_pressed = []
for i in range(10):
    switch_pressed.append(0)
clocks = [12, 6, 6, 6, 6, 6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
clocks2 = [12, 9, 3, 12, 6, 6, 9, 3, 12, 9, 12, 9, 12, 12, 6, 6]
print(clock_sync(switch_pressed, 0, clocks))
