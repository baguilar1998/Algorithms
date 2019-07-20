#include <iostream>
#include <set>
#include <map>
using namespace std;

bool is_unique(string s);

// Checking if a string is unique using a set
// Running Time: O(n)
// Space ComplexityL O(1)
bool is_unique_set(string s) {
	set<char> characters;
	for(int i=0;i<s.length();i++) {
		set<char>::iterator value = characters.find(s[i]);
		if(value != characters.end()) 
			return false;
		characters.insert(s[i]);
	}
	return true;
}

// Check if a string is unique using constant space
// Running Time: O(n)
// Space Complexity: O(256) => O(1)
bool is_unique(string s) {
	bool* letters = new bool[256];
	
	for(int i=0;i<256;i++)
		letters[i] = false;
	
	int i;
	for(i=0;i<s.length();i++) {
		int c = (int)s[i];
		if(letters[c]) {
			break;
		}
		letters[c] = true;
	}
	
	delete letters;
	if(i!=s.length())
		return false;
	return true;
}

int main() {
	string s1 = "Brian";
	string s2 = "!o%b$je*ct";
	string s3 =" arrays";
	string s4 = "javAsCript";
	
	cout<<boolalpha; 
	
	cout<<is_unique(s1)<<endl;
	cout<<is_unique(s2)<<endl;
	cout<<is_unique(s3)<<endl;
	cout<<is_unique(s4)<<endl;
	
	
}
