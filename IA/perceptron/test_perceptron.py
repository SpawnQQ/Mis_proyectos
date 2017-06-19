#!/usr/bin/env python
from perceptron import Perceptron
import matplotlib.pyplot as plt

## Datos de hombres y mujeres
input_data = [[170,1,56,1], # Mujer de 1.70m y 56kg
              [172,2,63,0],# Hombre de 1.72m y 63kg
              [160,3,50,1], # Mujer de 1.60m y 50kg
              [170,4,63,0], # Hombre de 1.70m y 63kg
              [174,5,66,0],# Hombre de 1.74m y 66kg
              [158,6,55,1],# Mujer de 1.58m y 55kg
              [183,7,80,0],# Hombre de 1.83m y 80kg
              [182,8,70,0],# Hombre de 1.82m y 70kg
              [165,9,54,1]]# Mujer de 1.65m y 54kg

## Creamos el perceptron
pr = Perceptron(4,0.1) # Perceptron con 3 entradas
weights = [] # Lista con los pesos
errors = []  # Lista con los errores

## Fase de entrenamiento
for _ in range(100):
    # Vamos a entrenarlo varias veces sobre los mismos datos
    # para que los 'pesos' converjan
    for person in input_data:
        output = person[-1]
        inp = [1] + person[0:-1] # Agregamos un uno por default
        weights.append(pr._w)
        err = pr.train(inp,output)
        errors.append(err)

h = float(raw_input("Introduce tu estatura en centimetros.- "))
w = float(raw_input("Introduce tu peso en kilogramos.- "))
x = float(raw_input("Introduce numero.- "))

if pr.predict([w,x,h,2]) == 1: print "Mujer"
else: print "Hombre"

#print """
#Nota: El resultado puede estar incorrecto. 
#Esto puede ser debido a sesgo en la muestra, o porque es imposible separar
#a hombres y mujeres perfectamente basados unicamente en talla y peso."""

## Fase de graficacion
import imp

can_plot = True
try:
    imp.find_module('matplotlib')
except:
    can_plot = False

if not can_plot:
    print "No es posible graficar los resultados porque no tienes matplotlib"
    sys.exit(0)
    pass

plt.plot(errors)
plt.show()