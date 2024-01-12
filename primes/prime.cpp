#include <iostream>
using namespace std;

bool is_prime(int a);

int main(){
	for(int i = 1; i < 51; i++){
		if (is_prime(i))
			cout << i << " ";
	}

	return 0;
}

bool is_prime(int a){
	for(int i = 2; i < a; i++){
		if (a % i == 0)
			return false;
	}
	return true;
}
