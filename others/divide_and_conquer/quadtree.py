import sys


class quadtree:

    def __init__(self):
        self.__init__(None)

    def __init__(self, color):
        self.child = []
        self.color = color

    def add_child(self, child):
        self.child.append(child)

    def swap_12_and_34(self):
        if len(self.child) == 0:
            return True

        for i in range(len(self.child)):
            self.child[i].swap_12_and_34()

        tmp = self.child[0]
        tmp2 = self.child[1]
        self.child[0] = self.child[2]
        self.child[1] = self.child[3]
        self.child[2] = tmp
        self.child[3] = tmp2

    def set_color(self, color):
        self.color = color

    def count_all_children(self):
        if len(self.child) == 0:
            return 1
        else:
            total = 0
            for i in range(len(self.child)):
                total += self.child[i].count_all_children()
        return total + 1

    def sprint_tree(self):
        str = []
        str.append(self.color)
        for i in range(len(self.child)):
            str.append(self.child[i].sprint_tree())

        return ''.join(str)

input_str = ["w",
             "xbwwb",
             "xbwxwbbwb",
             "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb"]


def decompress_quadtree(compressed, start_index):
    # basis
    if compressed[0] == "w" or compressed[0] == "b":
        return quadtree(compressed[0])

    if compressed[start_index] == "x":
        tree = quadtree("x")
        offset = 1
        child = decompress_quadtree(compressed, start_index + offset)
        tree.add_child(child)
        offset += child.count_all_children()

        child = decompress_quadtree(compressed, start_index + offset)
        tree.add_child(child)
        offset += child.count_all_children()

        child = decompress_quadtree(compressed, start_index + offset)
        tree.add_child(child)
        offset += child.count_all_children()

        child = decompress_quadtree(compressed, start_index + offset)
        tree.add_child(child)
        return tree
    else:
        return quadtree(compressed[start_index])


quadtree = decompress_quadtree(input_str[2], 0)
print(quadtree.sprint_tree())
quadtree.swap_12_and_34()
print(quadtree.sprint_tree())