import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn import model_selection

path = 'aula09/Iris.csv'

irisCrude = pd.read_csv(path, sep=',')

array = irisCrude.values
X = array[:,1:5]
Y = array[:,5]

validation_size = 0.3
seed = 7
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size=validation_size, random_state=seed)

tree = DecisionTreeClassifier(criterion = 'entropy').fit(X_train,Y_train)

prediction = tree.predict(X_train)

print("The prediction accuracy is: ",tree.score(X_train,Y_train)*100,"%")