#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
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
    void registrarClientes();
    void modificarClientes();
    void eliminarClientes();
    void mostrarClientes();

    void menuVendedores();
    void registrarVendedores();
    void modificarVendedores();
    void eliminarVendedores();
    void mostrarVendedores();

    void menuProductos();
    void menuMarcas();
    void menuLineas();

private:
    string desicion, busquedaDatos, codigoCliente, nombreCli, direccionCli, nitCli, telefonoCli, codigoVen, statusCli, codigoVendedor, nombreVen, direccionVen, telefonoVen, nitVen, statusVen;

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

void corpoComercial::menuClientes(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU CLIENTES--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Cliente\n" << "\t\t[2] Modificar Cliente\n" <<  "\t\t[3] Eliminar Cliente\n" << "\t\t[4] Mostrar clientes\n" << "\t\t[5] Salir al --MENU GENERAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarClientes();
        break;
    case 2:
        modificarClientes();
        break;
    case 3:
        eliminarClientes();
        break;
    case 4:
        mostrarClientes();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU GENERAL--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void corpoComercial::registrarClientes(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR CLIENTES--\n" << endl;
    cout << "\n\t Quires salir al --MENU CLIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuClientes();
    }
    else {
        cout << "\n\t\tIngrese el codigo de cliente: "; cin >> codigoCliente;
        cout << "\t\tIngrese el nombre del cliente a registrar: "; cin >> nombreCli;
        cout << "\t\tIngrese la direccion del cliente a registrar: "; cin >> direccionCli;
        cout << "\t\tIngrese el nit del cliente a registrar: "; cin >> nitCli;
        cout << "\t\tIngrese el numero de telefono del clliente a registrar: "; cin >> telefonoCli;
        cout << "\t\tIngrese codigo de vendedor a registrar: "; cin >> codigoVen;
        cout << "\t\tIngrese el status del cliente: "; cin>>statusCli;
        cout << "\n\t--Registro cliente--\n" << endl;
        baseDatos.open("cliente.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< codigoCliente <<std::left<<std::setw(50)<< nombreCli <<std::left<<std::setw(10)<< direccionCli <<std::left<<std::setw(20)<< nitCli <<std::left<<std::setw(15)<< telefonoCli <<std::left<<std::setw(20)<< codigoVen << std::left<<std::setw(20)<< statusCli << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU CLIENTES--";
    cout<<"\n\t";system("pause");
    return menuClientes();
}

void corpoComercial::modificarClientes(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR CLIENTES--" << endl;
    cout << "\n\t Quires salir al --MENU CLIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuClientes();
    }
    else{
        baseDatos.open("clientes.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU Clientes--";
            cout<<"\n\t";system("pause");
            return menuClientes();
        }
        else {
            cout << "\n\t\t\tIngrese el codigo de cliente que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalClientes.dat",ios::app|ios::out|ios::binary);
            baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
            while (!baseDatos.eof()){
                if (busquedaDatos!=codigoCliente){
                    modBaseDatos<<std::left<<std::setw(20)<< codigoCliente <<std::left<<std::setw(50)<< nombreCli <<std::left<<std::setw(10)<< direccionCli<<std::left<<std::setw(20)<< nitCli <<std::left<<std::setw(15)<< telefonoCli <<std::left<<std::setw(20)<< codigoVen<< std::left<<std::setw(20)<< statusCli << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el codigo de cliente: "; cin >> codigoCliente;
                    cout << "\t\tIngrese el nombre del cliente a registrar: "; cin >> nombreCli;
                    cout << "\t\tIngrese la direccion del cliente a registrar: "; cin >> direccionCli;
                    cout << "\t\tIngrese el nit del cliente a registrar: "; cin >> nitCli;
                    cout << "\t\tIngrese el numero de telefono del clliente a registrar: "; cin >> telefonoCli;
                    cout << "\t\tIngrese codigo de vendedor a registrar: "; cin >> codigoVen;
                    cout << "\t\tIngrese el status del cliente: "; cin>>statusCli;
                    modBaseDatos<<std::left<<std::setw(20)<< codigoCliente <<std::left<<std::setw(50)<< nombreCli <<std::left<<std::setw(10)<< direccionCli<<std::left<<std::setw(20)<< nitCli <<std::left<<std::setw(15)<< telefonoCli <<std::left<<std::setw(20)<< codigoVen<< std::left<<std::setw(20)<< statusCli << "\n";
                }
                 baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "clientes.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalClientes.dat","clientes.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU CLIENTES--";
        cout<<"\n\t";system("pause");
        return menuClientes();
    }
}

void corpoComercial::eliminarClientes(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR CLIETNES--" << endl;
	cout << "\n\t Quires salir al --MENU CLIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuClientes();
    }
    else {
        baseDatos.open("clientes.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el codigo del cliente que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalClientes.dat", ios::app | ios::out | ios::binary);
           baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
            while(!baseDatos.eof())
            {
                if(busquedaDatos!=codigoCliente)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< codigoCliente <<std::left<<std::setw(50)<< nombreCli <<std::left<<std::setw(10)<< direccionCli<<std::left<<std::setw(20)<< nitCli <<std::left<<std::setw(15)<< telefonoCli <<std::left<<std::setw(20)<< codigoVen<< std::left<<std::setw(20)<< statusCli << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
               baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Empleado no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "clientes.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalClientes.dat","clientes.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU CLIENTES--";
        cout<<"\n\t";system("pause");
        return menuClientes();
    }
}

void corpoComercial::mostrarClientes(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR CLIETNES--";
    cout << "\n\t Quires salir al --MENU CLIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuClientes();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a un cliente en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("clientes.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR CLIENTE--"<<endl;
                cout << "\n\t\tIngrese el codigo del cliente a buscar: "; cin >> busquedaDatos;
                baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
                while(!baseDatos.eof()){
                    if(busquedaDatos==codigoCliente){
                        cout << "\n\t\tCcodigo de cliente: "; cin >> codigoCliente;
                        cout << "\t\tNombre del cliente: "; cin >> nombreCli;
                        cout << "\t\tDireccion del cliente: "; cin >> direccionCli;
                        cout << "\t\tNit del cliente: "; cin >> nitCli;
                        cout << "\t\tTelefono del clliente: "; cin >> telefonoCli;
                        cout << "\t\tCodigo de vendedor: "; cin >> codigoVen;
                        cout << "\t\tStatus del cliente: "; cin>>statusCli;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU CLIENTES--";
                        cout<<"\n\t";system("pause");
                        return menuClientes();
                    }
                  baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR CLIENTES--";
                    cout<<"\n\t";system("pause");
                    return mostrarClientes();
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                }
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR Clientes"<<endl;
            baseDatos.open("clientes.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU Clientes--";
                cout<<"\n\t";system("pause");
                return menuClientes();
            }
            else
            {
                baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
                while(!baseDatos.eof())
                {
                    total++;
                    cout << "\n\t\tCcodigo de cliente: "; cin >> codigoCliente;
                        cout << "\t\tNombre del cliente: "; cin >> nombreCli;
                        cout << "\t\tDireccion del cliente: "; cin >> direccionCli;
                        cout << "\t\tNit del cliente: "; cin >> nitCli;
                        cout << "\t\tTelefono del clliente: "; cin >> telefonoCli;
                        cout << "\t\tCodigo de vendedor: "; cin >> codigoVen;
                        cout << "\t\tStatus del cliente: "; cin>>statusCli;
                    baseDatos>>codigoCliente>>nombreCli>>direccionCli>>nitCli>>telefonoCli>>codigoVen>>statusCli;
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\tRegresando al --MENU CLIENTES--";
                cout<<"\n\t";system("pause");
                return menuClientes();
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
}

void corpoComercial::menuVendedores(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU VENDEDORES--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Vendedor\n" << "\t\t[2] Modificar Vendedor\n" <<  "\t\t[3] Eliminar Vendedor\n" << "\t\t[4] Mostrar Vendedor\n" << "\t\t[5] Salir al --MENU GENERAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarVendedores();
        break;
    case 2:
        modificarVendedores();
        break;
    case 3:
        eliminarVendedores();
        break;
    case 4:
        mostrarVendedores();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU GENERAL--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void corpoComercial::registrarVendedores(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR VENDEDORES--\n" << endl;
    cout << "\n\t Quires salir al --MENU VENDEDORES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuVendedores();
    }
    else {
        cout << "\n\t\tIngrese el codigo de vendedor: "; cin >> codigoVendedor;
        cout << "\t\tIngrese el nombre del vendedor a registrar: "; cin >> nombreVen;
        cout << "\t\tIngrese la direccion del vendedor a registrar: "; cin >> direccionVen;
        cout << "\t\tIngrese el nit del vendedor a registrar: "; cin >> nitVen;
        cout << "\t\tIngrese el numero de telefono del vendedor a registrar: "; cin >> telefonoVen;
        cout << "\t\tIngrese el status del vendedor: "; cin>>statusVen;
        cout << "\n\t--Registro vendedor--\n" << endl;
        baseDatos.open("vendedores.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< codigoVendedor <<std::left<<std::setw(50)<< nombreVen <<std::left<<std::setw(10)<< direccionVen <<std::left<<std::setw(20)<< nitVen <<std::left<<std::setw(15)<< telefonoVen << std::left<<std::setw(20)<< statusVen << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU CLIENTES--";
    cout<<"\n\t";system("pause");
    return menuVendedores();
}

void corpoComercial::modificarVendedores(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR VENDEDORES--" << endl;
    cout << "\n\t Quires salir al --MENU VENDEDORES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuVendedores();
    }
    else{
        baseDatos.open("vendedores.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU VEndedores--";
            cout<<"\n\t";system("pause");
            return menuVendedores();
        }
        else {
            cout << "\n\t\t\tIngrese el codigo de vendedor que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalVendedores.dat",ios::app|ios::out|ios::binary);
            baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
            while (!baseDatos.eof()){
                if (busquedaDatos!=codigoVendedor){
                    modBaseDatos<<std::left<<std::setw(20)<< codigoVendedor <<std::left<<std::setw(50)<< nombreVen <<std::left<<std::setw(10)<< direccionVen <<std::left<<std::setw(20)<< nitVen <<std::left<<std::setw(15)<< telefonoVen << std::left<<std::setw(20)<< statusVen << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el codigo de vendedor: "; cin >> codigoVendedor;
                    cout << "\t\tIngrese el nombre del vendedor a registrar: "; cin >> nombreVen;
                    cout << "\t\tIngrese la direccion del vendedor a registrar: "; cin >> direccionVen;
                    cout << "\t\tIngrese el nit del vendedor a registrar: "; cin >> nitVen;
                    cout << "\t\tIngrese el numero de telefono del vendedor a registrar: "; cin >> telefonoVen;
                    cout << "\t\tIngrese el status del vendedor: "; cin>>statusVen;
                    modBaseDatos<<std::left<<std::setw(20)<< codigoVendedor <<std::left<<std::setw(50)<< nombreVen <<std::left<<std::setw(10)<< direccionVen <<std::left<<std::setw(20)<< nitVen <<std::left<<std::setw(15)<< telefonoVen << std::left<<std::setw(20)<< statusVen << "\n";
                }
                 baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "vendedores.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalVendedores.dat","vendedores.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU VENDEDORES--";
        cout<<"\n\t";system("pause");
        return menuVendedores();
    }
}

void corpoComercial::eliminarVendedores(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR VENDEDORES--" << endl;
	cout << "\n\t Quires salir al --MENU VENDEDORES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuVendedores();
    }
    else {
        baseDatos.open("vendedores.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el codigo del vendedor que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalVendedores.dat", ios::app | ios::out | ios::binary);
           baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
            while(!baseDatos.eof())
            {
                if(busquedaDatos!=codigoVendedor)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< codigoVendedor <<std::left<<std::setw(50)<< nombreVen <<std::left<<std::setw(10)<< direccionVen <<std::left<<std::setw(20)<< nitVen <<std::left<<std::setw(15)<< telefonoVen << std::left<<std::setw(20)<< statusVen << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
             baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Vendedor no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "vendedores.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalVendedores.dat","vendedores.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU VENDEDORES--";
        cout<<"\n\t";system("pause");
        return menuVendedores();
    }
}

void corpoComercial::mostrarVendedores(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR VENDEDORES--";
    cout << "\n\t Quires salir al --MENU VENDEDORES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuVendedores();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a un vendedor en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("vendedores.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR VENDEDORES--"<<endl;
                cout << "\n\t\tIngrese el codigo del vendedor a buscar: "; cin >> busquedaDatos;
                baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
                while(!baseDatos.eof()){
                    if(busquedaDatos==codigoCliente){
                        cout << "\n\t\tCodigo de vendedor: "; cin >> codigoVendedor;
                        cout << "\t\tNombre del vendedor: "; cin >> nombreVen;
                        cout << "\t\tDireccion del vendedor: "; cin >> direccionVen;
                        cout << "\t\tNit del vendedor: "; cin >> nitVen;
                        cout << "\t\tTelefono del vendedor: "; cin >> telefonoVen;
                        cout << "\t\tStatus del vendedor: "; cin>>statusVen;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU VENDEDORES--";
                        cout<<"\n\t";system("pause");
                        return menuVendedores();
                    }
                  baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR VENDEDORES--";
                    cout<<"\n\t";system("pause");
                    return mostrarVendedores();
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                }
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR VENDEDORES"<<endl;
            baseDatos.open("vendedores.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU Clientes--";
                cout<<"\n\t";system("pause");
                return menuVendedores();
            }
            else
            {
               baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
                while(!baseDatos.eof())
                {
                    total++;
                        cout << "\n\t\tCodigo de vendedor: "; cin >> codigoVendedor;
                        cout << "\t\tNombre del vendedor: "; cin >> nombreVen;
                        cout << "\t\tDireccion del vendedor: "; cin >> direccionVen;
                        cout << "\t\tNit del vendedor: "; cin >> nitVen;
                        cout << "\t\tTelefono del vendedor: "; cin >> telefonoVen;
                        cout << "\t\tStatus del vendedor: "; cin>>statusVen;
                    baseDatos>>codigoVendedor>>nombreVen>>direccionVen>>nitVen>>telefonoVen>>statusVen;
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\tRegresando al --MENU VEndedores--";
                cout<<"\n\t";system("pause");
                return menuVendedores();
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
}


