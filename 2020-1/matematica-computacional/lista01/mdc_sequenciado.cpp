#include <iostream>

using namespace std;
int32_t mdc(int32_t a, int32_t b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}
int main() {
	//a/b + c/d = e/f
	int32_t resposta = 0;
	int32_t n;
	cin >> n;
	for(int32_t i=0; i<n; i++){
		int32_t x;
		cin >> x;
		resposta = mdc(resposta, x);
	}	
	cout << resposta << endl;
	return 0;
}
