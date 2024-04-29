// Bodie Allen
// Coding 1 W3 D2

#include <iostream>            // for cout and cin
#include <string>
#include <ctime>               // for srand()
#include <cstdlib>             // for rand()   
using namespace std;

int main() {
    srand(time(0));            // seeding the random number generator
    cout << "What's poppin my rats?! It's week 3, day 2 and I'm high on bath salts.\n";

    int counter = 0;
    int highScore = 0;
    float sum = 0;
    while(counter < 10) {
        counter += 1;          // combined assignment operator      
        // counter++;             // increment operator   

        int randNumber = rand() % 45 + 5;

        // cout << "Counter is now " << counter << ".\n"; 
        cout << counter << ". " << randNumber << "\n";

        
        // if the new randNumber is higher than the highscore, it's the new highscore
        if(randNumber >highScore) {
            cout << "\t\tNew High Score Found! Yay!\n";
            highScore = randNumber;
        }

        // for average calculations
        sum += randNumber;
    }

    cout << "The High Score was " << highScore << ".\n";
    cout << "The average number was " << sum / counter << ".\n";
}