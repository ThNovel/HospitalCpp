//
//  main.cpp
//  hospital
//This is the Hospital project code for Intro Computing Science
//  Created by Fernando and Iker.
//

#include <iostream>
using namespace std;
//Aqui declara tus variables globales
string user_input;
string password_input;
string user="root";
int password= 1234;
int login_attempt = 0;
//
//Cualquier funcion declarala arriba del main
//Todo este bloque de aca es el Login
void login(){
    while (login_attempt<=3)
    {
        cout<<"User: ";
        cin>>user_input;
        cout<<"Password: ";
        cin>>password_input;
        if(user_input == user && password_input == "1234"){
            cout<<"Success";
            break;
        }
        else{
            cout<<"Invalid User or Password."<<endl;
            login_attempt++;
        }
        if(login_attempt==3){
            cout<<"Many failed attempts, muere."<<endl;
            break;
        }
    //hasta aca

    }
}

int main() {
    // FER PON TU CODIGO ACA!!
    
    login(); //Aqui sucede primero el Login
    cout<<"\nLogin succesful"<<endl;
    

    return 0;
}


