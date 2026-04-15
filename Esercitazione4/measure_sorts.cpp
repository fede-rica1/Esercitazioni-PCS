#include <iostream>
#include <algorithm>
#include <vector>
#include "randfiller.h"
#include "timecounter.h"
#include "sorting_algorithms.h"

int main(){
	randfiller rf;
	for (int i = 4; i <=8192; i*=2){
		std::vector<int> vettore;
		vettore.resize(i);
		rf.fill(vettore, -10000,10000);
		
		//BUBBLESORT
		timecounter tc;
		tc.tic();
		bubble_sort(vettore);
		double bubble = tc.toc();
		std::cout << bubble << " seconds for bubble_sort\n";
		
		//INSERTIONSORT
		tc.tic();
		insertion_sort(vettore);
		double insertion = tc.toc();
		std::cout << insertion << " seconds for insertion_sort\n";
		

		//SELECTIONSORT
		tc.tic();
		selection_sort(vettore);
		double selection = tc.toc();
		std::cout << selection << " seconds for selection_sort\n";
		
		//STANDARDSORT
		tc.tic();
		std::sort(vettore.begin(), vettore.end());
		double standard = tc.toc();
		std::cout << standard << " seconds for standard_sort\n";
		
		std::cout<<"\n";
	}
}
