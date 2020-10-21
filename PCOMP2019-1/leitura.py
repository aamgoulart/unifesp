import pandas as pd

dadosUc = pd.read_csv('materias.csv')

#print(dadosUc)


for indice, coluna in dadosUc.iterrows():
    if indice['Termo'] == 1 or indice['Termo'] == 2:
        print (indice['Nome da UC'])

