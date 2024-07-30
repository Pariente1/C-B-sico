#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
string nombreUsuario;
string mesNacimiento;
char apellidoPaterno[256]= "";
char apellidoMaterno[256];
string RFC;

bool tieneApellidoMaterno = true;
//bool contienePalabraIndeseada = FALSE;

int main()
{   
    string apellidoPaterno="";
    string apellidoMaterno="";
    string nombreUsuario="";
    string diaNacimiento= "";
    string mesNacimiento="";
    string annoNacimiento = "";
    
    map<string, string>palabrasIndeseadas;

    palabrasIndeseadas["CULO"] = "CULO";
    palabrasIndeseadas["CACA"] = "CACA";
    palabrasIndeseadas["TETA"] = "TETA";
    
    cout << "Calculo de tu RFC \n";
    //nombre, aqui usamos #include string para poder accesar a multiples palabras a la ves por medio de getline.
    cout << "Introduce tus nombres: ";
    getline(cin,nombreUsuario);
    cout << "Tu nombre es: " << nombreUsuario << "\n";
   
    //apellidoPaterno
    cout << "Introduce tu apellido paterno: ";
    cin >> apellidoPaterno;
    cout << "Tu apellido paterno es: " << apellidoPaterno << "\n";
    
    //apellidoMaterno (opcional). Para hacerlo opcional usamos un while y un if.
        
    cout << "Introduce tu apellido materno (o escribe 'NO'): ";
    cin >> apellidoMaterno;
    
    while (tieneApellidoMaterno){
        if (apellidoMaterno.compare("no") == 0){
            tieneApellidoMaterno = false;
            apellidoMaterno = "X";
        } else {
            break;
        }
    }
    cout << "Tu apellido materno es: " << apellidoMaterno << "\n";
    
    //Comienza la fecha de nacimiento.
    cout << "Ahora veremos tu fecha de nacimiento en números \n";
   
    //Día de nacimiento
    cout << "Introduce el día en que naciste: ";
    cin >> diaNacimiento;
 
    //Mes de nacimiento
    cout << "Introduce el mes en que naciste: ";
    cin >> mesNacimiento;
    
    //Anno de nacimiento
    cout << "Introduce el año en que naciste en 4 digitos, por ejemplo 1992: ";
    cin >> annoNacimiento;
    
 
    // Aquí imprimimos en consola los datos del usuario que llenó anteriormente.
    cout << nombreUsuario << " " << apellidoPaterno << " " << apellidoMaterno << " tu fecha de nacimiento es el " << diaNacimiento << " de " << mesNacimiento << " del " << annoNacimiento << "\n";
    
    //Proceso de seleccionar el RFC
    //Aqui usamos esta linea para usar solo los últimos dos digitos usando arrays y substr como método.

    RFC = apellidoPaterno.substr(0,2) + (tieneApellidoMaterno ? apellidoMaterno.substr(0, 1) : "X") + nombreUsuario.substr(0,1) + annoNacimiento.substr(2,3) + mesNacimiento + diaNacimiento;
    
    // Aquí cambiamos todas las letras a mayusculas
    transform(RFC.begin(), RFC.end(), RFC.begin(), ::toupper);
    
    // Aqui colocamos la primera vocal después de la primera consonante en el primer apellidoPaterno para generar el RFC.
    RFC += apellidoPaterno[1]; 
    for (char c : apellidoPaterno) { 
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') { 
            RFC += c; break;     
        };
        
    };

    //Aquí nos aseguramos que no tenga ninguna de las palabras indeseadas {CULO, CACA, TETA}
    for (const auto& par : palabrasIndeseadas)/* auto& existe para deducir automaticamente el tipo de dato que es palabrasIndeseadas */ {
    size_t pos = RFC.find(par.first);
        if (pos != string::npos) /*Si posición(pos) NO ES IGUAL a npos(lo cual significa NOT FOUND) entonces queire decir que sí se encontró coincidencia por lo tanto se procede*/ {
    // Reemplazar la última letra de la palabra indeseada con 'X'
            RFC.replace(pos + par.first.length() - 1, 1, "X");
        } 
    }
    
    //Aquí imprimimos en consola el resultado.
    cout << "Tu RFC es: " << RFC << "XXX" /*agregamos las 3 Xs del... */ << endl;
    
     
    return 0;
}
