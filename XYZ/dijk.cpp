import heapq

def dijkstra(graph, start):
	queue=[(0, start)]
	distances={start: 0}

	while queue:
		distance, node = heapq.heappop(queue)

		if distance > distances[node]:
			continue
	
		for neighbor, weight in graph[node].items():
			new_distance = distance + weight

			if neighbor not in distances or new_distance < distances[neighbor]:
				distances[neighbor] = new_distance
				heapq.heappush(queue, (new_distance, neighbor))

	return distances


graph = {
	"A": {"B": 5, "C": 2},
	"B": {"D": 1, "E": 6},
	"C": {"B": 2, "D": 6},
	"D": {"E": 1},
	"E": {},	
}
start_node = "A"

distances = dijkstra(graph, start_node)

print("Shortest distance from start node", start_node+"is :")
for node, distance in distances.items():
	print(node, distance)