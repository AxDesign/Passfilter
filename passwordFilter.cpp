#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

using namespace std;


void passwordIsValid(vector<wstring> wordList, wstring userWord){
    wifstream flux("word.txt");
    
    if(flux){
        wstring line;
        while(getline(flux, line)){
            wordList.push_back(line);
        }
    }
    else{
        cout << "ERREUR: Impossible de lire le fichier !" << endl;
    }

    wregex patternChar {L"3"};
    wstring target = userWord;
    wstring remplacement {L"e"};
    wstring resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;

    patternChar = L"[@4]";
    remplacement = L"a";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;

    patternChar = L"[!|/]";
    remplacement = L"i";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    target = resultat;

    patternChar = L"[?$25]";
    remplacement = L"s";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    target = resultat;
    
    patternChar = L"[1]";
    remplacement = L"l";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    target = resultat;
    
    patternChar = L"[0]";
    remplacement = L"o";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    target = resultat;

    bool isValid = true;

    for (const wstring word : wordList)
    {

        wregex patternWord {word};
        bool resultWord = regex_search(target, patternWord);

        if(resultWord){
            wcout << "Mot de passe refuse car il contient le mot " << word << endl;
            isValid = false;
        }
    }
    if(isValid){
        wcout << "Mot de passe accepte !" << endl;
    }
}

wstring convertLowerCase(wstring phrase){
    for(int i=0; i<phrase.size(); i++){
        phrase[i] = tolower(phrase[i]);
    }
    return phrase;
}



int main()
{
    vector<wstring> wordList;
    wstring password;
    wstring userWord;
    
    wcout << "Entrez un mot de passe:";
    getline(wcin, password);
    userWord = password;
    userWord = convertLowerCase(userWord);
    passwordIsValid(wordList, userWord);
}
