#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;
void passwordIsValid(vector<string> wordList, string userWord){

    ifstream flux("word.txt");

    cout << "Lecture du fichier..." << endl;
    
    if(flux){
        string line;
        while(getline(flux, line)){
            wordList.push_back(line);
        }
    }
    else{
        cout << "ERREUR: Impossible de lire le fichier !" << endl;
    }

    cout << "Lecture du fichier termine" << endl;


    regex patternChar {"3"};
    string target = userWord;
    string remplacement {"e"};
    string resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les 3 par des e: " << resultat << endl;

    patternChar = "[@4]";
    remplacement = "a";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les @ et 4 par des a: " << resultat << endl;

    patternChar = "[!|/]";
    remplacement = "i";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les ! | et / par des i: " << resultat << endl;
    target = resultat;

    patternChar = "[?$25]";
    remplacement = "s";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les ? $ 2 et 5 par des s: " << resultat << endl;
    target = resultat;
    
    patternChar = "[1]";
    remplacement = "l";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les 1 par des l: " << resultat << endl;
    target = resultat;
    
    patternChar = "[0]";
    remplacement = "o";
    resultat = regex_replace(target, patternChar, remplacement);
    target = resultat;
    cout << "Remplacer les 0 par des o: " << resultat << endl;
    target = resultat;

    bool isValid = true;

    for (const string word : wordList)
    {

        regex patternWord {word};
        bool resultWord = regex_search(target, patternWord);

        if(resultWord){
            cout << "Mot de passe refuse car il contient le mot " + word << endl;
            isValid = false;
        }
    }
    if(isValid){
        cout << "Mot de passe accepte !" << endl;
    }
}

string convertLowerCase(string phrase){
    for(int i=0; i<phrase.size(); i++){
        phrase[i] = tolower(phrase[i]);
    }
    return phrase;
}



int main()
{
    vector<string> wordList;
    string password;
    string userWord;
    
    cout << "Entrez un mot de passe:";
    getline(cin, password);
    userWord = password;
    userWord = convertLowerCase(userWord);
    cout << "Convertit en minuscule: " << userWord << endl;
    passwordIsValid(wordList, userWord);
    cout << "Le mot de passe est: " << password << endl;
    cout << "Le mot de passe en minuscule est: " << userWord << endl;
}
