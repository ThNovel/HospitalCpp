//
//  main.cpp
//  hospital
//  This is the Hospital project code for Intro Computing Science
//  Created by Fernando and Iker.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// global variables 
string user_input;
string password_input;
string user="root";
int password= 1234;
int login_attempt = 0;
//end of global variables
class Paciente {
public:
    // constructos vacio 
    Paciente(string name, string gender, int age, double weight, double height,string allergies, string caseInfo, string conclusion, double moneySpent, double moneyEarned):
		name(name), 
		gender(gender), 
		age(age),
		weight(weight),
		height(height),
        allergies(allergies), 
		caseInfo(caseInfo), 
		conclusion(conclusion),
        moneySpent(moneySpent), 
		moneyEarned(moneyEarned) {}

    // funcion para mostrar la informacion del paciente
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Allergies: " << allergies << endl;
        cout << "Case: " << caseInfo << endl;
        cout << "Conclusion: " << conclusion << endl;
        cout << "Money Spent: $" << moneySpent << endl;
        cout << "Money Earned by Hospital: $" << moneyEarned << endl;
        cout << "------------------------" << endl;
    }

// public class variables
public:
    string name;
    string gender;
    int age;
    double weight;
    double height;
    string allergies;
    string caseInfo;
    string conclusion;
    double moneySpent;
    double moneyEarned;
};

class SistemaPaciente {
public:
    // Funcion para agregar una paciente a la classe paciente
    void persona() {
        string name, gender, allergies, caseInfo, conclusion;
        int age;
        double weight, height, moneySpent, moneyEarned;

        cout << "Enter patient's name: ";
        cin >> name;
        cout << "Enter patient's gender: ";
        cin >> gender;
        cout << "Enter patient's age: ";
        cin >> age;
        cout << "Enter patient's weight (kg): ";
        cin >> weight;
        cout << "Enter patient's height (cm): ";
        cin >> height;
        /* 
		el get line es una funcion que lee las lineas del input stream al que se le especifica (X,...)
        y la razon por que la uso es para que tambien lea los espacios en blanco 
        */
        cout << "Enter patient's allergies: ";
        getline(cin, allergies);
        cout << "Enter patient's case: ";
        getline(cin, caseInfo);
        cout << "Enter conclusion of the case: ";
        getline(cin, conclusion);
        cout << "Enter money spent: $";
        cin >> moneySpent;
        cout << "Enter money earned by the hospital: $";
        cin >> moneyEarned;

        Paciente paciente(name, gender, age, weight, height, allergies, caseInfo, conclusion, moneySpent, moneyEarned);
        // la linea de abajo se encarga de mandar los pacientes al final del vector persona_paciente por medio del metodo push_back
        persona_paciente.push_back(paciente);

        cout << "Patient added successfully!" << endl;
    }

    // Funcion para listar todos los paciente que se han agregado
void listPatients() {
        if (persona_paciente.empty()) {
            cout << "No patients in the system." << endl;
            return;
        }

        cout << "List of Patients:" << endl;
        for (const auto& paciente : persona_paciente) {
            paciente.display();
        }
    }

public:
    vector<Paciente> persona_paciente;
};
// funcion login
void login(){
    while (login_attempt < 3)
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
        // no es necesario el if porque ya tenes la declaracion en la funcion while 
      /*  if(login_attempt >=3){
            cout<<"Many failed attempts, muere(figurativamente)."<<endl;
            exit(0); // Esta es una funcion que para que el programa
            break;
        }
        */
    //hasta aca
    }
    cout<<"Many failed attempts, muere(figurativamente)."<<endl;
            exit(0); // Esta es una funcion que para que el programa se apague 
}
// inicio de la clase main
int main() {
    SistemaPaciente sistema;

    login(); //Aqui sucede primero el Login
    cout<<"\nLogin succesful"<<endl;
    
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. List Patients" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                sistema.persona();
                break;
            case 2:
                sistema.listPatients();
                break;
            case 3:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
