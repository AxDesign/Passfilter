#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void passwordIsValid(vector<string> wordList, string userWord){

    ifstream flux("word.txt");
    if(flux){
        string line;
        while(getline(flux, line)){
            wordList.push_back(line);
        }
    }
    else{
        cout << "ERREUR: Impossible de lire le fichier !" << endl;
    }

    bool isValid = true;
    for (const string word : wordList)
    {
        if(word == userWord){
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
    string userWord;
    
    cout << "Entrez un mot de passe:";
    getline(cin, userWord);
    userWord = convertLowerCase(userWord);
    cout << userWord << endl;
    passwordIsValid(wordList, userWord);

}
