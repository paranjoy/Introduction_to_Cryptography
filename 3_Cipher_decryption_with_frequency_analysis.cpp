/*
The methodology behind frequency analysis relies on the fact that in any language, each letter has its own personality. 
The most obvious trait that letters have is the frequency with which they appear in a language.
Clearly in English the letter "Z" appears far less frequently than, say, "A". In times gone by, if you wanted to find out the
frequencies of letters within a language, you had to find a large piece of text and count each frequency. Now, however, we have
computers that can do the hard work for us. But in fact, we don't even need to do this step, as for most languages there are 
databases of the letter frequencies,  which have been calculated by looking at millions of texts, and are thus very highly 
accurate.

e -> 12.7 %
t -> 9.1 %
a -> 8.2 %
o -> 7.5 %
i -> 7.0 %
n -> 6.7 %
s -> 6.3 %
h -> 6.1 %
r -> 6.0 %
d -> 4.3 %
l -> 4.0 %
c -> 2.8 %
u -> 2.8 %
m -> 2.4 %
w -> 2.4 %
f -> 2.2 %
g -> 2.0 %
y -> 2.0 %
p -> 1.9 %
b -> 1.5 %
v -> 1.0 %
k -> 0.8 %
j -> 0.15 %
x -> 0.15 %
q -> 0.10 %
z -> 0.07 %

We can use this information to help us break a code given by a Monoalphabetic Substitution Cipher. This works because, 
if "e" has been encrypted to "X", then every "X" was an "e". Hence, the most common letter in the ciphertext should be "X".

Thus, if we intercept a message, and the most common letter is "P", we can guess that "P" was used to encrypt "e", and thus 
replace all the "P"'s with "e". Of course, not every text has exactly the same frequency, and as seen above, "t" and "a" 
have high frequencies too, so it could be that "P" was one of those. However, it is unlikely to be "z" as this is rare in 
the English Language. By repeating this process we can make good progress in breaking a message.
*/

// A C++ program to illustrate Caesar Cipher Decryption Technique 
#include <bits/stdc++.h> 
using namespace std; 
 
map<char, int> m;
string text;

void frequency_analysis(){

    for(int i = 65; i <= 90; i++)
        m[char(i)] = 0;

    for(int i = 0 ; i < text.size(); i++)
        if(int(text[i]) >= 97 && int(text[i]) <= 122)
            m[char(int(text[i] - 32))]++;
        else if(int(text[i]) >= 65 && int(text[i]) <= 90)
            m[text[i]]++;

    for(auto itr = m.begin(); itr != m.end(); itr++)
        cout << itr->first <<" : " << itr->second << endl;

}

void put_inplace(char ch1, char ch2) 
{ 
    for(int i = 0; i < text.size(); i++){

        if(text[i] == ch1)
            text[i] = ch2;
    }

} 


  
int main() 
{ 
    cout << "Enter the cipher text" << endl;
    getline(cin, text); 
    
    cout << "Frequency Analysis" << endl;
    frequency_analysis();


    while(1){

        char ch1, ch2;
        cout << "Enter to rplace characters" << endl;
        cin >> ch1 >> ch2; 

        put_inplace(ch1, ch2);

        cout << "\n" << text << endl << endl;

        cout << "Enter Y to continue and any other to exit" <<endl;

        cin >> ch1;

        if(!(ch1 == 'Y' || ch1 == 'y'))
            break;
    } 
 
    return 0; 
} 
