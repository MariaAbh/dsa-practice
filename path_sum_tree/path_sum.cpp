#include <iostream>
#include <vector>
using namespace std;


class TreeNode {
	private:
		struct Node {
			int value;
			Node* left;
			Node* right;
		};
		Node* root = NULL;
		/* vector<vector<int>> final_path; */
	public:
		void print() {
			Node* current = root;
			vector<Node*> queue;
			queue.push_back(root);
			while (queue.size()>0) {
				Node* node = queue[0];
				cout << node->value << " ";
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
			my_node->value = val;
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

		vector<vector<int>>* path_sum (Node* t, int k, vector<int> vec, vector<vector<int>>* final_path) {
			if (t == NULL) {
				return {};
			}
			int my_value = t->value;
			vec.push_back(my_value);
			if (t->left == NULL && t->right == NULL && k-my_value == 0) {
				(*final_path).push_back(vec);
				return final_path;
			}
			path_sum (t->left, k-my_value, vec, final_path);
			path_sum (t->right, k-my_value, vec, final_path);

			return {};
		}

		vector<vector<int>> result (int k) {
			Node* t = root;
			vector<vector<int>>* f= new vector<vector<int>>();
			path_sum(t,k,{},f);
			return *f;
		}
};


int main() {
	TreeNode t;
	t.add(5);
	t.add(4);
	t.add(10);
	t.add(7);
	t.add(6);

	int k = 15;
	vector<vector<int>> paths = t.result(k);


	for (int i = 0; i < paths.size(); i++) {
		for (int j = 0; j < paths[i].size(); j++) {
			cout << paths[i][j] << " " ;
		}
		cout << endl;
	}

	return 0;
}

