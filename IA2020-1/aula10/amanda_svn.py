import pandas as pd
import numpy as np
from sklearn.multiclass import OneVsRestClassifier
from sklearn.svm import LinearSVC

path = 'aula10/glass.csv'
glass = pd.read_csv(path, sep=',')

types = glass.Type.unique()

alpha = 0.7 

train = pd.DataFrame()
test = pd.DataFrame()
for i in range(len(types)):
    tempt = glass[glass.Type == types[i]]
    train = train.append(tempt[0:int(alpha*len(tempt))])
    test = test.append(tempt[int(alpha*len(tempt)): len(tempt)])


X = train.drop('Type',1)
Y = train['Type']
Z = test.drop('Type',1)

prediction = OneVsRestClassifier(LinearSVC(random_state=0)).fit(X, Y).predict(Z)

print(prediction)

truth = test['Type']
truth = np.array(truth)

accuracy = sum(prediction == truth)/(len(truth))
print(accuracy)