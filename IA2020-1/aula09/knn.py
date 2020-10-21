import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler  
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, confusion_matrix  

path = 'aula09/Iris.csv'
irisCrude = pd.read_csv(path, sep=',')

x_train, x_test, y_train, y_test = train_test_split(irisCrude.drop('Species',
                                                    axis=1),
                                                    irisCrude['Species'],
                                                    test_size=0.3,
                                                    random_state=42)
scaler = StandardScaler()  
scaler.fit(x_train)

x_train = scaler.transform(x_train)  
x_test = scaler.transform(x_test) 

classifier = KNeighborsClassifier(n_neighbors = 5)  
classifier.fit(x_train, y_train)

KNeighborsClassifier(algorithm='auto', leaf_size=30, metric='minkowski',
                     metric_params=None, n_jobs=None, n_neighbors=5, p=2,
                     weights='uniform')

y_pred = classifier.predict(x_test)

print(classification_report(y_test, y_pred)) 