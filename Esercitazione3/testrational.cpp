#include <iostream>
#include "rational.hpp"

int main(){
	rational<int> r1(3,6);
	rational<int> r2(1,2);
	
	std::cout << "r1 (3/6 semplificato): " << r1 << "\n";
	 
	rational<int> sum = r1+r2;
	rational<int> substraction = r1-r2;
	rational<int> product = r1*r2;
	rational<int> division = r1/r2;
	
	std::cout << "Somma: " << sum <<"\n";
	std::cout << "Sottrazione: " << substraction <<"\n";
	std::cout << "Prodotto: " << product <<"\n";
	std::cout << "Divisione: " << division <<"\n";

}