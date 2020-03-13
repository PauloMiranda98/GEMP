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

int main() {
	int32_t testes;
	cin >> testes;
	
	for(int caso=1; caso <= testes; caso++){
		int64_t a, b, c, x, y;
		cin >> a >> b >> c;
		int64_t g = mdcEstendido(a, b, x, y);
		cout << "Case "<< caso << ": ";
		if(c%g == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
