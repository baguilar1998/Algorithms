#include <iostream>
using namespace std;

template <class T>
class queue_node {
	private:
		T data;
		queue_node *next;
	public:
		queue_node() {
			next = NULL;
		}
		
		queue_node(T d) {
			data = d;
			next = NULL;
		}
		
		queue_node(T d, queue_node *n) {
			data = d;
			next = n;
		}
		
		virtual ~queue_node() {}
		
		T get_data() {
			return data;
		}
		
		queue_node* get_next() {
			return next;
		}
		
		void set_data(T d){
			data =d;
		}
		
		void set_next(queue_node *n) {
			next = n;
		}
};

template <class T>
class linked_queue {
	private:
		queue_node<T> *head, *tail;
		int length;
	public:
		linked_queue() {
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		void enqueue(T d) {
			queue_node<T> *new_data = new queue_node<T>(d,NULL);
			if(head == NULL) {
				head = new_data;
				tail = new_data;
			} else {
				tail->set_next(new_data);
				tail = new_data;
			}
			length++;
		}
		
		T dequeue() {
			if(head == NULL) {
				cout<<"Queue is empty!"<<endl;
				return NULL;
			} else {
				queue_node<T> *node = head;
				head = head->get_next();
				T data = node->get_data();
				delete node;
				--length;
				return data;
			}
		}
		
		T peek() {
			if(head == NULL) {
				cout<<"Queue is empty!"<<endl;
				return NULL;
			}
			return head->get_data();
		}
		
		void print_queue(){
			queue_node<T> *temp = head;
			while(temp != NULL) {
				cout<<temp->get_data()<<"->";
				temp = temp->get_next();
			}
			cout<<endl;
		}
};

int main() {
	linked_queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.print_queue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.print_queue();
	cout<<queue.peek()<<endl;
}
