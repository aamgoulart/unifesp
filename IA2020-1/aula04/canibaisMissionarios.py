#['amountMissionaryLeft', 'amountCannibalLeft', 'amountMissionaryRight', 'amountCannibalRight', 'canoe']
stateInit = [3,3,0,0,0]

# change de stage acording of canoe
changeState = [(1,0), (1,1), (2,0), (0,2), (0,1)]

border = []

visited = []

def changePerson(situationCurrent, numberMissionary=0, numberCannibal=0):
    if numberMissionary + numberCannibal > 2:
        return

    if situationCurrent[-1] == 0:
        origenMissionary = 0
        origenCannibal = 1
        destinyMissionary = 2
        destinyCannibal = 3
    else:
        origenMissionary = 2
        origenCannibal = 3
        destinyMissionary = 0
        destinyCannibal = 1
    
    if situationCurrent[origenMissionary] == 0 and situationCurrent[origenCannibal] == 0:
        return

    situationCurrent[-1] = 1 - situationCurrent[-1]

    for i in range(min(numberMissionary, situationCurrent[origenMissionary])):
        situationCurrent[origenMissionary]-=1
        situationCurrent[destinyMissionary]+=1

    for i in range(min(numberCannibal, situationCurrent[origenCannibal])):
        situationCurrent[origenCannibal]-=1
        situationCurrent[destinyCannibal]+=1
    
    return situationCurrent

def possibleStates(state):
    posible = []

    for (i,j) in changeState:
        s = changePerson(state[:],i,j)
        if s == None:
            continue
        elif (s[0]<s[1] and s[0]>0) or (s[2]<s[3] and s[2]>0):
            continue
        elif s in visited:
            continue
        posible.append(s)
    return posible

def getNodeNotVisited(node):
    l = possibleStates(node)
    if len(l)>0:
        return l[0]
    else:
        return -1

def isFinalState(state):
    if state[2] >=3 and state[3] >=3:
        return True
    else:
        return False

def dfs(stateInit):
    border.append(stateInit)
    while len(border) != 0:
        analysis = border[len(border)-1]
        if isFinalState(analysis): 
            break
        v = getNodeNotVisited(analysis)
        if v == -1:
            border.pop()
        else:
            visited.append(v)
            border.append(v)
    return border

solution = []
solution = dfs(stateInit)
print(solution)
