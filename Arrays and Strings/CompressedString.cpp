#include <iostream>
#include <map>
#include <string>
using namespace std;

string compressed_string(string s);

string compressed_string(string s) {
	if(s.length() == 0)
		return s;
	string compressed = "";
	int counter = 0;
	char current_char = s[0];
	for(int i=0;i<s.length();i++) {
		if(current_char != s[i]) {
			compressed.push_back(current_char);
			compressed+=to_string(counter);
			current_char = s[i];
			counter = 1;
		} else {
			counter++;
		}
	}
	compressed.push_back(current_char);
	compressed+=to_string(counter);
	if(compressed.length() > s.length())
		return s;
	return compressed;
}

int main(){
	string s = "aaaabbbcddeeeeffff";
	cout<<compressed_string(s);
	return 0;
}

