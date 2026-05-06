#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

//BUBBLE SORT
template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	if (vec.size() < 2) return;;
	
    for (size_t i = 0; i< vec.size()-1; i++)
    {
        for (size_t j = vec.size() -1; j > i; j--)
        {
            if (vec[j]<vec[j-1])
            {   
                T min = vec [j];
                vec[j] = vec[j-1];
                vec [j-1] = min;
            }
        }
    }
}


//INSERTION SORT
template<typename T>
void insertion_sort(std::vector<T>& vec, size_t start, size_t end)
{
	if (vec.size() < 2) return;
	
    for (size_t j = start+1; j<=end; j++)
    {
        T key = vec[j];
        size_t i = j;
        while (i > start && vec[i-1]>key)
        {   
            vec[i] = vec [i-1];
            i--;
        }
        vec[i] = key;
    }
}

//SELECTION SORT
template<typename T>
void selection_sort(std::vector<T>& vec)
{
	if (vec.size() < 2) return;
	
    for (size_t i = 0; i<vec.size()-1; i++)
    {
        size_t min = i;
        for (size_t j = i+1; j<vec.size(); j++)
        {
            if (vec[j]<vec[min])
            {
                min = j;   
            }
        }
        T swap = vec[i];
        vec[i] = vec[min];
        vec[min] = swap;
    }
}


//MERGE SORT
template<typename T>
void my_merge(std::vector<T>& vec, size_t start, size_t middle, size_t end){
	
	
	//size vettore sinistra
	size_t n1 = middle - start + 1;
	
	//size vettore destra
	size_t n2 = end - middle;
	
	//creo i vettori e li riempio
	std::vector<T> left;
	left.resize(n1); //si poteva aggiungere un posto in più alla fine in cui metto infinito e modificare il codice di mymerge 
	//però in questo caso dovrei separare il caso di infinito riferito ai limiti numerici e l'infinito per i confronti con char
	for (size_t i = 0; i < n1; i++){
		left[i] = vec[start + i];
	}

	
	std::vector<T> right;
	right.resize(n2);
	for (size_t j = 0; j < n2; j++){
		right[j] = vec[middle +1+ j];
	}
	
	size_t i = 0;
	size_t j = 0;
	size_t k = start;

	while (i < n1 && j < n2){
		if (left[i] <= right[j]) {
			vec[k] = left[i];
			i++;
		} else {
			vec[k] = right[j];
			j++;
		}
		k++;
	}
	
	while (i < n1){
		vec[k] = left[i];
		i++;
		k++;
    }
	
	while (j < n2){
		vec[k] = right[j];
		j++;
		k++;
	}
	
}


template<typename T>
void merge_sort(std::vector<T>& vec, size_t start, size_t end)
{   
	if (vec.size() < 2) return;
	
	//inserisco una condizione di uscita dalla funzione ricorsiva
	if  (start >= end) {
		return;
	}
	
	size_t middle = (start + end) / 2;  //se il risultato è 2.5 restituisce 2
				
	merge_sort(vec, start, middle);
	merge_sort(vec, middle + 1, end);			
	my_merge(vec, start, middle, end);
}


//QUICK SORT
template<typename T>
size_t partition(std::vector<T> &vec, size_t start, size_t end){
	T x = vec[end]; // sto automaticamente prendendo come pivot l'ultimo elemento
	size_t  i = start; //indica la separation tra i numeri più piccoli del nostro pivot
	for (size_t j = start;  j < end; j++){
		if(vec[j]<=x){
			std:: swap(vec[i], vec[j]);
			i++;
		}
	}
	std::swap(vec[i],vec[end]);
	return i;
}

template<typename T>
void quick_sort(std::vector<T> &vec, size_t start, size_t end){
	
	if (vec.size() < 2) return;
	
	if (start < end){
		size_t rango = partition(vec, start, end);
		if (rango>0){
			quick_sort(vec, start, rango -1);
		}
		quick_sort(vec, rango + 1, end);
	}
}



template<typename T>
void quicksort_ottimo(std::vector<T> &vec, size_t start, size_t end){
	
	if (vec.size() < 2) return;
	
	if (start >= end) return;
	
	size_t dim = end - start + 1;
	
	if (dim <20){
		insertion_sort(vec, start, end);
		return;
	}
	else{
		
		size_t rango = partition(vec, start, end);
		if (rango>0){
			quicksort_ottimo(vec, start, rango -1);
		}
		quicksort_ottimo(vec, rango + 1, end);
	
	}
	
}


//controllo se un vettore è ordinato
template<typename T>
int is_sorted(const std::vector<T>& vec)
{   
	if (vec.size()<2){
		std::cout<<"Il vettore è ordinato"<<"\n";
		return EXIT_SUCCESS;
	}
	
    for (size_t i = 0; i < vec.size()-1; i++)
    {
        if (vec[i]>vec[i+1])
        {
			//c'è almeno un elemento del vettore non ordinato
			std::cout<<"Il vettore non è ordinato"<<"\n";
            return EXIT_FAILURE;
        }
    }    
	//il vettore è ordinato
	std::cout<<"Il vettore è ordinato"<<"\n";
    return EXIT_SUCCESS;
}

//print vector
template<typename T>
void print_vector(const std::vector<T>& vec){
	
	if (vec.empty())  return;
	
	for (size_t i = 0; i<vec.size(); i++){
		std::cout << vec[i] <<" ";
	}
	std::cout << "\n";
}