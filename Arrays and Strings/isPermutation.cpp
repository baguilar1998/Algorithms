#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

bool is_permutation(string s1, string s2);

bool is_permutation(string s1, string s2) {
	if(s1.length() != s2.length())
		return false;
	
	map<char,int> S1;
	map<char,int> S2;
	set<char> keys1;
	set<char> keys2;
	
	for(int i=0;i<s1.length();i++) {
		S1[s1[i]] =  S1[s1[i]] +1;
		keys1.insert(s1[i]);
		S2[s2[i]] =  S2[s2[i]] +1;
		keys2.insert(s2[i]);
	}
	
	if(keys1.size() != keys2.size())
		return false;
	
	for(set<char>::iterator it= keys1.begin(); it != keys1.end(); it++) {
		char current_key = *it;
		set<char>::iterator it2 = keys2.find(current_key);
		if(it2 == keys2.end())
			return false;
		if(S1[current_key] != S2[current_key])
			return false;
	} 
	
	return true;
}
int main() {
	string s1 = "taco cat";
	string s2 = "cta toca";
	cout<<boolalpha;
	cout<<is_permutation(s1,s2);
}
