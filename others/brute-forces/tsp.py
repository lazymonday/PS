import sys

numberOfCities = 10

distance = [[1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]]


def shortest_path_2(visited, path, current_len):
    all_visited = True
    for v in visited:
        if not v:
            all_visited = False
            break

    if all_visited:
        return current_len + distance[0][path[-1]]

    min_len = sys.maxsize

    for index in range(numberOfCities):

        if visited[index]:
            continue

        visited[index] = True
        here = path[-1]
        path.append(index)

        candidate = shortest_path_2(visited, path, current_len + distance[here][index])
        min_len = min(candidate, min_len)

        path.pop()
        visited[index] = False

    return min_len


# think about distance between two nodes is different


def shortestPath(visited, path, currentLength):
    if len(path) == numberOfCities:
        return distance[0][path[-1]] + currentLength

    length = sys.maxsize

    for index in range(numberOfCities):
        if visited[index]:
            continue

        here = path[-1]
        visited[index] = True
        path.append(index)
        candidate = shortestPath(visited, path, currentLength + distance[here][index])
        length = min(length, candidate)
        visited[index] = False
        path.pop()

    return length


visited = [False for i in range(numberOfCities)]
path = [0]

visited[0] = True
shortestLength = shortestPath(visited, path, 0)
print('shortestLength : ' + str(shortestLength))

visited = [False for i in range(numberOfCities)]
path = [0]

visited[0] = True
shortestLength = shortest_path_2(visited, path, 0)
print('shortestLength : ' + str(shortestLength))
