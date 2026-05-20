#pragma once //evita inclusioni multiple dello stesso header file
#include <set>
#include <map>
#include <limits>
#include "graph.hpp" //struttura grafo
#include "coda_pila.hpp" //definizione di coda e pila


template <typename T, typename Contenitore>
undirected_graph<T> graph_visit(const undirected_graph<T>& grafo, const T& nodo_sorgente, Contenitore& c) {
    
    undirected_graph<T> albero_visita;
    std::map<T,bool> reached;      
    std::map<T, T> padre_figlio; 
    
	//controllo se devo usare l'algoritmo dfs 
    if (c.is_dfs()) {
     
		//inserisco il nodo sorgente nella pila
        c.put(nodo_sorgente);
		
        while (!c.empty()) { 
			
			//estraggo il nodo in cima alla pila
            T nodo_corrente = c.get();
			
            
            //se ho già visitato il nodo ricontrollo la condizione di while
            if (reached[nodo_corrente]) {
                continue;
            }
            
            reached[nodo_corrente]=true;
			
			//stampa di controllo per verificare la corretta visita dei nodi
			std::cout<<nodo_corrente<< " ";
            
            if (nodo_corrente != nodo_sorgente) {
                albero_visita.add_edge(padre_figlio[nodo_corrente], nodo_corrente);
            }
            
			//estraggo i vicini e itero sul set
            std::set<T> vicini = grafo.neighbours(nodo_corrente);
			
			//posso modificare la funzione inserendo rbegin() e rend() per visitare
			//i nodi dal più piccolo al più grande
            for (auto iteratore = vicini.begin(); iteratore != vicini.end(); iteratore++) {
                T nodo_vicino = *iteratore;
                
                if (!reached[nodo_vicino]) {
                    padre_figlio[nodo_vicino] = nodo_corrente;  //il padre viene "aggiornato" per andare in profonità nel ramo
                    c.put(nodo_vicino);
                }
            }
        }
    } 
	
	
	
	//utilizzo l'algoritmo bfs
    else {
       
        c.put(nodo_sorgente);
        reached[nodo_sorgente] = true; 
        
        while (!c.empty()) { 
            T nodo_corrente = c.get();  
			
			//stampa di controllo per verificare la corretta visita dei nodi
			std::cout<<nodo_corrente<< " ";
            
            if (nodo_corrente != nodo_sorgente) {
                albero_visita.add_edge(padre_figlio[nodo_corrente], nodo_corrente);
            }
            
            std::set<T> vicini = grafo.neighbours(nodo_corrente);
            for (auto iteratore = vicini.begin(); iteratore != vicini.end(); iteratore++) {
                T nodo_vicino = *iteratore;
                
                if (!reached[nodo_vicino]) {
                    reached[nodo_vicino]=true;  
                    padre_figlio[nodo_vicino] = nodo_corrente;  // Il primo padre rimane definitivo
                    c.put(nodo_vicino);
                }
            }
        }
    }	
    
    return albero_visita;
}



//definizione di visita usando l'algoritmo dfs
template <typename T>
void visita_dfs(
	const undirected_graph<T>& grafo,
	const T& nodo_corrente,
	std:: map<T,bool>& reached,
	undirected_graph<T>& albero_visita){
					
	reached[nodo_corrente]=true;
	
	std::cout<<nodo_corrente<<" ";
	
	std::set<T> vicini = grafo.neighbours(nodo_corrente);
	
	for(auto iteratore = vicini.begin(); iteratore != vicini.end(); iteratore++){
		
		T vicino = *iteratore;
		
		if(!reached[vicino]){
			
			//aggiungo l'arco tra il nodo corrente e il suo vicino non ancora visitato
			albero_visita.add_edge(nodo_corrente, vicino);
			
			
			//il nodo vicino che non era ancora stato visitato diventa il nodo corrente nella prossima dfs visit
			visita_dfs(grafo, vicino, reached, albero_visita);
		}
	}					
}


//funzione che chiama la dfs
template <typename T>
undirected_graph<T> dfs_ricorsiva(
	const undirected_graph<T>& grafo,
	const T& nodo_sorgente){
		
	undirected_graph<T> albero_visita;
		
	std::map<T, bool> reached;
		
	visita_dfs(
		grafo,
		nodo_sorgente,
		reached,
		albero_visita);
	
	return albero_visita;
		
}



//algoritmo dijkstra
template <typename T>

//la funzione restiuisce un unico albero che indica il cammino minimo 
//questo per il lemma sulla sovrapposizione dei cammini minimi
undirected_graph<T> dijkstra(const undirected_graph<T>& grafo, const T nodo_sorgente){
	
	undirected_graph<T> albero_cammino_minimo;
	std::map<T, int> distanze;
	std::map<T,T> padre_figlio;
	
	//definisco tutte le distanza dei nodi dalla sorgente a infinito
	const int INFINITO = std::numeric_limits<int>::max();
	
	std::set<T> nodi = grafo.all_nodes();
	for (auto iteratore = nodi.begin(); iteratore !=nodi.end(); iteratore++){
		T nodo = *iteratore;
		distanze[nodo] = INFINITO;
	}
	
	//definisco i dati di distanza e padre per il nodo sorgente
	distanze[nodo_sorgente] = 0;
	padre_figlio[nodo_sorgente] = nodo_sorgente;
	
	//definisco la coda di priorità come un set di coppie in cui ho distanza dalla sorgente e nodo corrispondente
	std::set<std::pair<int,T>> coda_priorita; //la coda di priorità è ordinata per distanza
	coda_priorita.insert({0, nodo_sorgente});
	
	
	while(!coda_priorita.empty()){
		
		auto piu_vicino = *coda_priorita.begin(); //sto deferenziando il primo elemento della coda di priorità
		T nodo_corrente = piu_vicino.second; //accedo al secondo elemento della coppia
		coda_priorita.erase(coda_priorita.begin());
		
		std::cout<<nodo_corrente<<" ";
		
		
		if(nodo_corrente != nodo_sorgente){
			undirected_edge<T> arco(padre_figlio[nodo_corrente], nodo_corrente);
			int peso_definitivo = grafo.get_peso_from_arco(arco);
			albero_cammino_minimo.add_edge(padre_figlio[nodo_corrente], nodo_corrente, peso_definitivo);

		}
		
		std::set<T> vicini = grafo.neighbours(nodo_corrente);
		for (auto iteratore = vicini.begin(); iteratore!=vicini.end(); iteratore++){
			
			T vicino = *iteratore;
			undirected_edge<T> arco(nodo_corrente, vicino);
			int peso = grafo.get_peso_from_arco(arco);
			
			if(distanze[nodo_corrente] + peso < distanze[vicino]){
				
				if (distanze[vicino] != INFINITO) {
                    coda_priorita.erase({distanze[vicino], vicino});
                }
				
				distanze[vicino] = distanze[nodo_corrente] + peso;
				padre_figlio[vicino] = nodo_corrente;
				
				coda_priorita.insert({distanze[vicino], vicino});
			}
		}
	}
	
	return albero_cammino_minimo;
	
	
}