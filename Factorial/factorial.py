def factorial_recursivo(n):
	if n==0:
		return 1
	if n==1:
		return 1
	return n*factorial_recursivo(n-1)

def entero_ncientifica(n_entero):
	contador=0;
	lista=range(2)
	nm=float(n_entero)
	if nm/10 > 1:
		while nm/10 > 1:
			nm=nm/10
			contador=contador+1
		lista[0]=nm
		lista[1]=contador
	else:
		lista[0]=nm
		lista[1]=0
	return lista	

def ncientifica(n_cientifico):
	contador=0
	nm=float(n_cientifico[0])
	if nm/10 > 1:
		while nm/10 > 1:
			nm=nm/10
			contador=contador+1
		base=nm
		exponente=contador
	else:
		base=nm
		exponente=0
	n_cientifico[0]=base
	n_cientifico[1]=exponente+n_cientifico[1]
	return n_cientifico

def mult_ncientifica(n1_cientifico,n2_cientifico,resultado):
	resultado[0]=n1_cientifico[0]*n2_cientifico[0]
	resultado[1]=n1_cientifico[1]+n2_cientifico[1]
	resultado=ncientifica(resultado)
	return resultado

def vfactorial(n):
	if n==0:
		return 1
	if n==1:
		return 1
	return mult_ncientifica(entero_ncientifica(n),vfactorial(n-1))

def factorial(n):
	resultado=range(2)
	resultado[0]=1;
	resultado[1]=0;
	while n!=0:
		resultado=mult_ncientifica(entero_ncientifica(n),resultado,resultado);
		n=n-1;
	return resultado
#print factorial(100)
resultado=factorial(5000)

print resultado[0],'e+',resultado[1]