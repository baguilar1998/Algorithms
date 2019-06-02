#include <string>
#include <iostream>
#include <map>
using namespace std;

string DRMDecryptor(string message);

string DRMDecryptor(string message) {
	
 	if (message.length()%2 != 0) {
 		cout<<"Message cannoted be decrypted"<<endl;
 		return message;
	 }
	 
	 map<char,int> letterValues;
	 
	 for(int i = 0; i < 26; i++) {
	 	char c = (char)('A' + i);
	 	letterValues[c] = i;
	 }
	 
	 int mid = (message.length()-1)/2;
	 
	 int leftSum = 0;
	 for(int i=0; i<=mid; i++){
	 	char c = message[i];
	 	leftSum+=letterValues[c];
	 }
	 
	 
	 int rightSum = 0;
	 for(int i=mid+1;i<message.length();i++){
	 	char c = message[i];
	 	rightSum+=letterValues[c];
	 }
	
	 string leftHalf;
	 for(int i=0;i<=mid;i++) {
		int c = message[i];
		int rotation = ((c-65)+leftSum)%26 + 65;
		leftHalf=leftHalf+(char)rotation;
	 }
	 
	 string rightHalf;
	 for(int i=mid+1;i<message.length();i++) {
		int c = message[i];
		int rotation = ((c-65)+rightSum)%26 + 65;
		rightHalf=rightHalf+(char)rotation;
	 }
	 
	 string finalMessage;
	 for(int i=0;i<leftHalf.length();i++){
	 	int c1 = leftHalf[i];
	 	int c2 = rightHalf[i];
	 	
	 	int rotation = ((c1-65)+(c2-65))%26 +65;
	 	finalMessage += (char)rotation;
	 }
	 return finalMessage;
}

int main() {
	string message = "UEQBJPJCBUDGBNKCAHXCVERXUCVK";
	//string message = "EWPGAJRB";
	cout<<DRMDecryptor(message);
}
