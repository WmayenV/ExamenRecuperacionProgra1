#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>

using namespace std;

class corpoComercial{
public:
    void menuGeneral();
    void menuClientes();
    void menuVendedores();
    void menuProductos();
    void menuMarcas();
    void menuLineas();

private:
    string desicion;

};

void corpoComercial::menuGeneral(){
    system ("cls");
    int menu;
    cout << "\n\t\t\tBIENVENIDOS AL PROTOTIPO P1ER2022 DE WILLIAM OTTONIEL MAYEN VASQUEZ 9959-21-1581";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Clientes\n" << "\t\t[2] Vendedores\n" << "\t\t[3] Productos\n" << "\t\t[4] Marcas\n" << "\t\t[5] Lineas\n"<< "\t\t[6] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuClientes();
        break;
    case 2:
        menuVendedores();
        break;
    case 3:
        menuProductos();
        break;
    case 4:
        menuMarcas();
        break;
    case 5:
        menuLineas();
        break;
    case 6:
        cout << "\n\t\t�Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\t SALISTE DEL PROTOTIPO P1ER2022 DE WILLIAM OTTONIEL MAYEN VASQUEZ 9959-21-1581";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuGeneral();
        break;
        }
    }
}
