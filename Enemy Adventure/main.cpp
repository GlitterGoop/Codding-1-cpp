#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool debug = false;

enum itemType {
    weapon, consumable
};

enum elementalType {
   kinetic, fire, water, rock, wind, electric, plant, ice
};

class item {
public:
    itemType type;
    int damage;
    string name;
    elementalType element;
    int healingAmount;

    item(string n, itemType t){
        if(debug) cout << "Starting item constructor.\n";
        name = n;
        type = t;
        
        if (type == weapon){
            damage = rand() % 5 + 3;
            element = (elementalType)(rand() % 7);
            healingAmount = 0;
        }
        else if(type == consumable) {
            healingAmount = rand() % 5 + 3;
            damage = -healingAmount;
            element = kinetic;
        }
    }

    void Inspect(){
        if(debug) cout << "Calling item.Inspect on item: " << name << ".\n";
        cout << "Your " << name << " does " << damage << " damage, with the element of " << elementToString(element) << ".\n";
    }

    string typeToString(itemType type){
        switch(type) {
            case weapon: 
                    return "weapon";
                    break;
            case consumable: 
                    return "consumable";
                    break;
            default: 
                    return "Unknown";
                    break;
        }
     }
    
    string elementToString(elementalType element){
        switch(element){
            case kinetic: return "kinetic";
            break;
            case fire: return "fire";
            break;
            case water: return "water";
            break;
            case rock: return "rock";
            break;
            case wind: return "wind";
            break;
            case electric: return "electric";
            break;
            case plant: return "plant";
            break;
            case ice: return "ice";
            break;
            default: return "unknown";
            break;
        }
    }
    int getDamage() {
        return rand() % damage + (damage/2);
    }
};

class enemy{
public:
    item heldItem;
    int orcHealth = 5;

    enemy(item givenItem = item("mace", weapon)) : heldItem(givenItem) {
        if(debug) cout << "Calling enemy constructor.\n";
    }

    int attack() {
    if(debug) cout << "Calling attack().\n";
    return heldItem.getDamage();

    }
};

string ask(string question){
     string response;
     cout << question;
     cin >> response;
     return response;
 }

int main() {
    if(debug) cout << "1\n";
    srand(time(0));

    int health = 20;

    vector<string> weaponNames = {
        "Real Big Hammer",
        "Shoe",
        "Cool Rock You Found On The Road",
        "God Slayer",
        "Bare Hand",
        "Bear Hand",
        "Bare Hand But Covered In Dirt"
    };

    random_shuffle(weaponNames.begin(), weaponNames.end());
    
    do{
        cout << "A real bad dude has appeared!\n";
        string response = ask("What do you wanna do?[Attack/Heal]");

        if(response == "Attack"){
              vector<item> weapons;
                string weaponName = weaponNames[rand() % weaponNames.size()];  
                    weapons.push_back(item(weaponName, weapon)); 
                    weapons[0].Inspect();        
            enemy badDude;
            badDude.orcHealth -= weapons[0].damage;
            health -= badDude.attack();

            if(badDude.orcHealth > 0){
                cout << "You got him, but he's not down!\n";
                cout << "He also got you, that sucks.\n";
            }
            else{
                cout << "He's dead! Cool.\n";
                cout << "He still hit you, but who cares right?\n";
            }
         }
        else{
            health -= item("healing",consumable).damage;
            cout << "Okay, you healed yourself up a bit.\n";
        }
      }
    while(health > 0);

    if(health <= 0){
        cout << "HAHA YOU DIED. Sorry, this assignment threw me for a loop and I gotta get my enjoyment where I can.\n";
    }
 
}