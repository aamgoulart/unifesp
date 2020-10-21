import pandas as pd
path = 'aula10/patient.csv'

patient = pd.read_csv(path, sep=',')

weight = [0.4,-0.6,0.3,0.7]
n = 0.5

def outputNetwork(index):
  return patient['Febre'][index]*weight[0] + patient['Enjôo'][index]*weight[1] + patient['Manchas'][index]*weight[2] + patient['Dores'][index]*weight[3] 

def verifyTraining():
  needTraining = False
  for i in range(4):
    if (outputNetwork(i) > patient['Diagnóstico'][i]):
      needTraining = True
  return needTraining


def updateWeight():
  for i in range(4):
     weight[i] = weight[i] * n *(patient['Diagnóstico'][i]-outputNetwork(i))

def training():
  needTraining = True
  while(needTraining):
    needTraining = verifyTraining()
    updateWeight()


training()

print(weight)
print(n + weight[0]*0 + weight[1]*0 + weight[2]*0 + weight[3]*1)
print(n + weight[0]*1 + weight[1]*1 + weight[2]*1 + weight[3]*1)