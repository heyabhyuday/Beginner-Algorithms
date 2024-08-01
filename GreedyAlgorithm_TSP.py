# import datetime
def Greedy_TSP(cities):
    pathweight = 0
    counter = 0
    i = 0
    j = 0
    minweight = 2147483647

    visited = dict()  # List to store all cities that get visited
    visited[0] = 1  # Starting city is the one at the first index
    path = [0] * len(cities)

    while i < len(cities) and j < len(cities[i]):
        if counter >= len(cities[i]) - 1:
            break

        # If the city hasn't been visited, check weight and update
        if j != i and j not in visited:
            if cities[i][j] < minweight:
                minweight = cities[i][j]
                path[counter] = j + 1
        j += 1

        # Check all paths that continue from the current city
        if j == len(cities[i]):
            pathweight += minweight
            minweight = 2147483647
            visited[path[counter] - 1] = 1
            i = path[counter] - 1
            j = 0
            counter += 1

    i = path[counter - 1] - 1

    for j in range(0, len(cities)):
        if i != j and cities[i][j] < minweight:
            minweight = cities[i][j]
            path[counter] = j + 1

    pathweight += minweight
    return pathweight


# Examples
cities1 = [[0, 10, 15, 20], [10, 0, 35, 25],
           [15, 35, 0, 30], [20, 25, 30, 0]]

print(Greedy_TSP(cities1))

cities2 = [[0, 14, 4, 10, 20], [14, 0, 7, 8, 7],
           [4, 5, 0, 7, 16], [11, 7, 9, 0, 2],
           [18, 7, 17, 4, 0]]

print(Greedy_TSP(cities2))

cities3 = [[0, 25, 10, 15], [25, 0, 10, 45],
           [10, 10, 0, 5], [15, 45, 5, 0]]

print(Greedy_TSP(cities3))

