#include <iostream>
#include <cmath>

int main(){
    static const int N = 10;
	double arr[N] = {1.1, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.5};
	
	double m = arr[0];
	double M = arr[0];
	double sum = arr[0];
	
	for (int i = 1; i < N; i++){
		sum = sum + arr[i];
		m = std:: min(m, arr[i]);
		M = std:: max(M, arr[i]);
	}
	
	std :: cout << "Il minimo è:" << m << "\n";
	std :: cout << "Il massimo è:" << M << "\n";
	
	double media = sum/N;
	
	std :: cout << "La media è:" << media << "\n";
	
	double sum2 = 0;
	for (int i = 0; i < N; i++){
		sum2 = sum2 + pow(arr[i],2);
	}
	
	double deviazione = sqrt(sum2/N - pow(media,2));
	std :: cout << "La deviazione standard è:" << deviazione << "\n";
	return 0;
	
}