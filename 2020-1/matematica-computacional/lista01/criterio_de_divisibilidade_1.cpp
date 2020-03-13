#include <iostream>

using namespace std;

int charParaInt(char c){
	return c-'0';
}

bool divisivel(string s, int mod){
	int n = s.size();
	int soma = 0;
	int base = 1; 
	for(int i=n-1; i>=0; i--){
		soma = (soma + base*charParaInt(s[i]))%mod;
		base = (base * 10)%mod;
	}
	return soma == 0;
}

int main() {
	string s;
	cin >> s;
	if(divisivel(s, 2))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;

	if(divisivel(s, 3))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;

	if(divisivel(s, 5))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}
