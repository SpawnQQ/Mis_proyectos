import tensorflow as tf
old_v = tf.logging.get_verbosity()
tf.logging.set_verbosity(tf.logging.ERROR)

from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

x = tf.placeholder(tf.float32, [None, 784]) #Variable x donde se almacena la imagen del numero en un vector
W = tf.Variable(tf.zeros([784,10])) #Matriz de pesos, 784 para recibir la imagen, 10 por las posibles salidas (0,1,2,3,...,9)
b = tf.Variable(tf.zeros([10])) #Bias o sesgo de nuestra red neuronal
y = tf.matmul(x, W) + b #La variable salida, es una multiplicacion de matrices (matmul) de la entrada por el peso mas el bias (y = x*W + b)
yR = tf.placeholder(tf.float32,[None, 10]) #Matriz con las etiquetas reales del set de datos

softmax = tf.nn.softmax_cross_entropy_with_logits(labels=yR, logits=y)
costo = tf.reduce_mean(softmax)
optimizador = tf.train.GradientDescentOptimizer(0.5).minimize(costo)

prediccion = tf.equal(tf.argmax(y, 1), tf.argmax(yR, 1)) #Nos da arreglo bolleano para decir cuales predicciones estan bien y cuales no

accuracy = tf.reduce_mean(tf.cast(prediccion, tf.float32)) #Nos da el porcentaje sobre el arreglo de prediccion
Produccion = tf.argmax(y, 1)
sess = tf.InteractiveSession()
init = tf.global_variables_initializer()

#Funcion que usaremos para ver que tan bien va a aprendiendo nuestro modelo 
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