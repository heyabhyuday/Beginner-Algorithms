def bfs(graph, root):
    visited = [root]
    queue = [root]
    while queue:
        node = queue.pop(0)
        print(str(node) + " ")
        for connected in graph[node]:
            if connected not in visited:
                visited.append(connected)
                queue.append(connected)


graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
bfs(graph, 0)


# Write dfs also one time