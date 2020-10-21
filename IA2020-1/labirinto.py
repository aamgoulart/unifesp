from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.max_length = 0

    def addEdge(self, u, v):
        self.graph[u].append(v)
    
    
    def dfs(self, v, cur_length):
            if cur_length > self.max_length:
                self.max_length = cur_length

            self.graph[v].visited = True

            for edge in self.graph[v].connections:
                if not self.graph[edge].visited:
                    cur_length += 1
                    self.dfs(edge, cur_length)

g = Graph()
cur_length = 0
g.addEdge('A','B')
g.addEdge('B','C')
g.addEdge('C','D')
g.addEdge('D','E')
g.addEdge('E','J')
g.addEdge('J','O')
g.addEdge('O','N')
g.addEdge('N','M')
g.addEdge('M','L')
g.addEdge('K','P')
g.addEdge('Q','U')
g.addEdge('U','V')
g.addEdge('V','W')
g.addEdge('W','Y')
g.addEdge('Y','Z')

for key in g.graph:
    g.dfs(key, cur_length)
# h = Graph()

# h.addEdge('A','F')
# h.addEdge('F','G')
# h.addEdge('F','K')
# h.addEdge('K','P')
# h.addEdge('G','H')
# h.addEdge('H','M')
# h.addEdge('H','C')
# h.addEdge('M','N')
# h.addEdge('S','T')
# h.addEdge('C','D')
# h.addEdge('D','E')


# h.dfs()
print(graph.max_length)