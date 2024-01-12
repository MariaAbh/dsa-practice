#include <iostream>
#include <string>
using namespace std;

bool is_interleaf(string s1, string s2, string s3);
int main(){
	string s1 = "abb";
	string s2 = "baa";
	string s3 = "abbbaa";
	string s4 = "ababba";
	bool res1 = is_interleaf(s1,s2,s3);
	bool res2 = is_interleaf(s1,s2,s4);
	cout << "res1: " << res1 << endl;
	cout << "res2: " << res2 << endl;
	return 0;
}
bool is_interleaf(string s1, string s2, string s3){
	if (s1.size() == 0 and s2.size() == 0)
		return true;
	if (s1.size() > 0 && s1[0] == s3[0])
		return is_interleaf(s1.substr(1, s1.size()-1),s2,s3.substr(1, s3.size()-1));
	if (s2.size() > 0 && s2[0] == s3[0])
		return is_interleaf(s1,s2.substr(1, s2.size()-1),s3.substr(1, s3.size()-1));
	return false;
}

