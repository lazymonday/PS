import sys

fences = [7, 1, 5, 9, 6, 7, 3]
# fences = [1, 4, 4, 4, 4, 1, 1]
# fences = [1, 8, 2, 2]


def find_cross_maximum_fence(fences, low, mid, high):
    min_height = fences[mid]
    max_area = min_height

    lo = mid
    hi = mid

    while lo > low or hi < high:
        if hi < high and (lo == low or fences[lo - 1] < fences[hi + 1]):
            hi += 1
            min_height = min(min_height, fences[hi])
        else:
            lo -= 1
            min_height = min(min_height, fences[lo])

        max_area = max(min_height * (hi - lo + 1), max_area)

    return max_area


def find_maximum_fence(fences, low, high):
    if high <= low:
        return fences[low]  # area
    else:
        mid = int((high + low) / 2)
        left = find_maximum_fence(fences, low, mid)
        right = find_maximum_fence(fences, mid + 1, high)
        cross = find_cross_maximum_fence(fences, low, mid, high)

        # print("[", high, low, mid, "] :", left, right, cross)

        if left >= right and left >= cross:
            return left
        elif right >= left and right >= cross:
            return right
        elif cross >= right and cross >= left:
            return cross


print(find_maximum_fence(fences, 0, len(fences) - 1))
