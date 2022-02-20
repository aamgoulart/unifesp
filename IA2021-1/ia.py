
import pandas as pd
df = pd.read_csv('/home/agoulart/Vídeos/ia/casos_obitos_doencas_preexistentes.csv', delimiter=';')


df.to_csv("test.csv", sep=",",index=False)
