#include <iostream>
#include <string>
#include "Publicacion.h"
#include "Usuario.h"
#include "Blog.h"
#include <vector>
using namespace std;

int menu();
int menu2();
int LogIn();
Usuario* agregarUsuario();

int main() {
	int x = 0;
	int aux = 0;
	bool aux2 = false;
	vector<Usuario*> usuarios;
	while ((x = LogIn()) != 2) {
		if (x == 1) {
			string user;
			string pass;
			cout << "Ingrese usuario: ";
			cin >> user;
			cout << "Ingrese Contraseña: ";
			cin >> pass;
			if (!usuarios.empty()) {
				//bool aux2 = false;
				for (int i = 0; i < usuarios.size(); i++) {
					Usuario *users;
					users = usuarios.at(i);
					string p = users->getContra();
					string u = users->getUser();
					if (user == u && pass == p ) {
						aux2 = true;
						aux = i;
					}
					delete users;
				}
			}
			if ((user == "Admin" || user == "admin") && pass == "1111" ) {
				int y;
				while ((y = menu()) != 5 ) {
					if (y == 1) {
						usuarios.push_back(agregarUsuario());
						cout << endl << usuarios.size() << endl;
					} else if(y == 2) {
						int us = 0;
						cout << "Estos son los usuarios que estan ingresados en el sistema: " << endl;
						for (int i = 0; i < usuarios.size(); i++) {
							Usuario *user;
							user = usuarios.at(i);
							cout << i << " "<< user->getUser() << endl;
							delete user;
						}
						cout << "Ingrese el numero del usuario que desea eliminar: ";
						cin >> us;
						if (us >= 0 && us < usuarios.size()) {
							usuarios.erase(usuarios.begin()+us);
							cout << endl << "Se elimino el usuario exitosamente" << endl;
						} else {
							cout << endl << "Ingreso una posicion no valida" << endl;
						}
					} else if (y == 3) {
						int us = 0;
						cout << "Estos son los usuarios que estan ingresados en el sistema: " << endl;
						for (int i = 0; i < usuarios.size(); i++) {
							Usuario *user;
							user = usuarios.at(i);
							cout << i << " "<< user->getUser() << endl << "  Password--> " << user->getContra() << endl;
							delete user;
						}
						cout << "Ingrese el numero del usuario que desea modificar: ";
						cin >> us;
						if (us >= 0 && us < usuarios.size()) {
							string newpass;
							cout << "Ingresa la nueva password: ";
							cin >> newpass;
							Usuario *user;
							user = usuarios.at(us);
							usuarios.erase(usuarios.begin()+us);
							user->setContra(newpass);
							usuarios.push_back(user);
							cout << endl << "Se Modifico el usuario exitosamente" << endl;
						} else {
							cout << endl << "Ingreso una posicion no valida" << endl;
						}
					} else if (y == 4) {
						cout << "PUBLICACIONES";
					}
				}
			} else if(aux2) {
				int z;
				while ((z = menu2()) != 4 ) {
						
				}
			} else {
				cout << endl<< "USUARIO NO EXISTENTE, VERIFIQUE CON EL ADMIN POR SU USUARIO" << endl;
			}
			aux2 = false;
		}

	}

	return 0;
}

Usuario* agregarUsuario() {
	int id;
	string user, pass, aux;
	bool esadmin;
	cout << "Ingrese el Id del usuario: ";
	cin >> id;
	cout << "Ingrese el user: ";
	cin >> user;
	cout << "Ingrese su password: ";
	cin >> pass;
	cout << "Ingrese si puede ser admin[s,n]:";
	cin >> aux;
	if(aux[0] = 'n') {
		esadmin = false;
	}
	vector<Publicacion*> misPublicaciones;
	cout << endl;
	return new Usuario(id, user, pass, esadmin);
}

int LogIn() {
	int opcion = 0;
	cout <<endl << "--------Menu---------"<<endl;
	cout << "1. Log in" << endl;
	cout << "2. Log out" << endl;
	cout << "\nIngrese la opcion que desea desarrollar: " << endl;
	cin >> opcion;
	return opcion;
}

int menu() {
	int opcion;
	cout << "----MENU ADMIN----" << endl;
	cout << "1. Agregar Usuario" << endl;
	cout << "2. Eliminar Usuario" << endl;
	cout << "3. Actualizar Contraseñas" << endl;
	cout << "4. Ver Publicaciones" << endl;
	cout << "5. Salir " << endl;
	cout << "Ingrese la opcion: "<<endl;
	cin >> opcion;
	while(opcion < 1 || opcion > 5) {
		cout << "Seleccione una opcion dentro del rango disponible" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}

int menu2() {
	int opcion;
	cout << "----MENU USUARIO NORMAL----" << endl;
	cout << "1. Ver mis publicaciones" << endl;
	cout << "2. Mis Publicaciones" << endl;
	cout << "3. Actualizar Contraseña" << endl;
	cout << "4. Cerrar Sesion" << endl;
	cout << "Ingrese la opcion: "<<endl;
	cin >> opcion;
	while(opcion < 1 || opcion > 5) {
		cout << "Seleccione una opcion dentro del rango disponible" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}