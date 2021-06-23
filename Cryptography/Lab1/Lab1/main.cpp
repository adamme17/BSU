//
//  main.cpp
//  Lab1
//
//  Created by Adam Bokun on 25.02.21.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";


//string FillCode(string password, int textLength)
//{
//    while(password.size() <= textLength)
//    {
//        password += password;
//    }
//
//    return password.substr(0, textLength);
//}
//
//string decrypt(string text, string key)
//{
//    auto fillCode = FillCode(key, text.size());
//    auto decText = "";
//
//    int decLetterIdx;
//
//    for (int i = 0; i < text.size(); ++i)
//    {
//        char letterIdx = alphabet.find(text[i]);
//        char keyIdx = fillCode.find(fillCode[i]);
//
//        decLetterIdx = letterIdx - keyIdx;
//
//        if (decLetterIdx < 0)
//        {
//            decLetterIdx = letterIdx + alphabet.size() - keyIdx;
//        }
//
//        decText += alphabet[decLetterIdx];
//    }
//
//    return decText;
//}
//
//string encrypt(string text, string key)
//{
//    auto fillCode = FillCode(key, text.size());
//    auto encText = "";
//
//    int encLetterIdx;
//
//    for (int i = 0; i < text.size(); ++i)
//    {
//        char letterIdx = alphabet.find(text[i]);
//        char keyIdx = fillCode.find(fillCode[i]);
//
//        encLetterIdx = letterIdx + keyIdx;
//
//        if(encLetterIdx >= alphabet.size())
//        {
//            encLetterIdx = encLetterIdx - alphabet.size();
//        }
//
//        encText += alphabet[encLetterIdx];
//    }
//
//    return encText;
//}
//
//int main()
//{
//    ifstream fin("cypher.in");
//    ofstream fout("cypher.out");
//
//    string key;
//    cin >> key;
//    string input = "helloworld";
// //    string input;
// //    getline(fin, input);
//    string enc = encrypt(input, key);
//    string dec = decrypt(enc, key);
//    cout << enc << endl << dec << endl;
//
// //    fout << enc << endl << dec << endl;
// //    fout.close();
//
//    return 0;
//}


 //Substring

string shuffle(string text)
{
    for(auto t: text)
    {
        int position1 = rand() %25+0;
        int position2 = rand() %25+0;
        char temp = text[position1];
        text[position1] = text[position2];
        text[position2] = temp;
    }

    return text;
}

string encrypt(string text, string key)
        {
            string encrypt_text = "";
            char text_char = '\0';
            for (int i = 0; i < text.length(); ++i)
            {
                text_char += tolower(text[i]);
            }

            for (auto ch : text)
            {
                encrypt_text += key[alphabet.find(ch)];
            }

            return encrypt_text;
        }

string decrypt(string text, string key)
        {
            string decrypt_text = "";
            char text_char = '\0';
            for (int i = 0; i < text.length(); ++i)
            {
                text_char += tolower(text[i]);
            }

            for (auto ch : text)
            {
                decrypt_text += alphabet[key.find(ch)];
            }

            return decrypt_text;
        }


int main()
{
    ifstream fin("cypher.in");
    ofstream fout("cypher.out");
    
//    fout << "ADAM it works!";
    string key = shuffle(alphabet);
    
//    string input = "helloworld";
    string input;
    getline(fin, input);
    string enc = encrypt(input, key);
    string dec = decrypt(enc, key);
//    cout << enc << endl << dec << endl;

    fout << enc << endl << dec << endl;
    fout.close();

    return 0;
}
