/*
It is very similar to Caesar cryptosystem BUT we use several keys instead of just a single key. 
It is a form of polyalphabetic substitution method

"Vigenere cryptosystem is a method of encrypting alphabetic text by using a series of 
            interwoven Caesar ciphers based on the letters of a keyword”


	Enter the plain text
	THIS IS JUST AN  EXAMPLE.
	
	Enter the private-key
	SECRET
	
	Encrypted text -->
	LLKJ ML BYUK EG  WBCDTEW.
	
	Decrypted text -->
	THIS IS JUST AN  EXAMPLE.
*/


#include<bits/stdc++.h>
using namespace std;


string vigenere_encrypt(string plain_text, string key){

	int  n = key.size();
	string str = "";

	int  i = 0;

	for(int  j = 0; j < plain_text.size(); j++){
		
		if( plain_text[j] >= 'A' && plain_text[j] <= 'Z'){
			int shift = int(key[(i++) % n] - 'A');
			int character = int(plain_text[j] - 'A');

			int encry_char = ((shift + character) % 26);

			str += char(65 + encry_char); 
		}
		else
			str += plain_text[j];
	}

	return str;
}

string vigenere_decrypt(string cipher_text, string key){
	
	int n = key.size();
	string str = "";

	int  i = 0;

	for(int  j = 0; j < cipher_text.size(); j++){
		
		if( cipher_text[j] >= 'A' && cipher_text[j] <= 'Z'){
			int shift = int(key[(i++) % n] - 'A');
			int character = int(cipher_text[j] - 'A');

			int decry_char = ((character - shift + 26) % 26);

			str += char(65 + decry_char); 
		}
		else
			str += cipher_text[j];
	}

	return str;
}

int main(){

	string plain_text;
	string cipher_text;
	string decrypted_text;
	string key;

	cout << "Enter the plain text" << endl;
	getline(cin, plain_text);

	cout << "Enter the private-key" << endl;
	getline(cin, key);

	cipher_text = vigenere_encrypt(plain_text, key); 

	cout << "Encrypted text -->" << endl;

	cout << cipher_text << endl;

	decrypted_text = vigenere_decrypt(cipher_text, key);

	cout << "Decrypted text -->" << endl;

	cout << decrypted_text << endl;


	return 0; 
}
