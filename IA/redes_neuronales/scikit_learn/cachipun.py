options =["piedra", "papel", "tijeras"]

def search_winner(p1, p2):
	if p1 == p2:
		result = 0
	elif p1 == "piedra" and p2 == "tijeras":
		result = 1
	elif p1 == "piedra" and p2 == "papel":
		result = 2
	elif p1 == "papel" and p2 == "tijeras":
		result = 2
	elif p1 == "papel" and p2 == "piedra":
		result = 1
	elif p1 == "tijeras" and p2 == "piedra":
		result = 2
	elif p1 == "tijeras" and p2 == "papel":
		result = 1

	return result

from random import choice

def get_choice():
	return choice(options)

for i in range(10):
	player1 = get_choice()
	player2 = get_choice()
	print("player1: %s player2: %s Winner: %s " %(player1,player2, search_winner(player1, player2)))

def str_to_list(option):
	if option == "piedra":
		res = [1,0,0]
	if option == "papel":
		res = [0,1,0]
	if option == "tijeras":
		res = [0,0,1]

	return res

data_x1 = list(map(str_to_list, ["piedra", "papel", "tijeras"]))
data_x2 = list(map(str_to_list, ["papel", "tijeras", "papel"]))

print(data_x1)
print(data_x2)

#importamos clasificador de scikit learn
from sklearn.neural_network import MLPClassifier

clf = MLPClassifier(verbose=False, warm_start=True)

#El modelo que utilizaremos, le pasamos un solo dato para que no aprenda con todos los valores de data
model = clf.fit([data_x1[0]], [data_x2[0]])
print(model)

def play_and_learn(iters=10, debug=False):
	score = {"win": 0, "loose": 0}
	
	data_x1 = []
	data_x2 = []
	
	for i in range(iters):
		player1 = get_choice()
		
		#Calculamos la probabilidad de la prediccion sobre el modelo model, nos quedamos con el primer resultado
		predict = model.predict_proba([str_to_list(player1)])[0]
		
		if predict[0] >= 0.95:
			player2 = options[0]
		elif predict[1] >= 0.95:
			player2 = options[1]
		elif predict[2] >= 0.95:
			player2 = options[2]
		else:
			#Si no esta en un 95% seguro, entonces tira una opcion random
			player2 = get_choice()

		if debug==True:
			print("Player1: %s Player2 (modelo): %s --> %s" % (player1, predict, player2))

		winner = search_winner(player1, player2)
		if debug==True:
			print("Comprobamos: p1 VS p2: %s" % winner)

		#Si player 2 ha ganado, entonces lo entrenamos para que aprenda
		if winner==2:
			data_x1.append(str_to_list(player1))
			data_x2.append(str_to_list(player2))

			score["win"]+=1
		else:
			score["loose"]+=1

	return score, data_x1, data_x2

score, data_x1, data_x2 = play_and_learn(1, debug=True)
print(data_x1)
print(data_x2)
print("Score: %s %s %%" % (score, (score["win"]*100/(score["win"]+score["loose"]))))
if len(data_x1):
	model = model.partial_fit(data_x1, data_x2)

i = 0
historic_pct = []
while True:
	i+=1
	score, data_x1, data_x2 = play_and_learn(1000, debug=False)
	pct = (score["win"]*100/(score["win"]+score["loose"]))
	historic_pct.append(pct)
	print("Iter: %s - score: %s %s %%" % (i, score, pct))

	if len(data_x1):
		model = model.partial_fit(data_x1, data_x2)

	if sum(historic_pct[-9:])==900:
		break

import matplotlib.pyplot as plt
import numpy as np

plt.title("Porcetaje de aprendizaje en cada iteración")
plt.xlabel("Numero de iteración")
plt.ylabel("Tasa de aprendizaje")

plt.plot(range(len(historic_pct)),historic_pct)

plt.show()