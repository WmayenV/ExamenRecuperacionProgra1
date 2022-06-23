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
    //menuGeneral//
    void menuGeneral();
    //menuclientes//
    void menuClientes();
    void registrarClientes();
    void modificarClientes();
    void eliminarClientes();
    void mostrarClientes();
    //menuVendedores//
    void menuVendedores();
    void registrarVendedores();
    void modificarVendedores();
    void eliminarVendedores();
    void mostrarVendedores();
    //menu Productos
    void menuProductos();
    void registrarProductos();
    void modificarProductos();
    void eliminarProductos();
    void mostrarProductos();
   // menuMarcas
    void menuMarcas();
    void registrarMarcas();
    void modificarMarcas();
    void eliminarMarcas();
    void mostrarMarcas();
    // menuLineas
    void menuLineas();
    void registrarLineas();
    void modificarLineas();
    void eliminarLineas();
    void mostrarLineas();

private:
    string desicion, busquedaDatos, codigoCliente, nombreCli, direccionCli, nitCli, telefonoCli, codigoVen, statusCli, codigoVendedor, nombreVen, direccionVen, telefonoVen, nitVen, statusVen, codigoProducto, nombreProd, codLinea, codMarca, exisProd, statusProd, codigoMarca, nombreMarca, statusMarca, codigoLinea, nombreLinea, statusLinea;

};
//inicio menuGeneral
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
//fin MenuGeneral//
// inicio Menuclientes//
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
// fin menu clientes//
//inicio menuVendedores//
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
                    if(busquedaDatos==codigoVendedor){
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
// fin menu vendedores//
//inicio menu Productos//
void corpoComercial::menuProductos(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU PRODUCTOS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar productos\n" << "\t\t[2] Modificar productos\n" <<  "\t\t[3] Eliminar prodductos\n" << "\t\t[4] Mostrar productos\n" << "\t\t[5] Salir al --MENU GENERAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarProductos();
        break;
    case 2:
        modificarProductos();
        break;
    case 3:
        eliminarProductos();
        break;
    case 4:
        mostrarProductos();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU GENERAL--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}


void corpoComercial::registrarProductos(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR PRODUCTOS--\n" << endl;
    cout << "\n\t Quires salir al --MENU PRODUCTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuProductos();
    }
    else {
        cout << "\n\t\tIngrese el codigo de producto: "; cin >> codigoProducto;
        cout << "\t\tIngrese el nombre del producto a registrar: "; cin >> nombreProd;
        cout << "\t\tIngrese codigo de linea a registrar: "; cin >> codLinea;
        cout << "\t\tIngrese codugo de marca a registrar: "; cin >> codMarca;
        cout << "\t\tIngrese el numero de existencias a registrar: "; cin >> exisProd;
        cout << "\t\tIngrese el status del producto: "; cin>>statusProd;
        cout << "\n\t--Registro producto--\n" << endl;
        baseDatos.open("productos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< codigoProducto <<std::left<<std::setw(50)<< nombreProd <<std::left<<std::setw(10)<< codLinea <<std::left<<std::setw(20)<< codMarca <<std::left<<std::setw(15)<< exisProd << std::left<<std::setw(20)<< statusProd << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU PRODUCTOS--";
    cout<<"\n\t";system("pause");
    return menuProductos();
}

void corpoComercial::modificarProductos(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR PRODUCTOS--" << endl;
    cout << "\n\t Quires salir al --MENU PRODUCTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuProductos();
    }
    else{
        baseDatos.open("productos.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU PRODUCTOS--";
            cout<<"\n\t";system("pause");
            return menuProductos();
        }
        else {
            cout << "\n\t\t\tIngrese el codigo de prducto que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalProductos.dat",ios::app|ios::out|ios::binary);
            baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
            while (!baseDatos.eof()){
                if (busquedaDatos!=codigoVendedor){
                    modBaseDatos<<std::left<<std::setw(20)<< codigoProducto <<std::left<<std::setw(50)<< nombreProd <<std::left<<std::setw(10)<< codLinea <<std::left<<std::setw(20)<< codMarca <<std::left<<std::setw(15)<< exisProd << std::left<<std::setw(20)<< statusProd << "\n";
                }
                else {
                   cout << "\n\t\tIngrese el codigo de producto: "; cin >> codigoProducto;
                    cout << "\t\tIngrese el nombre del producto a registrar: "; cin >> nombreProd;
                    cout << "\t\tIngrese codigo de linea a registrar: "; cin >> codLinea;
                    cout << "\t\tIngrese codugo de marca a registrar: "; cin >> codMarca;
                    cout << "\t\tIngrese el numero de existencias a registrar: "; cin >> exisProd;
                    cout << "\t\tIngrese el status del producto: "; cin>>statusProd;
                    modBaseDatos<<std::left<<std::setw(20)<< codigoProducto <<std::left<<std::setw(50)<< nombreProd <<std::left<<std::setw(10)<< codLinea <<std::left<<std::setw(20)<< codMarca <<std::left<<std::setw(15)<< exisProd << std::left<<std::setw(20)<< statusProd << "\n";
                }
                  baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "productos.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalProductos.dat","productos.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU Productos--";
        cout<<"\n\t";system("pause");
        return menuProductos();
    }
}

void corpoComercial::eliminarProductos(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR PRODUCTOS--" << endl;
	cout << "\n\t Quires salir al --MENU PRODUCTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuProductos();
    }
    else {
        baseDatos.open("productos.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el codigo del producto que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalProductos.dat", ios::app | ios::out | ios::binary);
          baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
            while(!baseDatos.eof())
            {
                if(busquedaDatos!=codigoProducto)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< codigoProducto <<std::left<<std::setw(50)<< nombreProd <<std::left<<std::setw(10)<< codLinea <<std::left<<std::setw(20)<< codMarca <<std::left<<std::setw(15)<< exisProd << std::left<<std::setw(20)<< statusProd << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
              baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Producto no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "productos.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalProductos.dat","productos.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU PRODUCTOS--";
        cout<<"\n\t";system("pause");
        return menuProductos();
    }
}

void corpoComercial::mostrarProductos(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR PRODUCTOS--";
    cout << "\n\t Quires salir al --MENU RRODUCTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuProductos();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a un producto en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("productos.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR PRODCUTOS--"<<endl;
                cout << "\n\t\tIngrese el codigo del producto a buscar: "; cin >> busquedaDatos;
                baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
                while(!baseDatos.eof()){
                    if(busquedaDatos==codigoProducto){
                        cout << "\n\t\tCodigo del producto: "; cin >> codigoProducto;
                        cout << "\t\tNombre del producto: "; cin >> nombreProd;
                        cout << "\t\tCodigo de linea del producto: "; cin >> codLinea;
                        cout << "\t\tCodigo de marca del producto: "; cin >> codMarca;
                        cout << "\t\tExostencia del producto: "; cin >> exisProd;
                        cout << "\t\tStatus del producto: "; cin>>statusProd;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU [PRODUCTOS--";
                        cout<<"\n\t";system("pause");
                        return menuProductos();
                    }
                   baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR PRODUCTOS--";
                    cout<<"\n\t";system("pause");
                    return mostrarProductos();
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
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR PRODUCTOS"<<endl;
            baseDatos.open("productos.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU PRODUCTOS--";
                cout<<"\n\t";system("pause");
                return menuProductos();
            }
            else
            {
               baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
                while(!baseDatos.eof())
                {
                    total++;
                        cout << "\n\t\tCodigo del producto: "; cin >> codigoProducto;
                        cout << "\t\tNombre del producto: "; cin >> nombreProd;
                        cout << "\t\tCodigo de linea del producto: "; cin >> codLinea;
                        cout << "\t\tCodigo de marca del producto: "; cin >> codMarca;
                        cout << "\t\tExostencia del producto: "; cin >> exisProd;
                        cout << "\t\tStatus del producto: "; cin>>statusProd;
                   baseDatos>>codigoProducto>>nombreProd>>codLinea>>codMarca>>exisProd>>statusProd;
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
                cout <<"\n\n\t\tRegresando al --MENU PRODUCTOS--";
                cout<<"\n\t";system("pause");
                return menuProductos();
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
//fin menu productos//
// inicio menu Marcas//
void corpoComercial::menuMarcas(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU MARCAS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar marcas\n" << "\t\t[2] Modificar marcas\n" <<  "\t\t[3] Eliminar marcas\n" << "\t\t[4] Mostrar marcas\n" << "\t\t[5] Salir al --MENU GENERAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarMarcas();
        break;
    case 2:
        modificarMarcas();
        break;
    case 3:
        eliminarMarcas();
        break;
    case 4:
        mostrarMarcas();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU GENERAL--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void corpoComercial::registrarMarcas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR MARCA--\n" << endl;
    cout << "\n\t Quires salir al --MENU MARCAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMarcas();
    }
    else {
        cout << "\n\t\tIngrese el codigo de marca: "; cin >> codigoMarca;
        cout << "\t\tIngrese el nombre de marca a registrar: "; cin >> nombreMarca;
        cout << "\t\tIngrese el status del producto: "; cin>>statusMarca;
        cout << "\n\t--Registro marca--\n" << endl;
        baseDatos.open("productos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< codigoMarca <<std::left<<std::setw(50)<< nombreMarca << std::left<<std::setw(20)<< statusMarca << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU MARCAS--";
    cout<<"\n\t";system("pause");
    return menuMarcas();
}

void corpoComercial::modificarMarcas(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR MARCAS--" << endl;
    cout << "\n\t Quires salir al --MENU MARCAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMarcas();
    }
    else{
        baseDatos.open("marcas.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU MARCAS--";
            cout<<"\n\t";system("pause");
            return menuMarcas();
        }
        else {
            cout << "\n\t\t\tIngrese el codigo de marca que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalMarcas.dat",ios::app|ios::out|ios::binary);
            baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
            while (!baseDatos.eof()){
                if (busquedaDatos!=codigoMarca){
                    modBaseDatos<<std::left<<std::setw(20)<< codigoMarca <<std::left<<std::setw(50)<< nombreMarca << std::left<<std::setw(20)<< statusMarca << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el codigo de marca: "; cin >> codigoMarca;
                    cout << "\t\tIngrese el nombre de marca a registrar: "; cin >> nombreMarca;
                    cout << "\t\tIngrese el status del producto: "; cin>>statusMarca;
                     modBaseDatos<<std::left<<std::setw(20)<< codigoMarca <<std::left<<std::setw(50)<< nombreMarca << std::left<<std::setw(20)<< statusMarca << "\n";
                }
                 baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "marcas.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalMarcas.dat","marcas.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU MARCAS--";
        cout<<"\n\t";system("pause");
        return menuMarcas();
    }
}

void corpoComercial::eliminarMarcas(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR MARCA--" << endl;
	cout << "\n\t Quires salir al --MENU MARCA--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMarcas();
    }
    else {
        baseDatos.open("marcas.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el codigo del marca que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalMarcas.dat", ios::app | ios::out | ios::binary);
          baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
            while(!baseDatos.eof())
            {
                if(busquedaDatos!=codigoMarca)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< codigoMarca <<std::left<<std::setw(50)<< nombreMarca << std::left<<std::setw(20)<< statusMarca << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
             baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Producto no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "marcas.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalMarcas.dat","marcas.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU MARCAS--";
        cout<<"\n\t";system("pause");
        return menuMarcas();
    }
}

void corpoComercial::mostrarMarcas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR MARCA--";
    cout << "\n\t Quires salir al --MENU MARCAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMarcas();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a una marca en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("marcas.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR MARCAS--"<<endl;
                cout << "\n\t\tIngrese el codigo de marca a buscar: "; cin >> busquedaDatos;
                 baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
                while(!baseDatos.eof()){
                    if(busquedaDatos==codigoProducto){
                        cout << "\n\t\tCodigo de marca: "; cin >> codigoMarca;
                        cout << "\t\tNombre de marca: "; cin >> nombreMarca;
                        cout << "\t\tStatus de marca: "; cin>>statusMarca;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU MARCAS--";
                        cout<<"\n\t";system("pause");
                        return menuProductos();
                    }
                   baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR MARCA--";
                    cout<<"\n\t";system("pause");
                    return mostrarMarcas();
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
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR  MARCAS"<<endl;
            baseDatos.open("marcas.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU MARCAS--";
                cout<<"\n\t";system("pause");
                return menuMarcas();
            }
            else
            {
                baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
                while(!baseDatos.eof())
                {
                    total++;
                        cout << "\n\t\tCodigo de marca: "; cin >> codigoMarca;
                        cout << "\t\tNombre de marca: "; cin >> nombreMarca;
                        cout << "\t\tStatus de marca: "; cin>>statusMarca;
                    baseDatos>>codigoMarca>>nombreMarca>>statusMarca;
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
                cout <<"\n\n\t\tRegresando al --MENU MARCAS--";
                cout<<"\n\t";system("pause");
                return menuMarcas();
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
//fin menuMarcas//
void corpoComercial::menuLineas(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU LINEAS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar lineas\n" << "\t\t[2] Modificar lineas\n" <<  "\t\t[3] Eliminar lineas\n" << "\t\t[4] Mostrar lineas\n" << "\t\t[5] Salir al --MENU GENERAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarLineas();
        break;
    case 2:
        modificarLineas();
        break;
    case 3:
        eliminarLineas();
        break;
    case 4:
        mostrarLineas();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU GENERAL--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void corpoComercial::registrarLineas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR LINEA--\n" << endl;
    cout << "\n\t Quires salir al --MENU LINEA--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuLineas();
    }
    else {
        cout << "\n\t\tIngrese el codigo de lineas: "; cin >> codigoLinea;
        cout << "\t\tIngrese el nombre de linea a registrar: "; cin >> nombreLinea;
        cout << "\t\tIngrese el status del linea: "; cin>>statusLinea;
        cout << "\n\t--Registro linea--\n" << endl;
        baseDatos.open("lineas.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< codigoLinea <<std::left<<std::setw(50)<< nombreLinea << std::left<<std::setw(20)<< statusLinea << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU LINEAS--";
    cout<<"\n\t";system("pause");
    return menuLineas();
}

void corpoComercial::modificarLineas(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR LINEAS--" << endl;
    cout << "\n\t Quires salir al --MENU LINEAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuLineas();
    }
    else{
        baseDatos.open("lineas.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU LINEAS--";
            cout<<"\n\t";system("pause");
            return menuLineas();
        }
        else {
            cout << "\n\t\t\tIngrese el codigo de lineas que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalLineas.dat",ios::app|ios::out|ios::binary);
            baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
            while (!baseDatos.eof()){
                if (busquedaDatos!=codigoLinea){
                    modBaseDatos<<std::left<<std::setw(20)<< codigoLinea <<std::left<<std::setw(50)<< nombreLinea << std::left<<std::setw(20)<< statusLinea << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el codigo de linea: "; cin >> codigoLinea;
                    cout << "\t\tIngrese el nombre de linea a modificar: "; cin >> nombreLinea;
                    cout << "\t\tIngrese el status del linea: "; cin>>statusLinea;
                     modBaseDatos<<std::left<<std::setw(20)<< codigoLinea <<std::left<<std::setw(50)<< nombreLinea << std::left<<std::setw(20)<< statusLinea << "\n";
                }
                 baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "lineas.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalLineas.dat","lineas.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU LINEAS--";
        cout<<"\n\t";system("pause");
        return menuLineas();
    }
}

void corpoComercial::eliminarLineas(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR LINEAS--" << endl;
	cout << "\n\t Quires salir al --MENU LINEAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuLineas();
    }
    else {
        baseDatos.open("lineas.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el codigo del lineas que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalLineas.dat", ios::app | ios::out | ios::binary);
          baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
            while(!baseDatos.eof())
            {
                if(busquedaDatos!=codigoLinea)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< codigoLinea <<std::left<<std::setw(50)<< nombreLinea << std::left<<std::setw(20)<< statusLinea << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
             baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Producto no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "lineas.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalLineas.dat","lineas.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU MARCAS--";
        cout<<"\n\t";system("pause");
        return menuLineas();
    }
}

void corpoComercial::mostrarLineas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR LINEAS--";
    cout << "\n\t Quires salir al --MENU LINEAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuLineas();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a una linea en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("lineas.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR LINEAS--"<<endl;
                cout << "\n\t\tIngrese el codigo de marca a buscar: "; cin >> busquedaDatos;
                 baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
                while(!baseDatos.eof()){
                    if(busquedaDatos==codigoLinea){
                        cout << "\n\t\tCodigo de linea: "; cin >> codigoLinea;
                        cout << "\t\tNombre de linea: "; cin >> nombreLinea;
                        cout << "\t\tStatus de linea: "; cin>>statusLinea;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU MARCAS--";
                        cout<<"\n\t";system("pause");
                        return menuMarcas();
                    }
                   baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR LINEA--";
                    cout<<"\n\t";system("pause");
                    return mostrarLineas();
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
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR  LINEAS"<<endl;
            baseDatos.open("lineas.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU LINEAS--";
                cout<<"\n\t";system("pause");
                return menuLineas();
            }
            else
            {
                baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
                while(!baseDatos.eof())
                {
                    total++;
                        cout << "\n\t\tCodigo de lineas: "; cin >> codigoLinea;
                        cout << "\t\tNombre de lineas: "; cin >> nombreLinea;
                        cout << "\t\tStatus de lineas: "; cin>>statusLinea;
                    baseDatos>>codigoLinea>>nombreLinea>>statusLinea;
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
                cout <<"\n\n\t\tRegresando al --MENU MARCAS--";
                cout<<"\n\t";system("pause");
                return menuLineas();
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

int main(){
    system ("cls");
    int contador=0;
    bool ingresa=false;
    string usuario, config0, config1, config2, contra, numU;
    fstream config;
    int datos=0;
    config.open("seguridad.dat",ios::in|ios::binary);
    if(!config){
        cout<<"\n\n\t\tError, no se encuentra un archivo escencial del programa...\a\n\n";
        exit(1);
    }
    else{
        cout << "\n\t\t\tBIENVENIDOS AL PROTOTIPO P1ER2022 DE WILLIAM OTTONIEL MAYEN VASQUEZ 9959-21-1581" << endl;
        cout << "\n\t\tIngrese el numero de usuario asignado: "; cin >> numU;
        config>>config0>>config1>>config2;
        while(!config.eof()){
            if(numU==config0){
                do{
                    cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
                    cout << "\n\t\tIngrese su contrasena: ";
                    char caracter;
                    caracter = getch();
                    contra="";
                    while (caracter != 13) //enter
                    {
                        if (caracter != 8) //backspace
                        {
                            contra.push_back(caracter);
                            cout<<"*";
                        } else
                        {
                            if (contra.length() > 0)
                            {
                                cout<<"\b \b"; //borrado en pantalla
                                contra = contra.substr(0,contra.length()-1); //todos menos el ultimo
                            }
                        }
                        caracter = getch();
                    }
                    //usuraio
                    if (usuario==config1 && contra==config2){
                        system("cls");
                        ingresa=true;
                    } else {
                        cout<<"\n\t\tEl usuario y/o contrasena son incorrectos\a"<<endl;
                        cin.get();
                        contador++;
                    }
                } while (ingresa==false && contador<3);
                if (ingresa==false){
                    cout<<"\n\t\tNo puede ingresar al sistema, agoto intentos"<<endl;
                    cin.get();
                } else {
                    fstream bienvenida;
                    string line, desicion;
                    bienvenida.open("WELCOME.txt");
                    if(bienvenida.is_open()){
                        cout << "\n";
                        while( getline(bienvenida, line)){
                            cout << "\t"<<line << endl;
                        }
                        cout<<"\n\t\t";system("pause");
                        bienvenida.close();
                    }
                    bienvenida.close();
                    corpoComercial prueba;
                    prueba.menuGeneral();
                    cin.get();
                }
                return ingresa;
                datos++;
                config.close();
            }
            config>>config0>>config1>>config2;
            config.close();
        }
        config.close();
    }
    config.close();
};
