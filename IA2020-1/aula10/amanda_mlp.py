import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
path = 'aula10/glass.csv'
glass = pd.read_csv(path, sep=',')


y = glass['Type'].values
y = y.reshape(-1,1)
x_data = glass.drop(['Type'],axis = 1)

x = (x_data - np.min(x_data)) / (np.max(x_data) - np.min(x_data)).values

x_train, x_test, y_train, y_test = train_test_split(x,y,test_size = 0.5,random_state=100)

y_train = y_train.reshape(-1,1)
y_test = y_test.reshape(-1,1)

print("x_train: ",x_train.shape)
print("x_test: ",x_test.shape)
print("y_train: ",y_train.shape)
print("y_test: ",y_test.shape)

my_x = x_train
my_y = y_train

my_xx = x_test
my_yy = y_test

clf = MLPClassifier(solver='lbfgs', alpha=1e-5,hidden_layer_sizes=(7, 2), random_state=1)

clf.fit(my_x, my_y)
y_pred = clf.predict(my_xx)
print(y_pred)