def factorial(n):
	if n==0:
		return 1
	if n==1:
		return 1
	return n*factorial(n-1)	

#print factorial(100)
print(factorial(100000))