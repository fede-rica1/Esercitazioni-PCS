#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include "randfiller.h"
#include "timecounter.h"
#include "sorting_algorithms.h"

using namespace std;



//confrontare gli algoritmi per vettori di dimensioni minori di 100
int main(){
	randfiller rf;
	
	const int N = 100;
	
	//apertura del file in cui salvo i tempi di sorting dei vettori
	ofstream file("sort.csv");
	
	if(!file.is_open()){
		cout << "Errore apertura file\n";
		return 1;
	}
	file<< "Dimensione, Bubblesort, Insertionsort, Selectionsort, Mergesort, Quicksort, Quicksort_ottimo, Standardsort\n";
	
	for (int dim = 2; dim <=N; dim++){
		
		//costruisco un vettore di vettori
		vector<vector<int>> tabella(N,vector<int>(dim));
		
        for(size_t j = 0; j<N; j++)
        {
            rf.fill(tabella[j],-10000,10000);
        }
        vector<vector<int>> vec_bubble = tabella;
        vector<vector<int>> vec_insertion = tabella;
        vector<vector<int>> vec_selection = tabella;
        vector<vector<int>> vec_merge = tabella;
        vector<vector<int>> vec_quick = tabella;
		vector<vector<int>> vec_quick_ottimo = tabella;
		vector<vector<int>> vec_std = tabella;
		
		timecounter tc;
		
		//BUBBLESORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            bubble_sort(vec_bubble[k]);
        }
        double tbub = tc.toc()/N;
		
		//INSERTIONSORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            insertion_sort(vec_insertion[k], 0, vec_insertion[k].size()-1);
        }
        double tins = tc.toc()/N;
		

		//SELECTIONSORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            selection_sort(vec_selection[k]);
        }
        double tsel = tc.toc()/N;
		
		//MERGESORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            merge_sort(vec_merge[k], 0, vec_merge[k].size()-1);
        }
        double tmerge = tc.toc()/N;
		
		//QUICKSORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            quick_sort(vec_quick[k], 0, vec_quick[k].size()-1);
        }
        double tquick = tc.toc()/N;
		
		//QUICKSORT_OTTIMO
		tc.tic();
        for (size_t k = 0; k<N; k++)
        {
            quicksort_ottimo(vec_quick_ottimo[k], 0, vec_quick_ottimo[k].size()-1);
        }
        double tquick_ottimo = tc.toc()/N;
		
		//STANDARDSORT
		tc.tic();
        for (int k = 0; k < N; k++)
        {
            sort(vec_std[k].begin(), vec_std[k].end());
        }
        double tstd = tc.toc()/N;
		
		string migliore;
        double miglior_tempo = tbub;
        migliore = "Bubblesort";

        if (tins<miglior_tempo)
        { 
            miglior_tempo = tins;
            migliore = "Insertionsort";
        }


        if (tsel<miglior_tempo)
        { 
            miglior_tempo = tsel;
            migliore = "Selectionsort";
        }


        if (tmerge<miglior_tempo)
        { 
            miglior_tempo = tmerge;
            migliore = "Merge Sort";
        }


        if (tquick<miglior_tempo)
        { 
            miglior_tempo = tquick;
            migliore = "Quick Sort";
        }
		
		
		if (tquick_ottimo<miglior_tempo)
        { 
            miglior_tempo = tquick_ottimo;
            migliore = "Quick Sort Ottimo";
        }
		
		
		if (tstd<miglior_tempo)
        { 
            miglior_tempo = tstd;
            migliore = "Standard Sort";
        }


        cout << "Tempi di esecuzione per un vettore di dimensione " << dim << ":\n";
        cout << "Bubblesort:" << tbub << "\n";
        cout << "Insertionsort:" << tins << "\n";
        cout << "Selectionsort:" << tsel << "\n";
        cout << "Mergesort:" << tmerge << "\n";
        cout << "Quicksort:" << tquick << "\n";
		cout << "Quicksort Ottimo:" << tquick_ottimo <<"\n";
		cout << "Standardsort:" << tstd << "\n";
        cout << "il più veloce è stato:" << " "<< migliore;
        cout << " con" << " "<< miglior_tempo << "s" << "\n";
		
		
		file << dim << ","<< tbub <<","<< tins <<","<< tsel <<","<< tmerge <<","<< tquick <<","<< tquick_ottimo<<","<< tstd<<"\n";

    }
    file.close();
    return 0;
}
