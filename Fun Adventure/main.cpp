#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

 string askYesNo(string question){
     string response;
     cout << question;
     cin >> response;
     return response;
 }

 int RollDie(int sides = 6) {
     return rand() % sides + 1;
 }

int main() {
    srand(time(0));

    int health = 20;
    int gold = 0;
    int turns = 0;

    do{
        string response = askYesNo("Do you wanna go adventuring? [Yes/No]");
        if (response == "Yes"){
            int orcDamage = RollDie(10);
            int playerBlock = RollDie(10);

            cout << "You encounter an orc and try to mug him!\n";
            cout << "He's fighting back! He's doing " << orcDamage << " damage!\n";
            cout << "You can block that, right?\n";

            if(playerBlock >= orcDamage){
                cout << "Oh wow, you actually blocked that, thank goodness.\n";
                health--;
                gold += RollDie(10);
                cout << "Now GRAB THE GOLD AND RUN BEFORE HE KILLS YOU\n";
                cout << "You lost a health point, but at least now you've got " << gold << " gold. He didn't have much, huh?\n";
            }
            else{
                cout << "WOW you did terrible at blocking.\n";
                health -= orcDamage;
                if(health > 0)
                    cout << "You lost " << orcDamage << " health, I suggest finding a weaker orc to mug.\n";
            }
            turns++;
        }
        else{
            break;
        }
    }
    while(health > 0);
    
    if(health <= 0){
        cout << "Oh wow you died, that sucks dude. There's now " << gold << " gold on your corpse, so that's cool.\n";  
    }
    else{
        cout << "At least you're alive.\n";
        cout << "It took you " << turns << " turns to end up with " << gold << " gold, so not a bad haul.\n";
        if(health <= 5){
            cout << "Oh also your health is super low and you're missing an arm.\n";
            cout << "You might wanna go see a doctor that does more than poking you with a stick.\n";
        }
    }
    return 0;
}