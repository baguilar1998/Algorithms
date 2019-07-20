#include <iostream>
using namespace std;

template <class T>
class array_stack {
	private:
		int capacity, top;
		T* arr;
	public:
		array_stack() {
			capacity = 1000;
			top = -1;
			arr = new T[capacity];
			
		}
		
		array_stack(int cap) {
			capacity = cap;
			top = -1;
			arr = new T[capacity];
		}
		
		~array_stack() {
			delete arr;
		}
		
		int size() {
			return top+1;
		}
		
		bool empty() {
			return top == -1;
		}
		
		void push(T x) {
			if(size() == capacity) {
				cout<<"Stack is full!"<<endl;
				return;
			}
			arr[++top] = x;
		}
		
		T pop() {
			if(empty()) {
				cout<<"Stack is empty!"<<endl;
			} else {
				return arr[top--];
			}
			
		}
		
		T peek() {
			if(empty()) {
				cout<<"Stack is empty!"<<endl;
			} else {
				return arr[top];	
			}
		}
		
		void print_stack() {
			cout<<"[";
			for(int i=0;i<size();i++) {
				cout<<arr[i];
				if(i!=size()-1)cout<<",";
			}
			cout<<"]"<<endl;
		}
};

int main() {
	array_stack<int> s(5);
	s.push(1);
	s.push(5);
	s.push(7);
	s.push(9);
	cout<<"The top of the stack currently is "<<s.peek()<<endl;
	s.push(13);
	s.push(17);
	s.print_stack();
	s.pop();
	s.pop();
	s.push(27);
	cout<<"Is the stack empty? "<<s.empty()<<endl;
	s.print_stack();
	return 0;
}
