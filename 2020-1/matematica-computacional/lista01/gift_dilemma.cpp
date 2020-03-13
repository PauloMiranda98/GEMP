#include <iostream>

using namespace std;

//g = a*x + b*y
int64_t mdcEstendido(int64_t a, int64_t b, int64_t &x, int64_t &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int64_t x1, y1;
	int64_t g = mdcEstendido(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;		
	return g;
}

int64_t contarQuantidadeDeSolucao(int64_t a, int64_t b, int64_t p){
	int64_t x, y;
	int64_t g = mdcEstendido(a, b, x, y);
	if(p%g != 0)
		return 0;
	x = x*(p/g);
	y = y*(p/g);
	//padronizando: 0<=x<b
	//a*(x-b*k) + b*(y+a*k) = g
	int64_t k;
	if(x >= 0){
		k = x/(b/g);
	}else{
		k = -((-x+(b/g)-1)/(b/g));
	}
	x = x-(b/g)*k;
	y = y+(a/g)*k;
	
	if(y >= 0){
		return y/(a/g) + 1;
	}else{
		return 0;
	}
}

int main() {
	int32_t testes;
	cin >> testes;
	
	for(int caso=1; caso <= testes; caso++){
		int64_t a, b, c, p;
		cin >> a >> b >> c >> p;
		int64_t resposta = 0;
		for(int64_t k=0; k*c <= p; k++){
			resposta += contarQuantidadeDeSolucao(a, b, p-k*c);			
		}
		cout << "Case "<< caso << ": ";
		cout << resposta << endl;
	}
	return 0;
}

