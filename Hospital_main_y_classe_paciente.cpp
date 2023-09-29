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
string user_doc = "doc";
string user_nurse = "nurse";
int password= 1234;
int login_attempt = 0;
float earning_box = 0;
//end of global variables
void gastos_ganancias(double& a, double& b){
    b = b - a; //B = MoneySpent, osea dinero dado por el hospital....
    cout<<"The hospital has really earned: $"<<b<<endl;
    earning_box = earning_box + b;
    cout<<"The earning box is: $"<<earning_box<<endl;
}
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
    double gastos;
};

class SistemaPaciente {
public:
    // Funcion para agregar una paciente a la classe paciente
    void persona() {
        string name, gender, allergies, caseInfo, conclusion;
        int age;
        double weight, height, moneySpent, moneyEarned, gastos;

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
        gastos_ganancias(moneySpent, moneyEarned);
        Paciente paciente(name, gender, age, weight, height, allergies, caseInfo, conclusion, moneySpent, moneyEarned);
        // la linea de abajo se encarga de mandar los pacientes al final del vector persona_paciente por medio del metodo push_back
        persona_paciente.push_back(paciente);

        cout << "Patient added successfully!" << endl;
    }
/*class SistemaDoctor {
	public:
		
}*/

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
        if(user_input == user or user_input == user_doc or user_input == user_nurse){
            cout<<"Success";
            break;
        }
        else{
            cout<<"Invalid User or Password."<<endl;
            login_attempt++;
        }
        // no es necesario el if porque ya tenes la declaracion en la funcion while
       if(login_attempt >=3){
            cout<<"Many failed attempts, muere (figurativamente)."<<endl;
             // Esta es una funcion que para que el programa
           break;
        }
        
    //hasta aca
    }
}

// inicio de la clase main
int main() {
	int choice;
    SistemaPaciente sistema;
//Que el paciente haga citas, que el paciente pague, anadir al paciente a la agenda del doctor
  	login(); //Aqui sucede primero el Login
    cout<<"\nLogin succesful"<<endl;
    if (user_input == user_nurse or user_input == user_doc)
	{
    	while (true) 
		{
        	cout << "Options:" << endl;
        	cout << "1. Add Patient" << endl;
        	cout << "2. List Patients" << endl;
        	cout << "3. Exit" << endl;
        	cin>>choice;
        	switch (choice) {
	            case 1:
	                sistema.persona();
	                break;
	            case 2:
	                sistema.listPatients();
	                break;
	            case 3:
	                cout << "Exiting the system." << endl;
	            case 4:
	                return 0;
	            case 5:
	                cout<<"Las ganancias son; "<<earning_box<<endl;
	                break;
	            default:
	                cout << "Invalid choice. Please try again." << endl;
        	}	
    	}
	}
       
        cout << "3. Exit" << endl;
        cout << "5. Expenses and Earnings "<<endl;
        cout << "Enter your choice: ";
        
    
/*
        switch (choice) {
            case 1:
                sistema.persona();
                break;
            case 2:
                sistema.listPatients();
                break;
            case 3:
                cout << "Exiting the system." << endl;
            case 4:
                return 0;
            case 5:
                cout<<"Las ganancias son; "<<earning_box<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }*/
   	return 0;
    }


