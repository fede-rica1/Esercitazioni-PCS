#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

//implemento la classe undirected_edge
template<typename T>
class undirected_edge {
	
	T nodo1;
	T nodo2;
	int peso; //peso 
	
	public:
	//default constructor
	undirected_edge(): nodo1(T()), nodo2(T()), peso(1) {}
	
	//user defined constrcutor, pass by const reference
	undirected_edge(const T& n1, const T& n2, int p = 1) : peso(p) {
		//diamo ai due nodi un ordine dentro il costruttore 
		//in questo modo il nodo più piccolo è il primo 
		if(p<0){
			std::cout<<"Il peso deve essere positivo\n";
			peso = 1;
		}
		
		
		if (n1 < n2){
			nodo1 = n1;
			nodo2 = n2;
		}
		else{
			nodo1 = n2;
			nodo2 = n1;
		}
	}
	
	//definizione dei metodi from() e to()
	T from() const {return nodo1;}
	T to() const {return nodo2; }

	//aggiungo un metodo per ottenere il peso di un arco
	int get_peso() const {return peso;}
	
	//definizione degli operatori 
	bool operator<(const undirected_edge& other_edge) const {
		if (nodo1 != other_edge.from()){
			return nodo1 < other_edge.from();
		}
		return nodo2 < other_edge.to();
	}
	
	bool operator==(const undirected_edge&  other_edge) const {
		if(nodo1 == other_edge.from() && nodo2 == other_edge.to()){
			return true;
		}
		return false;
	}
	
};

template<typename T>
std::ostream &operator<<(std::ostream& os, const undirected_edge<T>& edge){
	os << "(" << edge.from() << "," << edge.to() << ")";
	
	return os;
}


//implemento la classe undirected_graph
template <typename T>
class undirected_graph{
	
	//la classe è costituita da una mappa in cui la chiave è il nodo
	//e come valore associo il set dei suoi vicini
	private:
	std::map<T, std::set<T>> grafo;
	
	//creo un vettore contenete gli undirected_edge della classe definita sopra
	std::vector<undirected_edge<T>> archi; 
	
	public:
	//default constructor
	undirected_graph(){};
	
	//costruttore di copia
	undirected_graph(const undirected_graph<T>& other){
		//*this significa vai all'indirizzo del nuovo oggetto che ho creato
		(*this).grafo = other.grafo;
		(*this).archi = other.archi;
	}
	
	
	//metodo neighbours che prende come input un nodo e restituisce la lista di adiacenza
	std::set<T> neighbours(T nodo) const{
		return (*this).grafo.at(nodo);
	}
	
	//metodo all_nodes che restituisce il set dei nodi nel grafo
	std::set<T> all_nodes() const {
		std::set<T> nodi;
		
		//itero sulla mappa
		for (auto const& it: (*this).grafo){
			nodi.insert(it.first);
		}
		return nodi;
	}
	
	//metodo add_edge che utilizza il costruttore dell'arco 
	void add_edge(T nodo1, T nodo2, int peso = 1) {
		
		undirected_edge<T> nuovo_arco(nodo1, nodo2, peso);
		
		//aggiorno il vettore degli archi
		(*this).archi.push_back(nuovo_arco);
		
		//ordino il vettore degli archi quando inserisco l'arco per non 
		//dover ordinare dopo negli altri metodi
		
		std::sort((*this).archi.begin(), (*this).archi.end());
		
		//aggiorno la lista dei vicini per entrambi i nodi
		(*this).grafo[nuovo_arco.from()].insert(nuovo_arco.to());
		(*this).grafo[nuovo_arco.to()].insert(nuovo_arco.from());
	}
	
	
	//metodo all_edges ritorna il vettore ordinato perchè viene ordinato man mano
	std::vector<undirected_edge<T>> all_edges() const{
		std::vector<undirected_edge<T>> lista_archi = (*this).archi;
		return lista_archi;
	}
	
	//metodo edge_at() che restituisce l'arco in posizione i
	undirected_edge<T> edge_at(size_t i) const{
		if (i< (*this).archi.size()){
			return archi[i];
		}
		throw std::out_of_range("Indice arco fuori dai limiti");
	}
	
	//metodo edge_number che restituisce la posizione dell'arco
	int edge_number(undirected_edge<T> arco) const{
		
		//itero sul vettore degli archi
		for(size_t i = 0; i < (*this).archi.size(); i++){
			if (archi[i] == arco){
				return static_cast<int>(i); //passo da size_t a int
			}
		}
		//valore che restituisco quando l'arco non è presente
		return -1;
	}
	
	
	//metodo che restituisce il peso dell'arco
	int get_peso_from_arco(const undirected_edge<T>& arco) const {
		for (size_t i = 0; i < (*this).archi.size(); i++) {
       
			if (((*this).archi[i].from() == arco.from() && (*this).archi[i].to() == arco.to()) ||
				((*this).archi[i].from() == arco.to() && (*this).archi[i].to() == arco.from())) {
				return (*this).archi[i].get_peso();
			}
		}
		return 2;
	}
	
	
	//operatore ==
	bool operator==(const undirected_graph<T>& other) const {
    return this->archi == other.archi;
	}
	
	//operatore differenza tra due grafi
	undirected_graph<T> operator-(const undirected_graph<T>& other_graph){
		
		undirected_graph<T> risultato;
		
		//itero sugli archi di entrambi i grafi
		for (size_t i=0; i < (*this).archi.size(); i++){
			
			bool trovato_in_other = false;
			
			for (size_t j=0; j<other_graph.archi.size(); j++){
				if((*this).archi[i] == other_graph.archi[j]){
					trovato_in_other =true;
					break;
				}	
			}
			
			//se trovato_in_other resta false allora lo aggiungo 
			// all'arco differenza con il metodo add_grapf
			if (!trovato_in_other){
				risultato.add_edge((*this).archi[i].from(), (*this).archi[i].to());
			}
		}
		
		return risultato;
		
	}
};