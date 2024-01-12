#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
	private:
		struct Node {
			int val;
			Node* left = NULL;
			Node* right = NULL;
		};
		Node* root = NULL;
	public:
		void print() {
			Node* current = root;
			vector<Node*> queue;
			queue.push_back(root);
			while (queue.size()>0) {
				Node* node = queue[0];
				cout << node->val << " ";
				queue.erase(queue.begin());
				if (node->left != NULL) {
					queue.push_back(node->left);
				}
				if (node->right != NULL) {
					queue.push_back(node->right);
				}
			}
		}

		void add(int val) {
			Node* my_node = new Node();
			my_node->val = val;
			if (root == NULL) {
				root = my_node;
			}
			else {
				vector<Node*> queue;
				queue.push_back(root);
				while (queue.size() > 0) {
					Node* c_node = queue[0];
					queue.erase(queue.begin());
					if (c_node->left != NULL && c_node->right != NULL){
						queue.push_back(c_node->left);
						queue.push_back(c_node->right);
					}
					else {
						if(c_node->left == NULL) {
							c_node->left = my_node;
							return;
						}
						else if (c_node->right == NULL) {
							c_node->right = my_node;
							return;
						}
					}
				}
			}

		}

		vector<vector<int>> bfs() {
			Node* my_root = root;
			vector<Node*> current_nodes = {my_root};
			vector<vector<int>> result;

			while (current_nodes.size() > 0) {

				vector<Node*> temp;
				vector<int> node_values;
				
				for (int i = 0; i < current_nodes.size(); i++) {
					node_values.push_back(current_nodes[i]->val);
					if (current_nodes[i]->left != NULL) {
						temp.push_back(current_nodes[i]->left);
					}
					if (current_nodes[i]->right != NULL) {
						temp.push_back(current_nodes[i]->right);
					}
				}
				
				result.push_back(node_values);
				current_nodes.clear();
				
				for (auto elem : temp) {
					current_nodes.push_back(elem);
				}
			}
			return result;
		}
};

int main() {
	TreeNode t;
	t.add(10);
	t.add(31);
	t.add(23);
	t.add(72);
	t.add(42);
	t.add(4);
	/* t.print(); */
	cout << endl;
	vector<vector<int>> result = t.bfs();

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}	
