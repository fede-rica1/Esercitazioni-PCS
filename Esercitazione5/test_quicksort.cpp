//test quick sort

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "randfiller.h"
#include "sorting_algorithms.h"


int main(void){
	randfiller rf;
	
	//definisco i parametri del testing
	int N = 100;
	int range = 100;
	
	std::vector<int> dimensioni; //vettore con le dimensioni casuali
	dimensioni.resize(N); //devo testare il sorting per 100 dimensioni
	rf.fill(dimensioni, 0, range);
	
	for (int i=0; i < N; i++){
		std::vector<int> vettore;
		vettore.resize(dimensioni[i]);
		rf.fill(vettore, -10000,10000);
		print_vector(vettore); //print prima di sortare
		
		quick_sort(vettore, 0, vettore.size()-1);
		is_sorted(vettore);
		print_vector(vettore); //print dopo aver sortato
		std::cout<<"\n";
		
	}
	
	std::vector<std::string> stringhe = {"matita", "gomma", "penna", "computer", "astuccio", "zaino", "quaderno", "libro", "appunti", "righello"};
	
	quick_sort(stringhe, 0, stringhe.size()-1);
	is_sorted(stringhe);
	print_vector(stringhe);
	
}