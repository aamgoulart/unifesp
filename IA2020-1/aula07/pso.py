import numpy as np
w = 0.7
c1 = 0.2
c2 = 0.6
r1 = 0.4657
r2 = 0.5319
n = 5
interations = 3
pBest = []
gBest = 0
newX = []
tentative = 0


X = [0.4657, 0.8956, 0.3877, 0.4902, 0.5039]
V = [0.5319, 0.8185, 0.831, 0.7677, 0.1708]

def initPopulation(X, Y):
    for i in range(n):
        X[i] = 10 * (X[i] - 0.5)
        Y[i] = 10 * (Y[i] - 0.5)

def findPBest(X,newX):
    for i in range(n):
        if (X[i] < newX[i]):
            pBest[i] = newX[i]
        else:
            pBest[i] = X[i]

def fitnnes(X, newX):
    for i in range(n):
        applyForm = 1 + (2*X[i])-(X[i]*X[i])
        newX.append(applyForm)

def findIndiceGbest(newX):
    max = newX[0]
    maxIndex = 0
    for i in range(n):
        if newX[i] > max:
            max = newX[i]
            maxIndex = i
    return maxIndex

def updateVelocity(V):
    for i in range(n):
        applyForm = w*V[i] + c1*c2*(pBest[i]-newX[i])+ c1*c2*(gBest-newX[i])
        V[i] = applyForm

def uptadePosition(X):
    for i in range(n):
        X[i] = newX[i] + V[i]


for i in range(interations):
    initPopulation(X, V)
    fitnnes(X, newX)
    if (tentative == 0 ):
        pBest = X
    else:
        findPBest(X, newX)
        updateVelocity(V)
        uptadePosition(X)
    gBest = pBest[findIndiceGbest(newX)]
    print(str(i) + "  Interacao")
    print("X")
    print(X)
    print("V")
    print(V)
    print("F(" + str(i) + ")")
    print(newX)
    print("Pbest")
    print(pBest)
    print("Gbest")
    print(gBest)



