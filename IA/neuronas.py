import numpy as np
import random
import math

def leer_ele():	
	#Lee el fichero .txt y lo asigna a la lista elementos
	lineas = open("datos_ia.txt").readlines()
	elementos = [[m.strip() for m in n] for n in [linea.split(" ") for linea in lineas]]
	return elementos

def perceptron(entrada,peso,n):
	ponderar=0
	for i in range(n):
		ponderar=(int(entrada[i])*peso[i])+ponderar
	return ponderar

#def reajuste(entrada,peso, n,indice):
#	return 

resultado=[]
txt =leer_ele()
n=2
peso = np.random.uniform(0,1,n+1)
print peso
entrada=txt[1]
print txt[1]
print "Entradas:",entrada

print "Perceptron: ",perceptron(entrada,peso,n)

print "peso: ", peso

