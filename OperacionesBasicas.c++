#include <stdio.h>
#include <iostream>

using namespace std;
int valor1;
int valor2;
int resultadoSuma;
int resultadoResta;
int resultadoMultiplicacion;
int resultadoDivision;

int main()
{   
    cout << "Teclea el primer valor: ";
    cin >> valor1;
    cout << "Teclea el segundo valor: ";
    cin >> valor2;
    
    resultadoSuma=valor1+valor2;
    
    cout <<"La suma es: " << resultadoSuma << "\n";
    
    resultadoResta=valor1-valor2;
    
    cout << "La resta es: " <<resultadoResta << "\n";
    
    resultadoMultiplicacion = valor1*valor2;
    
    cout <<"La multiplicacion es: "<< resultadoMultiplicacion << "\n";
    
    resultadoDivision = valor1 / valor2;
    
    cout << "La division es: " << resultadoDivision << "\n";
    
    return 0;
}
