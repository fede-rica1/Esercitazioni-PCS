#include <iostream>

int main()
{
   double ad[4] = {0.0, 1.1, 2.2, 3.3};
   float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
   int ai[3] = {0,1,2};
   
   int x =1;
   float y = 1.1;
   
  
   (&y)[1] = 0; //ricorda che &y restituisce un pointer to float e quando faccio (&y)[1] mi muovo 
   //di una posizione avanti che per un float sono 4 byte
   
   std :: cout << x << "\n";
   std :: cout << &x <<"\n";
   std :: cout << &y <<"\n";
   // dato che la differenza tra l'indirizzo di x e y sono 4 byte io sto modificando quello che c'è all'inidirizzo di x, cioè x  
   //stampo indirizzo array
   
   
   //std :: cout << &ad[2] <<"\n";
   //std :: cout << &ad[1] <<"\n";
   //std :: cout << &af[8] <<"\n";
   //std :: cout << &ai[3] <<"\n";
   
   
   //std :: cout << &x <<"\n";
   //std :: cout << &y <<"\n";
   //std :: cout << (&y)[1] <<"\n"
   return 0;
 }