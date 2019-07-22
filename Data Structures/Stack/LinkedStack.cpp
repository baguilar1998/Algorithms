#include <iostream>
using namespace std;

template <class T>
class stack_node {
	private:
		T data;
		stack_node *next;
	public:
		stack_node() {
			next = NULL;
		}
		
		stack_node(T d) {
			data = d;
			next = NULL;
		}
		
		stack_node(T d, stack_node *n) {
			data = d;
			next = n;
		}
		
		virtual ~stack_node() {}
		
		T get_data() {
			return data;
		}
		
		stack_node* get_next() {
			return next;
		}
		
		void set_data(T d) {
			data = d;
		}
		
		void set_next(stack_node* n) {
			next = n;
		}
};

template <class T>
class linked_stack {
	private:
		stack_node<T>* top;
		int length;
	public:
		linked_stack() {
			top = NULL;
			length = 0;
		}
		
		int size() {
			return length;
		}
		
		bool empty() {
			return length == 0;
		}
		
		void push(T x) {
			stack_node<T>* new_data = new stack_node<T>(x,top);
			this->top = new_data;
			length++;
		}
		
		T peek() {
			if(this->top != NULL) {
				return this->top->get_data();
			}
		}
		
		T pop() {
			if(this->top == NULL) {
				cout<<"Stack is empty!"<<endl;
			} else {
				stack_node<T>* node = this->top;
				this->top = this->top->get_next();
				--length;
				T data = node->get_data();
				delete node;
				return data;
			}
			
		}
		
		void print_stack() {
			stack_node<T>* temp = top;
			while(temp != NULL) {
				cout<<temp->get_data()<<"->";
				temp = temp->get_next();
			}
			cout<<endl;
		}
};

int main() {
	linked_stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.print_stack();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
}
