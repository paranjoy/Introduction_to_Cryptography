/*
Caesar Cipher in Cryptography
The Caesar Cipher technique is one of the earliest and simplest method of encryption technique. 
It’s simply a type of substitution cipher, i.e., each letter of a given text is replaced by a letter some fixed number 
of positions down the alphabet. 
For example with a shift of 1, A would be replaced by B, B would become C, and so on. The method is apparently named after 
Julius Caesar, who apparently used it to communicate with his officials.
Thus to cipher a given text we need an integer value, known as shift which indicates the number of position each letter of the 
text has been moved down.
The encryption can be represented using modular arithmetic by first transforming the letters into numbers, according to 
the scheme, A = 0, B = 1,…, Z = 25. Encryption of a letter by a shift n can be described mathematically as.

E_n(x)=(x+n)%26                                 D_n(x)=(x-n)%26
(Encryption Phase with shift n)                 (Decryption Phase with shift n)


Examples :

Text : ABCDEFGHIJKLMNOPQRSTUVWXYZ
Shift: 23
Cipher: XYZABCDEFGHIJKLMNOPQRSTUVW

Text : ATTACKATONCE
Shift: 4
Cipher: EXXEGOEXSRGI


Algorithm for Caesar Cipher:
Input:
A String of lower case letters, called Text.
An Integer between 0-25 denoting the required shift.

Procedure:
Traverse the given text one character at a time .
For each character, transform the given character as per the rule, depending on whether we’re encrypting or decrypting
the text.
Return the new string generated.
*/

// A C++ program to illustrate Caesar Cipher Encryption Technique 

#include <iostream> 
using namespace std; 
  
// This function receives text and shift and  returns the encrypted text

string encrypt(string text, int s) 
{ 
    string result = ""; 
  
    for (int i = 0; i < text.size(); i++) 
    {  
        // Encrypt Uppercase letters 
      
        if (isupper(text[i])) 
            result += char( int(text[i] + s - 65) % 26 + 65); 
  
        // Encrypt Lowercase letters 
    
        else
            result += char( int(text[i] + s - 97) % 26 + 97); 
    } 
  
    return result; 
} 
  
int main() 
{ 
    string text;
    int s;
    
    cout << "Enter the text" << endl;
    getline(cin, text); 
    
    cout<<"Enter the shift value"<<endl;
    cin >> s;
    
    cout << " Text : " << text; 
    cout << "\n Shift: " << s; 
    cout << "\n Cipher: " << encrypt(text, s); 
    return 0; 
} 
