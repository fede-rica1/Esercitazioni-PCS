#include <iostream>
#include <cmath>

int main(){
    static const int N = 10;
	double arr[N] = {1.1, 3.0, 2.0, 6.0, 5.0, 4.0, 7.0, 8.0, 9.0, 10.5};
	int swaps = 1;
	
	while (swaps!=0){
		
		swaps = 0;
		
		for (int i = 0; i<N-1; i++){
			if (arr[i]>arr[i+1]){
				double maggiore = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = maggiore;
				swaps = swaps +1;
				}
		}

	}
	for (int i = 0; i<N; i++){
		std::cout << arr[i] << " ";
	}
}