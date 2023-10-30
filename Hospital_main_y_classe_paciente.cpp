#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string user_input;
string password_input;
ofstream fout; // write to a file
ifstream fin; // read from a file
string pat_name;
string pat_time;
string mytext;
string user = "admin";
string user_doc = "doc";
string user_nurse = "nurse";
int password = 1234;
int login_attempt = 0;
float earning_box = 0;
void sep(){
	cout<<"\n/////////////////////////"<<endl;
}
// Función para gestionar los gastos y ganancias del hospital
void gastos_ganancias(double& a, double& b) {
    b = b - a;
    cout << "The hospital has earned : $" << b << endl;
    earning_box = earning_box + b;
    cout << "The Total earning box is: $" << earning_box << endl;
}

class Paciente {
public:
    // Constructor de la clase Paciente
    Paciente(string name, string gender, int age, double weight, double height, string allergies, string caseInfo, string conclusion, double moneySpent, double moneyEarned) :
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

    // Función para mostrar la información del paciente
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Allergiess: " << allergies << endl;
        cout << "Case: " << caseInfo << endl;
        cout << "Conclusion: " << conclusion << endl;
        cout << "Money Spent: $" << moneySpent << endl;
        cout << "Money earned: $" << moneyEarned << endl;
        cout << "------------------------" << endl;
    }

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

class SistemaCitas {
public:
    // Función para gestionar citas
    void persona() {
        string cita;
        cout << "Ingrese una cita: ";
        getline(cin, cita);
    }
};

class SistemaPaciente {
public:
    // Función para agregar un paciente a la clase Paciente
    void persona() {
        string name, gender, allergies, caseInfo, conclusion;
        int age;
        double weight, height, moneySpent, moneyEarned;
        cout << "Enter the name of the patient: ";
		cin>>name;
        cout << "Enter the gender of the patient: ";
        cin>>age;
        cout << "Enter the age of the patient: ";
        cin >> age;
        cout << "Enter the weight of the patient (kg): ";
        cin >> weight;
        cout << "Enter the height of the patient (cm): ";
        cin >> height;
        cout << "Enter the allergies of the patient: ";
        getline(cin, allergies);
        cout << "Enter the case of the patient: ";
        getline(cin, caseInfo);
        cout << "Enter the conclusion of the case: ";
        getline(cin, conclusion);
        cout << "Enter the money spent: $";
        cin >> moneySpent;
        cout << "Enter the money earned by the hospital: $";
        cin >> moneyEarned;
        gastos_ganancias(moneySpent, moneyEarned);
        Paciente paciente(name, gender, age, weight, height, allergies, caseInfo, conclusion, moneySpent, moneyEarned);
        persona_paciente.push_back(paciente);
        cout << "Patient succesfully added!" << endl;
    }

    // Función para listar todos los pacientes que se han agregado
    void listPatients() {
        if (persona_paciente.empty()) {
            cout << "Not enough patients in the system." << endl;
            return;
        }

        cout << "Patient's list: '" << endl;
        for (const auto& paciente : persona_paciente) {
            paciente.display();
        }
    }

public:
    vector<Paciente> persona_paciente;
};

// Función para gestionar el inicio de sesión
int login(){
    while (login_attempt < 3)
    {
        cout<<"User: ";
        cin>>user_input;
        if(user_input == user or user_input == user_doc or user_input == user_nurse){
            cout<<"Success";
            return 1;
            break;
            
        }
    
        else{
            cout<<"Invalid User or Password."<<endl;
            login_attempt++;
        }
        // no es necesario el if porque ya tenes la declaracion en la funcion while
       if(login_attempt >3){
            cout<<"Many failed attempts, muere (figurativamente)."<<endl;
             // Esta es una funcion que para que el programa
            return 0;
           break;
        }
    }
        return 0;
    //hasta aca
}


void savePatientsToFile(const vector<Paciente>& pacientes, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Failure trying to open the file. " << filename << endl;
        return;
    }

    for (const Paciente& paciente : pacientes) {
        outFile << "Name: " << paciente.name << endl;
        outFile << "Gender: " << paciente.gender << endl;
        outFile << "Age: " << paciente.age << endl;
        outFile << "Weight: " << paciente.weight << " kg" << endl;
        outFile << "Height: " << paciente.height << " cm" << endl;
        outFile << "Allergies: " << paciente.allergies << endl;
        outFile << "Case: " << paciente.caseInfo << endl;
        outFile << "Conclusion: " << paciente.conclusion << endl;
        outFile << "Money Spent: $" << paciente.moneySpent << endl;
        outFile << "Money earned by the hospital: $" << paciente.moneyEarned << endl;
        outFile << "------------------------" << endl;
    }

    outFile.close();
}
void apps(const string& a){
	ofstream outFile(a);
	if(!outFile){
		cerr << "Failure trying to open the file : "<<a<<endl;
	}
	
	while(fout)
	{
		cout<<"Insert the name of the patient: "<<endl;
		getline(cin, pat_name);
		if(pat_name=="exit")
			break;
		outFile << pat_name << endl;
		
		
		cout<<"Insert the time of the appointment "<<endl;
		getline(cin, pat_time);
		if(pat_time=="exit")
			break;
		outFile << pat_time << endl;
	}
	outFile.close();
	
}
void seeapps(){
	fin.open("apps.txt");
	
	while(getline(fin, mytext))
	{
		cout<<"This is from the file: "<<mytext<<endl;
	}
	fin.close();
}
int main() {
    int choice;
    SistemaPaciente sistema;
  
    int loginvalue = login(); 
	cout<<"\n"<<loginvalue<< endl;
  	if (loginvalue == 1 )
	  {
        while (true) {
        	sep();
            cout << "Options:" << endl;
            cout << "1. Add patient" << endl;
            cout << "2. List patients" << endl;
            cout << "3. Exit" << endl;
            cout << "4. Save patients to a file: " << endl;
            cout << "5. Make an appointment" << endl;
            cout << "6. See the appointments "<<endl;
            cin >> choice;
            switch (choice) {
                case 1:
                	sep();
                    sistema.persona();
                    break;
                case 2:
                	sep();
                    sistema.listPatients();
                    break;
                case 3:
                	sep();
                    cout << "Exiting system." << endl;
                    return 0;
                case 4:
                	sep();
                    savePatientsToFile(sistema.persona_paciente, "datos_pacientes.txt");
                    cout << "The data of the patient has been succesfully added into 'datos_patients.txt'" << endl;
                    break;
                case 5:
                	sep();
                	apps("apps.txt");
                	break;
                case 6:
                	sep();
                	seeapps();
                	break;
                default:
                	sep();
                    cout << "No valid option, try again." << endl;
            }
        }		
	  }
    return 0;
}

