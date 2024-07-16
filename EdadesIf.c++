#include <stdio.h>
#include <iostream>

using namespace std;
int edad;

int main()
{   
    cin >> edad;
    
    if (edad > 18){
        cout << "Es mayor de edad " << "porque tiene " << edad << " años";
    } else {
        cout << "No es mayor de edad " << "porque tiene " << edad << " años";
    }
    return 0;
}