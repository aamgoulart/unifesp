import numpy as np 
import pandas as pd
from sklearn.naive_bayes import GaussianNB
from sklearn import model_selection
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score

path = 'aula09/Iris.csv'
irisCrude = pd.read_csv(path, sep=',')

irisCrude.Species.replace(['Iris-setosa', 'Iris-versicolor', 'Iris-virginica'], [1, 2, 3], inplace=True)

clf = GaussianNB()

array = irisCrude.values
X = array[:,1:5]
Y = array[:,5]

validation_size = 0.3

seed = 7
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size=validation_size, random_state=seed)

scoring = 'accuracy'

clf.fit(X_train, Y_train) 

pred_clf = clf.predict(X_validation)

prob_pos_clf = clf.predict_proba(X_validation)[:, 1]

pred_clf_df = pd.DataFrame(pred_clf.reshape(50,1))

pred_clf_df.rename(columns={0:'Prediction'}, inplace=True)

X_validation_df = pd.DataFrame(X_validation.reshape(50,4))

pred_outcome = pd.concat([X_validation_df, pred_clf_df], axis=1)

pred_outcome.rename(columns = {0:'SepalLengthCm', 1:'SepalWidthCm', 2:'PetalLengthCm', 3:'PetalWidthCm'}, inplace=True)

del irisCrude['Id']

pred_comp = pd.merge(irisCrude,pred_outcome, on=['SepalLengthCm','SepalWidthCm','PetalLengthCm','PetalWidthCm'])

print(pred_comp.head(10))