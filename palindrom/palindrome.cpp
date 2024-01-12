#include <iostream>
#include <string>
using namespace std;

bool pal(string s);

int main(){
	string s1 = "hi";
	string s2 = "aba";
	string s3 = "aabbaa";
	cout << pal(s1) << endl;
	cout << pal(s2) << endl;
	cout << pal(s3) << endl;

	return 0;
}

bool pal(string s){
	int start = 0;
	int end = s.length()-1;
	int mid = (end-start)/2;
	while (start < mid+1 && end > mid ){
		if (s[start] != s[end])
			return false;
		start += 1;
		end -= 1;
	}
	return true;
}
