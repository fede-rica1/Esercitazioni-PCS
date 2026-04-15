#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


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

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	if (vec.size() < 2) return;;
	
    for (size_t j = 1; j< vec.size(); j++)
    {
        T key = vec[j];
        size_t i = j;
        while (i > 0 && vec[i-1]>key)
        {   
            vec[i] = vec [i-1];
            i--;
        }
        vec[i] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
	if (vec.size() < 2) return;;
	
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