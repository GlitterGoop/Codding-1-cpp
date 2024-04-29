#include <iostream>
#include <string>
using namespace std;

enum difficulty {EASY, MEDIUM, HARD}; 
enum shipType {TUGBOAT = 10, FIGHTER = 25, FRIGATE = 50, BATTLESHIP = 250, CARRIER = 1000};

class robot {
public:
    string name = "Robba";
};

class weapon {
public:
    string name = "Mace of doom";
    int damage = 20;
};

class human {
public:
    string name = "Tedd";
    robot buddy;
    weapon myWeapon;

human(){
    SayHello();
}

void SayHello(){
    cout << "Hi, I'm " << name << " and my robot's name is " << buddy.name << ".\n";
    cout << "My weapon is " << myWeapon.name << " and it does " << myWeapon.damage << ".\n";
    }
};



int main() {
  cout << "Hello World!\n";
    shipType playerShip = TUGBOAT;

    int playerMoney = 5000;

    if(playerShip == TUGBOAT){
        cout << "You got a tugboat! Nice.\n";
        playerMoney -= TUGBOAT;
    }
    else if(playerShip == 1000){
        cout << "You got a carrier? Fuck you.\n";
        playerMoney -= CARRIER;
    }

    shipType enemyShip = FRIGATE;

    if(playerShip > enemyShip){
        cout << "Hey! You have a better ship! FUCK YOU.\n";
    }

    cout << "Your money is now $" << playerMoney << ".\n";


    
    human firstHuman;

    weapon coolSword;
    coolSword.name = "Sword of cool";
    coolSword.damage = 9999;

    firstHuman.myWeapon = coolSword;
    firstHuman.SayHello();

    cout << "The memory address of coolSword is " << &coolSword << ".\n";
    cout << "The memory address of firstHuman.myWeapon is " << &firstHuman.myWeapon << ".\n";
}