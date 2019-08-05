#include "UndirectedAdjacencyList.cpp";
template <class V>
void depth_first_search(undirected_graph<V> g, V v) {
	set<V> visited;
	set<V> vertices = g.get_vertices();
	for(auto it = vertices.begin(); it != vertices.end(); it++) {
		if(visited.find(*it) == visited.end()) 
			depth_first_search_visit(g,*it,visited);
	}
}
template <class V>
void depth_first_search_visit(undirected_graph<V> g, V v,set<V> visited) {
	visited.insert(v);
	list<V> edges  = g.get_edges(v);
	for(auto it = edges.begin(); it != edges.end(); it++) {
		if(visited.find(*it) == visited.end())
			depth_first_search_visit(g,*it,visited);
	}
}

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
	depth_first_search(graph,'s');
	
}
