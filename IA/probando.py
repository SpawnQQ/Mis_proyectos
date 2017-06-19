#!/usr/bin/env python
import random
import numpy as np

def ajuste(reglas,peso,fa):
  for c in range(100):
    for i in range(6):
      peso[0]=peso[0]+fa*reglas[i][3]*reglas[i][0]
      peso[1]=peso[1]+fa*reglas[i][3]*reglas[i][1]
      peso[2]=peso[2]+fa*reglas[i][3]*reglas[i][2]
  return peso

## Datos de hombres y mujeres

input_data = [[25,80,100,1],
              [30,40,100,0],
              [33,55,100,0], 
              [12,100,100,1], 
              [53,47,100,1],
              [33,98,100,0]]

p = float(raw_input("Introduce promedio contaminacion en el sector ppm.- "))
c = float(raw_input("Introduce contaminacion producida ppm.- "))
n = float(raw_input("Introduce limite por norma de contaminacion ppm.- "))

peso = np.random.uniform(0,1,3)
factor_aprendizaje=0.1

ajuste(input_data,peso,factor_aprendizaje)

print n*peso[2]-(p*peso[0]+c*peso[1])
