#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_anagram(string a, string b);
int main() {
	string a = "abba";
	string b = "baab";
	bool anagram = is_anagram(a,b);
	cout << "anagram: " << anagram << endl;
	return 0;
}
bool is_anagram(string a, string b){
	vector<int> la(128,0);
	vector<int> lb(128,0);
	int len_a = a.size();
	int len_b = b.size();
	if (len_a != len_b)
		return false;
	for (int i = 0; i < len_a; i++){
		int ord_a = (int)a[i];
		int ord_b = (int)b[i];
		la[ord_a] += 1;
		lb[ord_b] += 1;
	}
	for (int j = 0; j < 128; j++){
		if (la[j] != lb[j])
			return false;
	}
	return true;
}
