#include <iostream>
using namespace std;

template <class T>
class Queue {
	private:
		struct Node {
			T val;
			Node* next;
		};
		Node* queue = NULL;
		Node* tail = NULL;
	public:
		void add (T val) {
			Node* node = new Node();
			node->val = val;
			node->next = NULL;
			if (queue == NULL){
				queue = node;
				tail = queue;
			}
			else {
				tail->next = node;
				tail = node;
			}
		}

		int pop () {
			int popped = queue->val;
			Node* addr = queue;
			queue = queue->next;
			delete addr;
			return popped;
		}

		int get () {
			return queue->val;
		}
};

int main() {
	Queue<int> my_queue;
	
	my_queue.add(5);
	my_queue.add(10);
	my_queue.add(20);
	cout << my_queue.get() << endl;

	my_queue.pop();
	cout << my_queue.get() << endl;

	return 0;
}
