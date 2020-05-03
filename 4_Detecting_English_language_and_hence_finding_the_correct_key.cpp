/*
When cracking a given cipher it may be useful to detect whether the decrypted language is english or not.
We can use a dictionary and check whether the given words are present in a dictionary or not. 
These dictionaries (containing most of the english words) are available on the web.
*/
/*
INPUT:
Enter the cipher(encrypted) Text
Xmj bfx gtws ns Bfwxfb, ns bmfy bfx ymjs ymj Pnslitr tk Utqfsi, ufwy tk ymj Wzxxnfs Jrunwj. Xmj xyzinji fy Bfwxfb'x 
hqfsijxynsj Kqdnsl Zsnajwxnyd fsi gjlfs mjw uwfhynhfq xhnjsynknh ywfnsnsl ns Bfwxfb. Ns 1891, flji 24, xmj ktqqtbji mjw 
tqijw xnxyjw Gwtsnxłfbf yt xyzid ns Ufwnx, bmjwj xmj jfwsji mjw mnlmjw ijlwjjx fsi htsizhyji mjw xzgxjvzjsy xhnjsynknh btwp. 
Xmj xmfwji ymj 1903 Stgjq Uwnej ns Umdxnhx bnym mjw mzxgfsi Unjwwj Hzwnj fsi umdxnhnxy Mjswn Gjhvzjwjq. Xmj bts ymj 1911
Stgjq Uwnej ns Hmjrnxywd.

OUTPUT:
THE KEY IS : 5
The message is ------>>>
She was born in Warsaw, in what was then the Kingdom of Poland, part of the Russian Empire. She studied at Warsaw's 
clandestine Flying University and began her practical scientific training in Warsaw. In 1891, aged 24, she followed her 
older sister Bronisława to study in Paris, where she earned her higher degrees and conducted her subsequent scientific work. 
She shared the 1903 Nobel Prize in Physics with her husband Pierre Curie and physicist Henri Becquerel. She won the 1911 
Nobel Prize in Chemistry.
*/

//code

#include<bits/stdc++.h>
using namespace std;
set <string> s;
string str;
double length_str, length_english_words;

void load_english_dictionary(){

	fstream file;

	file.open("english_words.txt",ios::in);

	if(!file)
		cout<<"Error in opening file!!!"<<endl;  
    
    string str; //to read single word

    //read untill end of file is not found.
    while( !file.eof() ){
    	
    	file >> str; //read single word from file
    	
    	s.insert(str);
    }

    file.close();
}

string decrypt_key(string text, int key){
//function to decrypt the cipher text based on the key
    string result = ""; 
  
    for (int i = 0; i < text.size(); i++) 
    {  
              
        if (isupper(text[i])) 
            result += char( int(text[i]) - key <  65 ? (int(text[i]) - key + 26) : (int(text[i]) - key)); 
  
        else if(islower(text[i]))
            result += char( int(text[i]) - key <  97 ? (int(text[i]) - key + 26) : (int(text[i]) - key));
        
        else
            result += text[i]; 
    } 
  
    return result; 
}

bool check_english_sentence(string str1){
//function to check whether the decrypted text is a valid English language text or not.
	istringstream iss(str1);

    string word;

    length_str = 0.0;
    length_english_words = 0.0;


    while(iss >> word) {  

          string str = word.c_str();

          length_str += 1.0;

          if(str[str.size() -1] == ',' || str[str.size() -1] == '.')
            str = str.substr(0, str.size() - 1);

          else if(str.size() >= 2 && str[str.size() - 2] == char(39))
            str = str.substr(0, str.size() - 2);
          

          transform(str.begin(), str.end(), str.begin(), ::toupper);

          if(s.count(str))
          	length_english_words += 1.0;
    }

    double t = length_english_words / length_str;

    if(t >= 0.6) // threshold value 
    	return true;

    else
    	return false;
}


int main(){

	load_english_dictionary(); // load the English language words

	cout << "Enter the cipher(encrypted) Text" << endl;

	getline(cin, str);

	cout << endl << endl;

	for(int  i = 0; i <= 26; i++){

		string str1 = decrypt_key(str, i);

		bool res = check_english_sentence(str1);

		if(res){

			cout << "THE KEY IS : " << i << endl;

			cout << "The message is ------>>>" << endl;

			cout << str1 << endl;

			break;
		}
	}

	return 0;
}
