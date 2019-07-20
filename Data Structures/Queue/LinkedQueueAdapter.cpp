#include "SinglyLinkedList.cpp"
#include <iostream>;
using namespace std;

/**
SinglyLinkedList.cpp can be found in
the Linked List folder in this GitHub Repo
**/
template <class T>
class linked_queue_adapter {
	private:
		linked_list<T> list;
	
	public:
		int size() {
			return list.size();
		}
		
		bool empty() {
			return list.empty();
		}
		
		void enqueue(T x) {
			list.add_tail(x);
		}
		
		T dequeue() {
			return list.remove_head();
		}
		
		void print_queue() {
			list.print_list();
		}
};

int main() {
	linked_queue_adapter<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.print_queue();
	queue.dequeue();
	queue.print_queue();
}
