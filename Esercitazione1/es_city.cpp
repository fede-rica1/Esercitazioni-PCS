#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[])
{
if(argc < 2){  // faccio un controllo sul numero di parametri inseriti
cout << "L'input inserito non è corretto";
return 1;
}
ifstream ifs(argv[1]);
if ( ifs.is_open() ) {  //controllo che il file sia stato aperto
	string città;
	double t1, t2, t3, t4;
	while (ifs >> città >> t1 >> t2 >> t3 >> t4){
	double t = t1 + t2 + t3 + t4;
	double media = t/4;
	
	
	cout <<città << " "<< media << "\n";
	}
}
else{
	cout << "Il file non può essere aperto correttamente \n";
}
return 0;
}

