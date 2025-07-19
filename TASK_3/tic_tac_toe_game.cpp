#include<bits/stdc++.h>
using namespace std;
char board[3][3];
char current_player;
void make_board(){
    char number = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = number++;
        }
    }
}
void display_board(){
    cout<<"\n";
    for(int i=0;i<3;i++){
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j<2) cout<<" | ";
        }
        if(i<2) cout<<"\n---|---|---\n";
    }
    cout<<"\n\n";
}
bool make_move(){
    int choice;
    cout<<"Player "<<current_player<<", enter your choice (1-9): ";
    cin>>choice;
    if(choice<1 || choice>9){
        cout<<"Invalid input. Try again!\n";
        return false;
    }
    int row= (choice - 1) / 3;
    int col= (choice - 1) % 3;
    if(board[row][col]== 'X' || board[row][col]== 'O'){
        cout<<"Cell already taken. Try another.\n";
        return false;
    }
     board[row][col]= current_player;
     return true;
}
bool check_win(){
    for(int i=0;i<3;i++){
        if( board[i][0]== current_player && board[i][1]== current_player && board[i][2]== current_player ||
            board[0][i]== current_player && board[1][i]== current_player && board[2][i]== current_player){
                return true;
        }
    }
    if(board[0][0]== current_player && board[1][1]== current_player && board[2][2]== current_player ||
    board[0][2]== current_player && board[1][1]== current_player && board[2][0]== current_player){
        return true;
    }
    return false;
}
bool check_draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if( board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}
void switch_player(){
    current_player= (current_player== 'X') ? 'O' : 'X';
}
int main(){
    char playagain;
    do{
        make_board();
        current_player='X';
        while(true){
            display_board();
            if(!make_move())continue;
            if(check_win()){
                display_board();
                cout<<"Player "<<current_player<<" wins\n";
                break;
            }
            else if(check_draw()){
                display_board();
                cout<<"It's a draw.\n";
                break;
            }
        switch_player();
        } 
        cout<<"Play again (y/n): ";
        cin>>playagain;
    }while(playagain== 'y' || playagain=='Y');
    cout<<"Thanks for playing!\n";
    return 0;
}