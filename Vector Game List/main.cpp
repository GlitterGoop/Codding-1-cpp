#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string response = "";
    do {
        cout << "Welcome to the FavGames list!\n";
        cout << "Do you wanna look at what I tried to make?\n";
        cin >> response;

    } 
        while (response != "yes");
        cout << "Okay cool\n";
    
    vector<string> games;

    games.push_back("Portal 2");
    games.push_back("Hades");
    games.push_back("Destiny 2");
    games.push_back("Genshin Impact");
    games.push_back("Titalfall 2");
    games.push_back("Devil May Cry 5");
    games.push_back("Hi Fi Rush");
    games.push_back("Deathloop");
    cout << "There are " << games.size() << " games in my personal favorite list.\n";

    do {
        cout << "Oh did you wanna see them?\n";
        cin >> response;

    } 
        while (response != "yes");
        cout << "Okay here ya go.\n";


    for(int i =0; i < games.size(); i ++) {
        cout << games[i] << "\n";
    }
    
    cout << "Sure are a lotta twos huh?\n";

    while (true) {
        if(response == "no") {
            cout << "Oh. Kay then bye.\n";
            break;
        }
        else{
        cout << "Feel free to add a game or two.\n";
        getline(cin,response);                //Originally was cin >> response;
        games.push_back(response);            //getline allows for spaces to be typed
        cout << "Nice choice. Let's look at the list again.\n";
    
        for(int i =0; i < games.size(); i ++) {
            cout << games[i] << "\n";
            }
       }
    }
}