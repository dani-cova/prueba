#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void menu();
void crear_contacto();
void agregar_contacto();
bool verifica(string matricula);
void visualizar_contacto();
void modificar_matricula();
void modificar_nombre();
void modificar_apellido();
void modificar_telefono();
void modificar_correo();
void modificar_carrera();
void modificar_division();
void eliminar_contacto();
void buscar_contacto();

struct contacto{
	string matricula,nombre,apellidoM,apellidoP,
	telefono,correo,carrera,division;
}datos;

int main(){
	menu();

	system("pause");
	return 0;
}

void menu(){
	int opcion;

	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Crear Agenda Telefonica"<<endl;
		cout<<"2. Visualizar contactos existentes"<<endl;
		cout<<"3. Modificar matricula"<<endl;
		cout<<"4. Modificar nombre"<<endl;
		cout<<"5. Modicicar apellido"<<endl;
		cout<<"6. Modificar telefono"<<endl;
		cout<<"7. Modificar correo"<<endl;
		cout<<"8. Modicicar carrera"<<endl;
		cout<<"9. Modificar division"<<endl;
		cout<<"10. Eliminar contacto"<<endl;
		cout<<"11. Buscar contacto"<<endl;
		cout<<"12. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;

		switch(opcion){
			case 1: crear_contacto();
					cout<<"\n";
					system("pause");
					break;
			case 2: visualizar_contacto();
					cout<<"\n";
					system("pause");
					break;
			case 3: modificar_matricula();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 4: modificar_nombre();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 5: modificar_apellido();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 6: modificar_telefono();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 7: modificar_correo();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 8: modificar_carrera();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 9: modificar_division();
                    cout <<"\n";
                    system("PAUSE");
                    break;
             case 10: eliminar_contacto();
                    cout <<"\n";
                    system("PAUSE");
                    break;
            case 11: buscar_contacto();
                    cout <<"\n";
                    system("PAUSE");
                    break;
		}
		system("cls");
	}while(opcion!=12);
}

bool verifica(string matricul){
	
	ifstream archivo("AgendaTelefonica.txt", ios::in);
	
	string matricula;
	string nombre;
	string apellidoM;
	string apellidoP;
	string telefono;
	string correo;
	string carrera;
	string division;
	
	archivo>>matricula;
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellidoM;
		archivo>>apellidoP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(matricula== matricul){
			
			archivo.close();
			return false;
			
		}
		archivo>>matricula;	
	}
	archivo.close();
	return true;
}

//Funcion para crear un contacto
void crear_contacto(){
	ofstream archivo;
	char rpt;
	string matricula;
	string nombre;
	string apellidoM;
	string apellidoP;
	string telefono;
	string correo;
	string carrera;
	string division;

	archivo.open("AgendaTelefonica.txt",ios::out| ios::app); //Abrimos el archivo en modo escritura

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
		fflush(stdin);
		cout<<"\nDigite su Matricula: ";
		cin>>matricula;
		cout<<"\nDigite su Nombre: ";
		cin>>nombre;
		cout<<"Digite su Apellido Materno: ";
		cin>>apellidoM;
		cout<<"Digite su Apellido Paterno: ";
		cin>>apellidoP;
		cout<<"Digite su Telefono: ";
		cin>>telefono;
		cout<<"\nDigite su Correo: ";
		cin>>correo;
		cout<<"Digite su Carrera: ";
		cin>>carrera;
		cout<<"Digite su Division: ";
		cin>>division;
		
		if(verifica(matricula))
		
		archivo<<" "<<matricula<<" "<<nombre<<" "<<apellidoM<<" "<<apellidoP<<" "<<telefono<<" "<<correo<<" "<<carrera<<" "<<division<<endl<<endl;


		archivo.close(); //Cerramos el archivo
}

