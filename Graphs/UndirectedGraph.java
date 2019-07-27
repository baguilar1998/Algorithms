import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class UndirectedGraph<V> {
	private Hashtable<V,LinkedList<V>> graph;
	private Hashtable<V,HashMap<V,Integer>> shortestDistance;
	private int vertices, edges;
	
	public UndirectedGraph() {
		graph = new Hashtable<V, LinkedList<V>>();
		shortestDistance = new Hashtable<V, HashMap<V,Integer>>();
		vertices = 0;
		edges = 0;
	}
	
	
	public void addVertex(V v) throws Exception {
		if(graph.get(v) != null) {
			throw new Exception("Vertex already exists");
		}
		
		graph.put(v, new LinkedList<V>());
		vertices++;
	}
	
	public void addEdge(V v, V u) throws Exception {
		if(!graph.containsKey(v) || !graph.containsKey(u)) {
			throw new Exception("Vertices do not exist");
		}
		graph.get(v).add(u);
		graph.get(u).add(v);
		edges++;
	}
	
	public void BFS(V s) {
		HashSet<V> visited = new HashSet<V>();
		HashMap<V,Integer> distance = new HashMap<V,Integer>();
		shortestDistance.put(s, new HashMap<>());
		for(V v : graph.keySet()) {
			distance.put(v, 0);
		}
		visited.add(s);
		Queue<V> q = new LinkedList<V>();
		q.add(s);
		while(q.size()!=0) {
			V u = q.remove();
			for(V v : graph.get(u)) {
				if(!visited.contains(v)) {
					visited.add(v);
					int d = distance.get(u) + 1;
					distance.replace(v,d);
					q.add(v);
				}
			}
		}
		
		for(V v: distance.keySet()) {
			if(v.equals(s))
				continue;
			shortestDistance.get(s).put(v, distance.get(v));
		}
	}
	
	public void printShortestDistance(V v) throws Exception{
		HashMap<V,Integer> s = shortestDistance.get(v);
		if(s == null) {
			throw new Exception("Distance not calculated");
		}
		System.out.println("SHORTEST DISTANCE AT EVERY VERTEX FROM VERTEX " + v);
		for(V u: s.keySet()) {
			System.out.println("sp("+v+ ","+u+") = " + s.get(u));
		}
	}
	
	public Set<V> getVertices() {
		return graph.keySet();
	}
	
	public String toString() {
		return graph.toString();
	}
}
