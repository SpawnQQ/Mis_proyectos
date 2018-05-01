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

import tensorflow as tf

x = tf.placeholder(tf.float32, [None, 3])
W = tf.Variable(tf.zeros([3,3])) 
b = tf.Variable(tf.zeros([3])) 
y = tf.matmul(x, W) + b 
yR = tf.placeholder(tf.float32,[None, 3])
softmax = tf.nn.softmax_cross_entropy_with_logits(labels=yR, logits=y)
costo = tf.reduce_mean(softmax)
optimizador = tf.train.GradientDescentOptimizer(0.5).minimize(costo)

prediccion = tf.equal(tf.argmax(y, 1), tf.argmax(yR, 1)) #Nos da arreglo bolleano para decir cuales predicciones estan bien y cuales no

accuracy = tf.reduce_mean(tf.cast(prediccion, tf.float32)) #Nos da el porcentaje sobre el arreglo de prediccion
Produccion = tf.argmax(y, 1)
sess = tf.InteractiveSession()
init = tf.global_variables_initializer()

def avance(epoca_i, sess, last_features, last_labels):
	costoActual = sess.run(costo,feed_dict={x: last_features, yR: last_labels})
	Certeza = sess.run(accuracy,feed_dict={x:mnist.validation.images,yR: mnist.validation.labels})
	print('Epoca: {:<4} - Costo: {:<8.3} Certeza: {:<5.3}'.format(epoca_i,costoActual,Certeza))

with tf.Session() as sess:
	sess.run(init)
	for epoca_i in range(1000):
		lotex, lotey = mnist.train.next_batch(100)
		sess.run(optimizador, feed_dict={x: lotex, yR: lotey})
		if (epoca_i%1==0):
			avance(epoca_i, sess, lotex, lotey)
	print('RESULTADO FINAL: ',sess.run(accuracy, feed_dict={x: mnist.test.images,yR: mnist.test.labels}))
	print ('Resultado de una imagen',sess.run(Produccion,feed_dict={x: mnist.test.images[9].reshape(1,784)}))
	print (mnist.test.labels[9])
	print ('Resultado de una imagen',sess.run(Produccion,feed_dict={x: mnist.test.images[10].reshape(1,784)}))
	print (mnist.test.labels[10])