#include <iostream>
#include <limits>
#include <vector>
using namespace std;

float closets_to_zero(vector<float> numb);
int main(){
	vector<float> numb = {1.2,2.3,-1.0,-0.5,0.2,5.3};
	float mini = closets_to_zero(numb);
	cout << "mini: " << mini << endl;
	return 0;
}
float closets_to_zero(vector<float> numb){
	float mini = numeric_limits<float>::infinity();
	for (int i = 0; i < numb.size(); i++) {
		if (abs(numb[i]) < abs(mini)){
			mini = numb[i];
		}
	}
	return mini;
}
