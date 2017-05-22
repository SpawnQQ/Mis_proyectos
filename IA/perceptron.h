
double neurona(int entrada[], float peso[], int n){
	float ponderacion=0;
	for(int i=0;i<n;i++){
		ponderacion=ponderacion+(entrada[i]*peso[i]);
	}
	return tanh(ponderacion);
}