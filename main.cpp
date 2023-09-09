#include <iostream>
using namespace std;
int main()
{
  cout << "\n\n Find the perfect numbers between 1 and 500:\n";
  cout << "------------------------------------------------\n";
  int i = 1, u = 1, sum = 0;
  cout << "\n The perfect numbers between 1 to 500 are: \n";
  while (i <= 500) //Mientras i sea menor igual que 500 sucedera:
  {
    while (u <= 500) //Sucedera otro mientras, "Mientras u sea menor o igual que 500 sucedera:"
    {
      if (u < i) //Dentro de este mientras, habra un "If", "Si u es menor que i, sucedera:"
      {
        if (i % u == 0) //Otro "If", que dice; "Si el residuo de I entre U es igual a 0;
          sum = sum + u; //La variable "Suma" se sumara a si misma mas el valor de U.
      }
      u++; //Mientras U sea menor que 500, su valor ira aumentando 1.
    }
    if (sum == i) { //Cuando la variable suma (que se esta sumando siempre su valor anterior más U) tenga el mismo valor que I
      cout << i << "  " << "\n"; //Se imprimira, dando a entender que es un número perfecto
    }
    i++; //Mientras i sea menor que 500, irá aumentando su valor en 1
    u = 1; //Mientras I sea menor que 500, U valdra 1.
    sum = 0; //Mientras I sea menor que 500, la suma valdrá 0.
  }
}
