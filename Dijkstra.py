import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    unvisited = [(0, start)]
    heapq.heapify(unvisited)

    while unvisited:
        current_distance, current_node = heapq.heappop(unvisited)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(unvisited, (distance, neighbor))
            print(unvisited)

    return distances


graph1 = {
    1: {2: 1, 3: 4},
    2: {3: 2, 4: 6},
    3: {4: 3},
    4: {}
}

graph2 = {
    1: {2: 1, 3: 4},
    2: {4: 2, 5: 2},
    3: {5: 4},
    4: {3: 3, 6: 4},
    5: {6: 3},
    6: {}
}
