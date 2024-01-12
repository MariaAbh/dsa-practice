#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};
struct Node* ending = NULL;

struct Node* add (int val, Node* end);
int pop (Node** p_start);
int get (Node* start);

int main() {
	Node* queue = NULL;
	queue = add(5,queue);
	cout << queue->val << " " << ending->val << endl;

	queue = add(10,queue);
	cout << queue->val << " " << ending->val << endl;
	
	queue = add(20,queue);
	cout << queue->val << " " << ending->val << endl;
	
	Node** p_queue = &queue;
	int poped = pop(p_queue);
	cout << "new start: " << queue->val << " popped: " << poped << endl;

	cout << "get elem: " << get(queue) << endl;

	return 0;
}

struct Node* add (int val, Node* queue) {
	Node* node = new Node();
	node->val = val;
	node->next = NULL;
	if (queue == NULL){
		queue = node;
		ending = queue;
	}
	else {
		ending->next = node;
		ending = node;
	}
	return queue;
}

int pop (Node** p_start) {
	Node* start = *p_start;
	int popped = start->val;
	Node* addr = start;
	start = start->next;
	*p_start = start;
	delete addr;
	return popped;
}

int get (Node* queue) {
	return queue->val;
}
