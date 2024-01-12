#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int> values, vector<int> weights, int capacity, int start);

int main() {
	vector<int> values = {60,100,120};
	vector<int> weights = {10,20,30};
	int capacity = 50;
	int start = 0;
	int k = knapsack(values,weights,capacity,start);
	cout << k << endl;

	return 0;
}

int knapsack(vector<int> values, vector<int> weights, int capacity, int start) {
	if (start == values.size() || capacity == 0) {
		return 0;
	}
	if (weights[start] <= capacity) {
		return max(
			values[start] + knapsack(values,weights,capacity-weights[start],start+1),
			knapsack(values,weights,capacity,start+1)
			);
	}
	else {
		return knapsack(values,weights,capacity,start+1);
	}
}
