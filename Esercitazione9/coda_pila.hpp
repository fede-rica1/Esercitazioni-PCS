#include <queue>
#include <stack>

//coda politica FIFO
template <typename T>
class coda {
	
	private:
	std::queue<T> c;
		
	public:
	coda() = default;
	
	void put(const T& element){
		c.push(element); //utilizzo il metodo push della contenitore queue
	}
	
	T get() {
		T element = c.front();
		c.pop();
		return element;
	}
	
	bool empty() const{
		return c.empty();
	}
	
	//aggiungo questo metodo per il bfs
	bool is_dfs() const {
		return false;
	}
};
	
//pila politica LIFO
template <typename T>
class pila {
	
	private: 
	std::stack<T> p;
		
	public:
	pila() = default;
	
	void put(const T& element){
		p.push(element);
	}
	
	T get(){
		T element = p.top();
		p.pop();
		return element;
	}
	
	bool empty() const{
		return p.empty();
	}
	
	//metto questo metodo per il dfs
	bool is_dfs() const{
		return true;
	}
};