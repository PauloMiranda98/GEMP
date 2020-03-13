#include <iostream>

using namespace std;

//g = a*x + b*y
int64_t mdc_estendido(int64_t a, int64_t b, int64_t &x, int64_t &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int64_t x1, y1;
	int64_t g = mdc_estendido(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return g;
}

int main() {
	int64_t a, b, x1, y1, x2, y2;
	while(cin >> a >> b){ //Ler enquanto tem alguma coisa para ler
		int64_t g = mdc_estendido(a, b, x1, y1);

		//padronizando: 0<=x<b
		//a*(x-b*k) + b*(y+a*k) = g
		int64_t k;
		if(x1 >= 0){
			k = x1/b;
		}else{
			k = -(-x1+b-1)/b;
		}
		x1 = x1-b*k;
		y1 = y1+a*k;
		
		//a*(x+b*k) + b*(y-a*k);
		//padronizando: 0<=y<a
		if(y1 >= 0){
			k = (y1/a);
		}else{
			k = -(-y1+a-1)/a;
		}
		x2 = x1+b*k;
		y2 = y1-a*k;
		if(abs(x1)+abs(y1) <= abs(x2)+abs(y2))
			cout << x1 << " " << y1 << " " << g << endl;
		else
			cout << x2 << " " << y2 << " " << g << endl;
	}
	return 0;
}
