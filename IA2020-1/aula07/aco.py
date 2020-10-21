alpha = 1
beta = 1
rho = 0.5
tau = 2

probabilityWay = [[0,0,0,0,0], [0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]

qualityEdges = [[0,2,10,8,3], [1,0,2,5,7], [9,1,0,3,6], [10,4,3,0,2], [2,7,5,1,0]]
pheromone = [[0,2,2,2,2], [2,0,2,2,2], [2,2,0,2,2], [2,2,2,0,2], [2,2,2,2,0]]

def probabilityEdge(probabilityWay):
    calculus = 0.0
    for i in range(5):
        for j in range(5):
            if (qualityEdges[i][j] != 0):
                calculus = (alpha * pheromone[i][j])*(beta*qualityEdges[i][j])/20
                probabilityWay[i][j]=calculus

probabilityEdge(probabilityWay)
print(probabilityWay)