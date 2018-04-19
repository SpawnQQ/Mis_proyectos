import tensorflow as tf

#nodo 1 constante
nodo1 = tf.constant(3.0, dtype=tf.float32)

#nodo 2
nodo2 = tf.constant(6.0)

print(nodo1)
print(nodo2)

sess = tf.Session()
print(sess.run([nodo1, nodo2]))