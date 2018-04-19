import tensorflow as tf

nodo1 = tf.constant(3.0, dtype=tf.float32)
nodo2 = tf.constant(6.0)

sess = tf.Session()

# Combinar nodos

nodo3 = tf.add(nodo1, nodo2)

print("nodo3 : ", sess.run(nodo3))

#Marcadores de posicion

x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)
sumador = x + y

print("sumador #1: ", sess.run(sumador, feed_dict = {x:3, y:2}))
print("sumador #2: ", sess.run(sumador,{x:[2, 3], y:[4, 1]}))

sum_mul = sumador * 5
print("sum_mul: ", sess.run(sum_mul, {x:3, y:4}))