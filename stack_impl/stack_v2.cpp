#include <iostream>
using namespace std;

template <class T>
class Stack {
	private:
		struct Node {
			T value;
			Node* prev;
		};
		Node* head = NULL;
	public:
		void add (T val) {
			Node* temp = new Node();
			temp->value = val;
			temp->prev = head;
			head = temp;
		}

		T pop () {
			T popped = head->value;
			Node* addr = head;
			head = head->prev;
			delete addr;
			return popped;
		}

		T get () {
			if (head == NULL)
				return 0;
			return head->value;
		}

		bool is_empty () {
			return head == NULL;
		}
};

int main() {
	Stack<double> my_stack;
	
	my_stack.add(5.2);
	cout << my_stack.get() << endl;
	
	my_stack.add(10.4);
	cout << my_stack.get() << endl;

	if (!my_stack.is_empty())
		cout << "poped " << my_stack.pop() << endl;
	cout << my_stack.get() << endl;


	return 0;
}
