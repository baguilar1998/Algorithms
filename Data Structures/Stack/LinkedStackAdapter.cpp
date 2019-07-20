#include "SinglyLinkedList.cpp"
#include <iostream>;
using namespace std;

/**
SinglyLinkedList.cpp can be found in
the Linked List folder in this GitHub Repo
**/
template <class T>
class linked_stack_adapter {
	private:
		linked_list<T> list;
	
	public:
		int size() {
			return list.size();
		}
		
		bool empty() {
			return list.empty();
		}
		
		void push(T x) {
			list.add_head(x);
		}
		
		T pop() {
			return list.remove_head();
		}
		
		void print_stack() {
			list.print_list();
		}
};

int main() {
	linked_stack_adapter<int> stack;
	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	stack.print_stack();
	stack.pop();
	stack.print_stack();
}
