#include <iostream>
using namespace std;

template <class T>
class node {
	private:
		T data;
		node *next;
	
	public:
		node() {
			next = NULL;
		}
		
		node(T d) {
			data = d;
			next = NULL;
		}
		
		node(T d,node* n) {
			data = d;
			next = n;
		}
		
		virtual ~node() {}
		
		T get_data() {
			return data;
		}
		
		node* get_next() {
			return next;
		}
		
		void set_data(T d) {
			data = d;
		}
		
		void set_next(node* n) {
			next = n;
		}
};


template <class T>
class linked_list {
	private:
		node<T> *first, *last;
		int length;
	public:
		linked_list() {
			first = NULL;
			last = NULL;
			length = 0;
		}	
		
		int size() {
			return length;
		}
		
		bool empty() {
			return size == 0;
		}
		
		 void add_head(T d) {
		 	node<T> *new_data = new node<T>(d,first);
		 	this->first = new_data;
		 	if(this->last == NULL) this->last = first;
		 	++length;
		 }
		 
		 void add_tail(T d){
		 	node<T> *new_data = new node<T>(d);
		 	if(this->first == NULL) {
				this->first = new_data;
				this->last = new_data;
			} else {
				this->last->set_next(new_data);
				this->last = new_data;					
			}
			length++;
		 }
		 
		 T remove_head() {
		 	if(this->first == NULL) {
		 		cout<<"List is empty!"<<endl;
			 } else {
			 	node<T> *data = first;
			 	T value = data->get_data();
			 	this->first = this->first->get_next();
			 	delete data;
			 	return value;
			 }
		 }
		 void print_list() {
		 	node<T> *temp = first;
		 	while(temp!=NULL) {
		 		cout<<temp->get_data()<<"->";
		 		temp = temp->get_next();
			 }
			 cout<<endl;
		 }
};


int main() {
	linked_list<int> list;
	list.add_head(1);
	list.add_tail(2);
	list.add_tail(3);
	list.add_tail(4);
	list.add_tail(5);
	list.print_list();
	cout<<list.remove_head()<<" was removed from the list"<<endl;
	list.print_list();
	return 0;
}