void visualizar_contacto(){
	
	system("cls");
	
	ifstream archivo;
	string matricula;
	string nombr;
	string apellid;
	string apellidP;
	string telefon;
	string correo;
	string carrera;
	string division;

	archivo.open("AgendaTelefonica.txt",ios::in); //Abrimos el archivo en modo lectura

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo>>matricula;
	while(!archivo.eof()){ //mientras no sea el final de archivo
		archivo>>nombr;
		archivo>>apellid;
		archivo>>apellidP;
		archivo>>telefon;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		cout<<"Matricula:---"<<matricula<<endl;
		cout<<"Nombre:--- "<<nombr<<endl;
		cout<<"Apellido Materno:--- "<<apellid<<endl;
		cout<<"Apellido Paterno:--- "<<apellidP<<endl;
		cout<<"Telefono:--- "<<telefon<<endl;
		cout<<"Correo:---"<<correo<<endl;
		cout<<"Carrera:---"<<carrera<<endl;
		cout<<"Division:---"<<division<<endl<<endl;
	
		archivo>>matricula;
	}
	archivo.close(); //Cerramos el archivo
}
void modificar_matricula(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce la nueva matricula" << endl;
			cin >> nuevoN;
			archivo2<<" "<<nuevoN<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
			
		}else{
		
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>nombre;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void modificar_nombre(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce el nuevo nombre" << endl;
			cin >> nuevoN;
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nuevoN<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
			
		}else{
		
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>nombre;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void modificar_apellido(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce el nuevo apellido" << endl;
			cin >> nuevoN;
			
			archivo2<<" "<<matricula<<endl;
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<nuevoN <<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
		}else{
		
			archivo2<<" "<<matricula<<endl;
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>matricula;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void modificar_telefono(){
	
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellidM;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellidM;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce el nuevo telefono" << endl;
			cin >> nuevoN;
			
			archivo2<<" "<<matricula<<endl;
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellidM <<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<nuevoN<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
		}else{
		
			archivo2<<" "<<matricula<<endl;
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellidM<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>matricula;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
	
}
void modificar_correo(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce el nuevo correo" << endl;
			cin >> nuevoN;
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<nuevoN<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
			
		}else{
		
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>nombre;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void modificar_carrera(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce la nueva carrera" << endl;
			cin >> nuevoN;
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<nuevoN<<endl;
			archivo2<<" "<<division<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
			
		}else{
		
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>nombre;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void modificar_division(){
	
	ifstream archivo;
    ofstream archivo2;
    string editar;
    string nuevoN;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
    
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a editar" << endl;
	cin>>editar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(editar==matricula){
			
			cout << "Introduce la nueva division" << endl;
			cin >> nuevoN;
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<nuevoN<<endl<<endl;
			cout<<"El regitro ha sido editado" << endl;
			
		}else{
		
			archivo2<<" "<<matricula<<endl;		
			archivo2<<" "<<nombre<<endl;
			archivo2<<" "<<apellido<<endl;
			archivo2<<" "<<apellidP<<endl;
			archivo2<<" "<<telefono<<endl;
			archivo2<<" "<<correo<<endl;
			archivo2<<" "<<carrera<<endl;
			archivo2<<" "<<division<<endl<<endl;
		
		}
		archivo>>nombre;
	}
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void eliminar_contacto(){
	
	ifstream archivo;
    ofstream archivo2;
    string eliminar;
	string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    

	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    archivo2.open("AgendaTelefonicaTemp.txt",ios::out);	
  
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce el nombre del contacto a eliminar" << endl;
	cin>>eliminar;
	
	archivo>>matricula;
	
while(!archivo.eof()){
  		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
  	
    if(eliminar == nombre){  //se encontro
    
      cout<<"El regitro ha sido eliminado" << endl;
     
      
    }else{
    	archivo2<<" "<<matricula<<endl;
		archivo2<<" "<<nombre<<endl;
		archivo2<<" "<<apellido<<endl;
		archivo2<<" "<<apellidP<<endl;
		archivo2<<" "<<telefono<<endl;
		archivo2<<" "<<correo<<endl;
		archivo2<<" "<<carrera<<endl;
		archivo2<<" "<<division<<endl<<endl;
    
    	
	}
    archivo >>matricula;
  }
		
	
	archivo.close();
	archivo2.close();
  	remove("AgendaTelefonica.txt");      
  	rename("AgendaTelefonicaTemp.txt", "AgendaTelefonica.txt");
	
}
void buscar_contacto(){
	
	ifstream archivo;
    string buscar;
    string matricula;
	string nombre;
	string apellido;
	string apellidP;
	string telefono;
	string correo;
	string carrera;
	string division;
    
	archivo.open("AgendaTelefonica.txt",ios::in); //leer de este archivo
    
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "Introduce la matricula del contacto a buscar" << endl;
	cin>>buscar;
	
	archivo>>matricula;
	
	while(!archivo.eof()){
		archivo>>nombre;
		archivo>>apellido;
		archivo>>apellidP;
		archivo>>telefono;
		archivo>>correo;
		archivo>>carrera;
		archivo>>division;
		
		if(buscar==matricula){
			
		cout<<"Matricula:---"<<matricula<<endl;
		cout<<"Nombre:--- "<<nombre<<endl;
		cout<<"Apellido Materno:--- "<<apellido<<endl;
		cout<<"Apellido Paterno:--- "<<apellidP<<endl;
		cout<<"Telefono:--- "<<telefono<<endl;
		cout<<"Correo:---"<<correo<<endl;
		cout<<"Carrera:---"<<carrera<<endl;
		cout<<"Division:---"<<division<<endl<<endl;
			
		}
		archivo>>matricula;
	}
	
	archivo.close();
	
}
