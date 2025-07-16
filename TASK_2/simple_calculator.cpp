#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Welcome to Calculator!";
    int number_1;
    cout<<"Enter the First number: \n"; 
    cin>>number_1;
    int number_2;
    cout<<"Enter the Second number: \n"; 
    cin>>number_2;
    char operation;
    cout<<"Choose an operation to perfrom (+, -, *, /): ";
    cin>>operation;
    switch(operation){
        case '+':
        cout<<"Result : "<<number_1 + number_2<<endl;
        break;

        case '-':
        cout<<"Result : "<<number_1 - number_2<<endl;
        break;

        case '*':
        cout<<"Result : "<<number_1 * number_2<<endl;
        break;

        case '/':   
        if(number_2 == 0){
            cout<<"Error! Divison by zero is not allowed."<<endl;
        }
        else{
        cout<<"Result : "<<number_1 / number_2<<endl;
        break;
        }

        default: 
        cout<<"Invalid operator entered!"<<endl;
    }

    return 0;
}