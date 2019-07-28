#include <list>
#include <map>
#include <set>
#include <iostream>
using namespace std;

template <class V>
class undirected_graph {
	private:
		map<V,list<V>> graph;
		set<V> vertices;
		int edges;
		
	public:
		void add_vertex(V v) {
			if(graph.find(v) != graph.end()) {
				cout<<"Vertex already exists!"<<endl;
				return;
			} else {
				graph[v] = list<V>();
				vertices.insert(v);
			}
		}
		
		void addEdge(V v, V u) {
			if(graph.find(v) == graph.end()) {
				cout<<"Vertex "<<v<<" does not exist!"<<endl;
				return;
			} else if (graph.find(u) == graph.end()) {
				cout<<"Vertex "<<u<<" does not exist!"<<endl;
				return;
			}
			graph[v].push_back(u);
			graph[u].push_back(v);
			edges++;
		}
		
		void remove_vertex(V v) {
			if(graph.find(v) == graph.end()) {
				cout<<"Vertex does not exist!"<<endl;
			}
			auto v_vertex = vertices.find(v);
			auto g_vertex = graph.find(v);
			for(auto it1 = vertices.begin(); it1 != vertices.end(); it1++) {
				graph[*it1].remove(v);
			}
			vertices.erase(v);
			graph.erase(v);
		}
		
		void remove_edge(V v, V u) {
			if(graph.find(v) == graph.end()) {
				cout<<"Vertex "<<v<<" does not exist!"<<endl;
				return;
			} else if (graph.find(u) == graph.end()) {
				cout<<"Vertex "<<u<<" does not exist!"<<endl;
				return;
			}
			graph[v].remove(u);
			graph[u].remove(v);
			edges--;
		}
		void print_graph() {
			for(auto it1 = vertices.begin(); it1 != vertices.end(); it1++) {
				cout<<"["<<*it1<<"]"<<":";
				list<V> adj = graph[*it1];
				for(auto it2 = adj.begin(); it2 != adj.end(); it2++){
					cout<<"["<<*it2<<"]"<<"->";
				}
				cout<<endl;
			}
		}
		
};

int main() {
	undirected_graph<char> graph;
	// Add vertices
	graph.add_vertex('r');
	graph.add_vertex('s');
	graph.add_vertex('t');
	graph.add_vertex('u');
	graph.add_vertex('v');
	graph.add_vertex('w');
	graph.add_vertex('x');
	graph.add_vertex('y');
	//Add Edges
	graph.addEdge('r','s');
	graph.addEdge('r','v');
	graph.addEdge('s','w');
	graph.addEdge('w','t');
	graph.addEdge('w','x');
	graph.addEdge('t','x');
	graph.addEdge('t','u');
	graph.addEdge('x','u');
	graph.addEdge('x','y');
	graph.addEdge('u','y');
	graph.print_graph();
	graph.print_graph();
}
