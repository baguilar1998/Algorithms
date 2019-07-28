#include "UndirectedAdjacencyList.cpp";
#include <queue>


template <class V>
void breadth_first_search(undirected_graph<V> g, V v) {
	static map<V,int> distance; 
	set<V> vertices = g.get_vertices();
	for(auto it = vertices.begin(); it != vertices.end(); it++) {
		if(*it == v)
			continue;
		distance[*it] = 0;
	}
	
	queue<V> q;
	set<V> visited;
	q.push(v);
	while(q.size() != 0) {
		V u = q.front();
		q.pop();
		list<V> edges = g.get_edges(u);
		for(auto it = edges.begin(); it != edges.end(); it++) {
			if(visited.find(*it) == visited.end()) {
				visited.insert(*it);
				distance[*it] = distance[u]+1;
				q.push(*it);
			}
			visited.insert(u);
		}
	}
	
	cout<<"Shortest distance at every vertex from vertex "<<v<<endl;
		for(auto it = vertices.begin(); it != vertices.end(); it++) {
		if(*it == v)
			continue;
		cout<<"sp("<<v<<","<<*it<<") = "<<distance[*it]<<endl;
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
	breadth_first_search(graph,'s');
	
}
