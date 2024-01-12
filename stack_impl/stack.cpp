#include <iostream>
using namespace std;

struct Node {
	int value;
	Node * prev;
};

struct Node* add (int val, Node* current);
int remove (Node** current);
int get (Node* current);

int main() {
	Node* stack = NULL;

	stack = add(5, stack);
	cout << stack->value << endl;

	stack = add(10, stack);
	cout << stack->value << endl;

	Node** p_stack = &stack;
	int poped = remove(p_stack);
	cout << poped << endl;

	cout << stack->value << endl;
	/* stack = remove(stack); */
	/* cout << get(stack) << endl; */

	/* stack = remove(stack); */
	/* cout << get(stack) << endl; */

	return 0;
}

struct Node* add (int val, Node* first) {
	Node* temp = new Node();
	temp->value = val;
	temp->prev = first;
	first = temp;
	return first;
}

int remove (Node** p_stack) {
	Node* first = *p_stack;
	if (first == NULL)
		return 0;
	int popped = first->value;
	Node* addr = first;
	first = first->prev;
	*p_stack = first;
	delete addr;
	return popped;
}

int get (Node* current) {
	if (current == NULL)
		return 0;
	return current->value;
}





