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
string user = "root";
string user_doc = "doc";
string user_nurse = "nurse";
int password = 1234;
int login_attempt = 0;
float earning_box = 0;

// Función para gestionar los gastos y ganancias del hospital
void gastos_ganancias(double& a, double& b) {
    b = b - a;
    cout << "El hospital ha ganado realmente: $" << b << endl;
    earning_box = earning_box + b;
    cout << "La caja de ganancias es: $" << earning_box << endl;
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
        cout << "Nombre: " << name << endl;
        cout << "Género: " << gender << endl;
        cout << "Edad: " << age << endl;
        cout << "Peso: " << weight << " kg" << endl;
        cout << "Altura: " << height << " cm" << endl;
        cout << "Alergias: " << allergies << endl;
        cout << "Caso: " << caseInfo << endl;
        cout << "Conclusión: " << conclusion << endl;
        cout << "Dinero Gastado: $" << moneySpent << endl;
        cout << "Dinero Ganado por el Hospital: $" << moneyEarned << endl;
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
        cout << "Ingrese el nombre del paciente: ";
        cin >> name;
        cout << "Ingrese el género del paciente: ";
        cin >> gender;
        cout << "Ingrese la edad del paciente: ";
        cin >> age;
        cout << "Ingrese el peso del paciente (kg): ";
        cin >> weight;
        cout << "Ingrese la altura del paciente (cm): ";
        cin >> height;
        cout << "Ingrese las alergias del paciente: ";
        getline(cin, allergies);
        cout << "Ingrese el caso del paciente: ";
        getline(cin, caseInfo);
        cout << "Ingrese la conclusión del caso: ";
        getline(cin, conclusion);
        cout << "Ingrese el dinero gastado: $";
        cin >> moneySpent;
        cout << "Ingrese el dinero ganado por el hospital: $";
        cin >> moneyEarned;
        gastos_ganancias(moneySpent, moneyEarned);
        Paciente paciente(name, gender, age, weight, height, allergies, caseInfo, conclusion, moneySpent, moneyEarned);
        persona_paciente.push_back(paciente);
        cout << "¡Paciente agregado exitosamente!" << endl;
    }

    // Función para listar todos los pacientes que se han agregado
    void listPatients() {
        if (persona_paciente.empty()) {
            cout << "No hay pacientes en el sistema." << endl;
            return;
        }

        cout << "Lista de Pacientes:" << endl;
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
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    for (const Paciente& paciente : pacientes) {
        outFile << "Nombre: " << paciente.name << endl;
        outFile << "Género: " << paciente.gender << endl;
        outFile << "Edad: " << paciente.age << endl;
        outFile << "Peso: " << paciente.weight << " kg" << endl;
        outFile << "Altura: " << paciente.height << " cm" << endl;
        outFile << "Alergias: " << paciente.allergies << endl;
        outFile << "Caso: " << paciente.caseInfo << endl;
        outFile << "Conclusión: " << paciente.conclusion << endl;
        outFile << "Dinero Gastado: $" << paciente.moneySpent << endl;
        outFile << "Dinero Ganado por el Hospital: $" << paciente.moneyEarned << endl;
        outFile << "------------------------" << endl;
    }

    outFile.close();
}
void apps(){
	fout.open("files/apps.txt", ios::app); 
	
	while(fout)
	{
		cout<<"Insert the name of the patient; "<<endl;
		getline(cin, pat_name);
		if(pat_name=="exit")
			break;
		fout<<pat_name<<endl;
		
		
		cout<<"Insert the time of the appointment "<<endl;
		getline(cin, pat_time);
		if(pat_time=="exit")
			break;
		fout<<pat_time<<endl;
	}
	fout.close();
	
}
void seeapps(){
	fin.open("files/apps.txt");
	
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
            cout << "Opciones:" << endl;
            cout << "1. Agregar Paciente" << endl;
            cout << "2. Listar Pacientes" << endl;
            cout << "3. Salir" << endl;
            cout << "4. Guardar Pacientes en un Archivo" << endl;
            cout << "5. Hacer cita" << endl;
            cout << "6. Ver las citas "<<endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    sistema.persona();
                    break;
                case 2:
                    sistema.listPatients();
                    break;
                case 3:
                    cout << "Saliendo del sistema." << endl;
                    return 0;
                case 4:
                    savePatientsToFile(sistema.persona_paciente, "datos_pacientes.txt");
                    cout << "Los datos de los pacientes se han guardado en 'datos_pacientes.txt'." << endl;
                    break;
                case 5:
                	apps();
                	break;
                case 6:
                	seeapps();
                	break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
            }
        }		
	  }
    return 0;
}

