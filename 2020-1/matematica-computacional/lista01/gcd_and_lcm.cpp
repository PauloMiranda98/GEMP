#include <iostream>

using namespace std;
int64_t mdc(int64_t a, int64_t b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}
int64_t mmc(int64_t a, int64_t b){
	int64_t _mdc = mdc(a, b);
	
	return (a/_mdc)*b;
}
int main() {
	//a/b + c/d = e/f
	int64_t a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int64_t f = mmc(b, d);
	int64_t e = a*(f/b) + c*(f/d);
	
	//tornar a fração irredutível
	int64_t _mdc = mdc(e, f);
	
	cout << (e/_mdc) << " " << (f/_mdc) << endl;
	return 0;
}
