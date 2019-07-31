#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>
using namespace std;

template <class T>
class disjoint_sets {
	private:
		map<T,list<T>*> sets;
		set<T> keys;
	public:
		void make_set(T x) {
			if(sets.find(x) == sets.end()) {
				sets[x] = new list<T>();
				keys.insert(x);
				sets[x]->push_back(x);
			}
		}
		
		list<T> find_set(T x) {
			return sets[x];
		}
		
		void join_sets(T x, T y) {
			list<T> *s1 = sets[x];
		    list<T> *s2 = sets[y];
			if(s1 == s2)
				return;
			for(auto it = s2->begin(); it != s2->end(); it++)
				s1->push_back(*it);
			delete s2;
			sets[x] = s1;
			sets[y] = s1;
		}
		
		void print_sets() {
			set<list<T>*> printedSets;
			for(auto it1 = keys.begin(); it1 != keys.end(); it1++) {
				list<T>* set = sets[*it1];
				if(printedSets.find(set) != printedSets.end())
					continue;
				cout<<"{";
				int counter = 0;
				for(auto it2 = set->begin(); it2 != set->end(); it2++) {
					if(counter == set->size()-1) {
						cout<<*it2;
					} else {
						cout<<*it2<<",";
					}
					counter++;
				}
				cout<<"} ";
				printedSets.insert(set);
			}
			cout<<endl;
		}
};

int main() {
	disjoint_sets<char> sets;
	char c = 'a';
	for(int i = 0; i < 10; i++)
		sets.make_set(c++);
	sets.print_sets();
	sets.join_sets('b','d');
	sets.print_sets();
}
