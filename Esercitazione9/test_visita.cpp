#include "visita_grafi.hpp"

int main() {

	//grafo su cui provo gli algoritmi
    
	
	undirected_graph<int> G;

	G.add_edge(1,2);
	G.add_edge(1,3);
	G.add_edge(2,4);
	G.add_edge(2,5);
	G.add_edge(3,6);
	G.add_edge(3,7);
	
	
	//algoritmo dfs iterativo
	std::cout<<"\nnodi DFS ierativo\n";
    pila<int> p;
    auto grafo1 = graph_visit(G, 1, p);
	
	std::cout << "\narchi DFS iterativo\n";
    for (auto e : grafo1.all_edges()) {
        std::cout << e << std::endl;
    }
	


	
	//algoritmo bfs
	std::cout<<"\nnodi BFS\n";
    coda<int> c;
    auto grafo2 = graph_visit(G, 1, c);


    std::cout << "\narchi BFS\n";
    for (auto e : grafo2.all_edges()) {
        std::cout << e << std::endl;
    }
	
	
	//algoritmo dfs ricorsivo
	std::cout<<"\nnodi DFS ricorsivo\n";
	auto grafo3 = dfs_ricorsiva(G,1);
	
	std::cout<<"\narchi DFS ricorsivo\n";
	for(auto e: grafo3.all_edges()){
		std::cout << e << std::endl;
	}
	
	
	
	//definisco un grafo pesato
	
	undirected_graph<int> G_peso;

	G_peso.add_edge(1,2,10);
	G_peso.add_edge(1,3,1);
	G_peso.add_edge(3,2,1);
	G_peso.add_edge(2,4,2);
	G_peso.add_edge(3,4,20);
	
	
	//algoritmo cammini minimi 
	std::cout<<"\nnodi cammino minimo\n";
	auto grafo4 = dijkstra(G_peso,1);
	
	std::cout<<"\narchi cammino minimo\n";
	for(auto e: grafo4.all_edges()){
		std::cout << e << std::endl;
	}
	
    return 0;
}