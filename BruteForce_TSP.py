from itertools import permutations
# import datetime

def BruteForce_TSP(cities, start):
    N = len(cities)  # Total number of vertices or "cities"

    # Store all vertices that have to be visited
    tovisit = []
    for i in range(N):
        if i != start:
            tovisit.append(i)

    # List of all possible paths
    allpaths = permutations(tovisit)

    # Keep track of minimum path weight encountered
    minweight = 2147483647  # Max int value in python

    for i in allpaths:
        pathweight = 0

        # Compute weight of the current path
        x = start
        for j in i:
            pathweight += cities[x][j]
            x = j
        pathweight += cities[x][start]

        # Update minimum weight, if smaller
        minweight = min(minweight, pathweight)

    return minweight


# Examples
cities1 = [[0, 10, 15, 20], [10, 0, 35, 25],
          [15, 35, 0, 30], [20, 25, 30, 0]]

print(BruteForce_TSP(cities1, 0))

cities2 = [[0, 14, 4, 10, 20], [14, 0, 7, 8, 7],
           [4, 5, 0, 7, 16], [11, 7, 9, 0, 2],
           [18, 7, 17, 4, 0]]

print(BruteForce_TSP(cities2, 0))

cities3 = [[0, 25, 10, 15], [25, 0, 10, 45],
           [10, 10, 0, 5], [15, 45, 5, 0]]

print(BruteForce_TSP(cities3, 0))
