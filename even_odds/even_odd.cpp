#include <iostream>
#include <string>
using namespace std;

string even_odd(int a);

int main(){
	int a = 5;
	int b = 2;
	cout << even_odd(a) << endl;
	cout << even_odd(b) << endl;
	return 0;
}

string even_odd(int a){
	if (a % 2 == 0)
		return "even";
	else
		return "odd";
}
