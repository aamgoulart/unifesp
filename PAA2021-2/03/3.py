def perdedor(parts):
  for i in parts:
    if i >= N:
      return 1
    else: 
      return 0

def vencedor(parts):
  return len(parts) == 1

def validador(x, y):
  return x >=1 and y>=1 and x < L and y < L

N = 65
L = 9
dx = [1,1,-1,-1,2,2,-2,-2]
dy = [2,-2,2, -2,1,-1,1,-1]
contador = 0
matriz = []
graph = [[], [11,18], [12,19,17], [13,9,20,18], [14,10,21,19], [15,11,22,20], [16,12,23,21],
 [13,24,22], [14,23],[19,3,26], [20,4,27,25], [21,17,5,1,28, 26], [22,18, 6,2,29,27], 
 [23,19, 7,3,30,28], [24,20,8,4,31,29], [21,5,32,30], [22,6,31],[27,11,34,2], [28,12,35,33,3,1], 
 [29,25,13,9,36,24,4,2], [30,26,14,10,37,35,5,3], [31,27,15,11,38,36,6,4],
 [32,28,16,12,39,37,7,5], [29,13,40, 38,8,6], [30,14,39,7], [35,19,42,10], [36,20, 43,41,11,9], 
 [37,33,21,17,44,42,12,10], [38,34,22,18,45,14,12], [39,35,23,19,46,44,14,12], [40,36,24,20,47,45,15,13],
  [37,21,48,46,16,15], [38,21,48,46,16,14], [43,27,50,18], [44,28,51,49,19,17], 
  [45, 41, 29 ,25 ,52, 50, 20, 18], [46, 42, 30, 26, 53, 51, 21, 19], [47, 43, 31, 27, 54, 52, 22, 20],
[48, 44, 32, 28, 55, 53, 23, 21], [45, 29, 56, 54, 24, 22], [46, 30, 55, 23], [51, 35, 58, 26], 
[52, 36, 59, 57, 27, 25], [53, 49, 37, 33, 60, 58, 28, 26], [54, 50, 38, 34, 61, 59, 29, 27], 
[55, 51, 39, 35, 62, 60, 30, 28], [56, 52, 40, 36, 63, 61, 31, 29], [53, 37, 64, 62, 32, 30],
[54, 38, 63, 31], [59, 43, 34], [60, 44, 35, 33], [61, 57, 45, 41, 36, 34],[62, 58, 46, 42, 37, 35],
[63, 59, 47, 43, 38, 36], [64, 60, 48, 44, 39, 37],[61, 45, 40, 38],[62, 46, 39] , [51, 42], 
[52, 43, 41], [53, 49, 44, 42], [54, 50, 45, 43], [55, 51, 46, 44], [56, 52, 47, 45],[53, 48, 46],
[54, 47] ]

n = int(input())
b = []
possivel = 0
queue = []
set = []
init = []

for i in range(n+1):
  peca = int(input())
  b.append(peca)

aux = [0]
init.append(aux)
init.append(init)
queue.append(init)

print(init)
# while (len(queue) > 0):
#   now = queue[0]
#   set.clear()
#   teste = queue.pop(0)
#   movements = now[0]
#   parts = now[1]
#   if(set.count(parts)):
#     continue
#   set.append(parts)
#   if(perdedor(parts)):
#     continue

#   if(vencedor(parts)):
#     possivel = 1
#     print(movements[0])
#     break
#   horse = parts[len(parts)-1]
#   for i in range(len(graph[horse])):
#     next = graph[horse][i]
#     new = []
#     for j in range(len(parts)-1):
#       peao = parts[j]
#       if (peao == next):
#         continue
#       new.append(peao+8)
#     new.append(next)
#     auxiliar = []
#     x =  movements[0] + 1
#     y = []
#     y.append(x)
#     auxiliar.append((y))

#     auxiliar.append(new)
#     queue.append(auxiliar)

# if not(possivel):
#   print("impossible")

