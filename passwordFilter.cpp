#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> wordList;

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
    for (const string& word : wordList)
    {
        cout << word << endl;
    }
    cout << endl;
}