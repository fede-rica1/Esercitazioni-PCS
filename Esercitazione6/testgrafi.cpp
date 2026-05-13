#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "graph.hpp"

int main(){
	
	//testo undirected_edge
	undirected_edge<int> arco1 (2,0);
	undirected_edge<int> arco1_1 (0,2);
	undirected_edge<int> arco2 (7,0);
	undirected_edge<int> arco3 (2,3);
	undirected_edge<int> arco4 (7,4);
	undirected_edge<std::string> arco_parole ("testo", "canzone");
	undirected_edge<int> arco_vuoto;
	
	std::cout << arco1 << "\n";
	
		
	if(arco1.from()!=0 && arco1.to()!=2){
		std::cerr<<"Errore costruttore undirected_graph \n";
		return EXIT_FAILURE;
	}
	
	if(arco_parole.from()!="canzone" && arco_parole.to() != "testo"){
		std::cerr<<"Errore costruttore undirected_graph \n";
		return EXIT_FAILURE;
	}
	
	if(!(arco_vuoto == undirected_edge<int>())){
		std::cerr<<"Errore costruttore undirected_graph \n";
		return EXIT_FAILURE;
	}
	
	if(!(arco1 == arco1_1)){
		std::cerr<<"Errore operator== \n";
		return EXIT_FAILURE;
	}
	
	if(!(arco1 < arco2)){
		std::cerr<<"Errore operator< \n";
		return EXIT_FAILURE;
	}
	
	std::ostringstream os; 
	os << arco1;
	
	if (os.str() != "(0,2)"){
		std::cerr<<"Errore operator<< \n";
		return EXIT_FAILURE;
	}
	
	
	//test su add_edge
	undirected_graph<int> grafo1;
	
	//5 nodi e 4 archi
	grafo1.add_edge(0,2);
	grafo1.add_edge(7,0);
	grafo1.add_edge(2,3);
	grafo1.add_edge(7,4);
	
	//testo se sono stati aggiunti effettivamente 4 archi
	if(grafo1.all_edges().size() != 4){
		std::cerr<<"Errore metodo add_edge nell'aggiunta archi\n";
		return EXIT_FAILURE;
	}
	
	//testo se sono stati aggiunti effettivamente 5 nodi
	if(grafo1.all_nodes().size() != 5){
		std::cerr<<"Errore medoto add_edge nell'aggiunta nodi \n";
		return EXIT_FAILURE;
	}
	
	//edge_number restituisce -1 se l'arco non è presente
	if(grafo1.edge_number(undirected_edge<int>(0,2)) == -1){
		std::cerr<<"Errore medoto add_edge nell'aggiunta archi \n";
		return EXIT_FAILURE;
	}
	
	//test su all_edges
	std::vector<undirected_edge<int>> archi_attesi = {{0,2} , {0,7} , {2,3}, {4,7}};
	
	//all edges contiene già i vettori ordinati perchè la funzione sort
	//agisce ogni volta che aggiugno un arco
	if(grafo1.all_edges() != archi_attesi){
		std::cerr<<"Errore medoto all_edges \n";
		return EXIT_FAILURE;
	}
	
	
	//test su all_nodes
	std::set<int> nodi_attesi = {0,2,3,4,7};
	
	if(grafo1.all_nodes() != nodi_attesi){
		std::cerr<<"Errore medoto all_nodes \n";
		return EXIT_FAILURE;
	}
	
	//test su neighbours
	std::set<int> vicini_zero = {2,7};
	
	if(grafo1.neighbours(0) != vicini_zero){
		std::cerr<<"Errore medoto neighbours \n";
		return EXIT_FAILURE;
	}
	
	//test su edge_number 
	if(grafo1.edge_number(undirected_edge<int> (0,2)) != 0){
		std::cerr<<"Errore medoto edge_number \n";
		return EXIT_FAILURE;
	}
	
	if(grafo1.edge_number(undirected_edge<int> (7,4)) != 3){
		std::cerr<<"Errore medoto edge_number \n";
		return EXIT_FAILURE;
	}
	
	
	//test edge_at 
	if(!(grafo1.edge_at(0) == undirected_edge<int>(0,2))){
		std::cerr<<"Errore medoto edge_at \n";
		return EXIT_FAILURE;
	}
	
	if(!(grafo1.edge_at(3) == undirected_edge<int>(7,4))){
		std::cerr<<"Errore medoto edge_at \n";
		return EXIT_FAILURE;
	}
	
	//test operator-
	undirected_graph<int> grafo2;
	grafo2.add_edge(0,2); //presente nel grafo1
	grafo2.add_edge(2,3); //presente nel grafo1
	grafo2.add_edge(3,4); //non presente nel grafo1
	
	undirected_graph<int> risultato_atteso;
	risultato_atteso.add_edge(7,0);
	risultato_atteso.add_edge(7,4);
	
	undirected_graph<int> risultato = grafo1 - grafo2;
	
	if(!(risultato == risultato_atteso)){
		std::cerr<<"Errore operatore- \n";
		return EXIT_FAILURE;
	}
	
	
	//test costruttore di copia
	undirected_graph<int> copia(grafo1);
	
	if(copia.all_edges()!=grafo1.all_edges()){
		std::cerr<<"Errore costruttore copia \n";
		return EXIT_FAILURE;
	}
	
	if(copia.all_nodes()!=grafo1.all_nodes()){
		std::cerr<<"Errore costruttore copia \n";
		return EXIT_FAILURE;
	}
	
	std::cout <<"Nessun errore\n";
	return EXIT_SUCCESS;
	
}