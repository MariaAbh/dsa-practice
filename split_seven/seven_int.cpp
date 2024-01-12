//#82
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_str (string s);

int main() {
	string s = "Hello WHello WHello W";
	vector<string> words = split_str(s);
	for (string w: words)
	    cout << w << endl;
	return 0;
}

vector<string> split_str (string s) {
	vector<string> words;
	string w = "";
	for (int i = 0; i < s.size(); i++) {
		w += s[i];
		if ((i+1)%7 == 0 and i != 0){
			words.push_back(w);
			w = "";
		}
	}
	words.push_back(w);
	return words;
}
