#include <iostream>
#include <string>
#include "Publicacion.h"
#include "Usuario.h"

#include <vector>
using namespace std;

int menu();
int menu2();

int main() {
	int opcion;
	while((opcion = menu()) != 3) {
		switch (opcion) {
			case 1: {
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
				vector<Publicacion*> publicaciones;
				cout << endl;
				return new Usuario(id, user, pass, esadmin, publicaciones);
			}
			break;
		}
	case 2: {

			break;
		}
	case 3: {

			break;
		}
	case 4: {

			break;
		}
	case 5: {

			break;
		}
	}//fin del switch
}//fin while menu
return 0;
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