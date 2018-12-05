import sys
MAX = sys.maxsize

def DFS(Graph, start, visited):
    if start not in visited:
        # visit(start)
        print(start, " is visited")
        visited.add(start)
        adjacents = Graph[start]
        for adjacent, weight in adjacents:
            DFS(Graph, adjacent, visited)

def find_min_weight(Graph, start, visited, curr_weight):
    if start not in visited:
            # visit(start)
            print(start, " is visited")
            visited.add(start)
            adjacents = Graph[start]

            min_weight = MAX
            min_adjacent = start
            for adjacent, weight in adjacents:
                # Find edge with min weight
                if adjacent not in visited:
                    if weight < min_weight:
                        min_weight = weight
                        min_adjacent = adjacent
            if (min_weight < MAX):
                curr_weight += min_weight
            return find_min_weight(Graph, min_adjacent, visited, curr_weight)
    else:
        return curr_weight

def find_max_weight(Graph, start, visited, curr_weight):
    if start not in visited:
            # visit(start)
            print(start, " is visited")
            visited.add(start)
            adjacents = Graph[start]

            max_weight = -1
            max_adjacent = start
            for adjacent, weight in adjacents:
                # Find edge with min weight
                if adjacent not in visited:
                    if weight > max_weight:
                        max_weight = weight
                        max_adjacent = adjacent
            if (max_weight > -1):
                curr_weight += max_weight
            return find_max_weight(Graph, max_adjacent, visited, curr_weight)
    else:
        return curr_weight

def main():
    n = 3
    e = 3

    start = [1, 2, 3]
    end = [3, 1, 2]
    weights = [5, 5, 2]

    source_vertex = 1

    Graph = {i: [] for i in range(1, n+1)}

    for source, destination, weight in zip(start, end, weights):
        Graph[source].append([destination, weight])
        Graph[destination].append([source, weight])

    # Print adjacency list
    # print(Graph)
    # DFS(Graph, source_vertex, set())
    minw = find_min_weight(Graph, source_vertex, set(), 0)
    maxw = find_max_weight(Graph, source_vertex, set(), 0)
    print(minw, maxw)


main()