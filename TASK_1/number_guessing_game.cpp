#include<bits/stdc++.h>
using namespace std;
void playgame(){
    int secret_number;
    int guess;
    int attempts=0;
    srand(time(0));
    secret_number = rand() % 100 + 1;
    while(true){
        cout<<"Enter your guess: ";
        cin>>guess;
        attempts++;
        if(secret_number < guess){
            cout<<"To high! Try again \n";
        }
        else if(secret_number > guess){
            cout<<"To low! Try again \n";
        }
        else{
            cout<<"Congratulations! You guessed the correct number in "<<attempts<<" attempts.\n";
            break;
        }
    }
}
int main(){
    string choice;
    cout<<"Welcome to Number Guesssing Game!\n";
    do{
        playgame();
        cout<<"\nDo you want to play the game again? (YES/NO) : ";
        cin>>choice;
    }
    while(choice=="YES" || choice=="yes");
cout<<"Thanks for playing game.\n";
return 0;
}