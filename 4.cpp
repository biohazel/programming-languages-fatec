# include <iostream>
using namespace std;
int main () {
	double valor;
	cout <<  "Digite um valor numerico" << endl;
	cin >> valor;
	if (valor >= 28 && valor < 30) {
		cout << "O valor esta no intervalo [28, 30[";

	} else if ((valor > 35 && valor <= 40) || (valor >= 90 && valor <= 100)){
	       cout << "O valor esta entre os intervalo ]35,40] ou [90,100]" << endl;	
	} else if ((valor == 100) || (valor >= 200 && valor <= 300) || (valor > 500 && valor < 600)) {
		cout << "O valor esta entre 100 ou [200,300] ou ]500,600[" << endl;
	
	} else {
		cout << "O valor esta fora dos intervalos." << endl;
	}
	return 0;

}
