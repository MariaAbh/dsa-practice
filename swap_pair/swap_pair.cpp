#include <iostream>
using namespace std;

class LinkedList {
	private:
		struct Node {
			int val;
			Node * next = NULL;
		};
		Node* head = NULL;

	public:
		void add (int val) {
			Node* new_node = new Node();
			new_node->val = val;
			new_node->next = head;
			head = new_node;
		}

		void swap_pairs() {
			Node* node = head;
			while (node != NULL && node->next != NULL && node->next->next != NULL) {
				if (node == head) {
					Node* temp;
					temp = node->next;
					node->next = node->next->next;
					temp->next = node;
					node = temp;
					temp = temp->next;
					head = node;
					node = temp;
				}
				else {
					Node* temp1;
					temp1 = node->next->next;
					node->next->next = node->next->next->next;
					temp1->next = node->next;
					node->next = temp1;
					node = node->next->next;
				}
			}
		}
		
		void print_list() {
			Node* node = head;
			while (node != NULL) {
				cout << node->val << " ";
				node = node->next;
			}
			cout << endl;
		}
};

int main() {
	LinkedList node;
	node.add(5);
	node.add(10);
	node.add(7);
	node.add(8);
	
	node.print_list();
	node.swap_pairs();
	node.print_list();

	return 0;
}



