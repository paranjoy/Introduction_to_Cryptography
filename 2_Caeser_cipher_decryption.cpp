/*
Brute Force Attack ->
Because the number of the possible keys is 26 that's why we can consider all these cases 
(so check all the possible key values) and check whether the decrypted message makes sense or not.
*/

// A C++ program to illustrate Caesar Cipher Decryption Technique 

#include <iostream> 
using namespace std; 
  
// This function receives text and shift and  returns the decrypted text

string decrypt(string text, int s) 
{ 
    string result = ""; 
  
    for (int i = 0; i < text.size(); i++) 
    {  
        // deccrypt Uppercase letters 
      
        if (isupper(text[i])) 
            result += char( int(text[i]) - s <  65 ? (int(text[i]) - s + 26) : (int(text[i]) - s)); 
  
        // decrypt Lowercase letters 
    
        else if(islower(text[i]))
            result += char( int(text[i]) - s <  97 ? (int(text[i]) - s + 26) : (int(text[i]) - s));
        
        else
            result += text[i]; 
    } 
  
    return result; 
} 
  
int main() 
{ 
    string text; 
    cout << "Enter the cipher text" << endl;
    getline(cin, text); 
    
    for(int i = 0; i  < 26; i++)
        cout<<"Shift by :" << i <<" ->  " << decrypt(text, i) << endl; 
 
    return 0; 
} 
