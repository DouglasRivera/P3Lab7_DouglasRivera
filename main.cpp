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
Publicacion* agregarPublicacion();
fstream file;
fstream file2;

int main() {
	fstream Readfile("usuarios.csv", ios::in);
	if (!Readfile) {
		fstream CreateFile("usuarios.csv", ios::out);
	}
	file.open("usuarios.csv", ios::app);

	fstream Readfile2("publicaciones.csv", ios::in);
	if (!Readfile2) {
		fstream CreateFile2("publicaciones.csv", ios::out);
	}
	file2.open("publicaciones.csv", ios::app);
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
				Usuario *users;
				users = usuarios.at(aux);
				while ((z = menu()) != 4 ) {
					if (z == 1) {
						vector<Publicacion*> temporal;
						temporal = users->getPublicaciones();
						if (!temporal.empty()) {
							for (int i = 0; i < temporal.size(); i++) {
								Publicacion* p;
								p = temporal.at(i);
								cout << i << ") ";
								p->verPublicacion();
							}
						} else {
							cout << endl << "No hay publicaciones Actualmente";
						}
					} else if (z == 2) {
						int opcionAdmin = 0;
						while(opcionAdmin != 4) {
							cout << endl << "MENU\n1.Agregar Publicacion\n2.Modificar Publicacion\n3.Borrar Publicacion\n4.Salir" << endl;
							cin >> opcionAdmin;
							if (opcionAdmin == 1) {
								users->agregarPublicacion(agregarPublicacion());
							} else if (opcionAdmin == 2) {
								vector<Publicacion*> temporal;
								temporal = users->getPublicaciones();
								if (!temporal.empty()) {
									cout << endl << "Estas son las Publicaciones que ha publicado hasta el momento: " << endl;
									for (int i = 0; i < temporal.size(); i++) {
										Publicacion* p;
										p = temporal.at(i);
										cout << i << ") ";
										p->verPublicacion();
										delete p;
									}
									int num;
									cout << endl << "Ingrese el numero de la publicacion que desea modificar: ";
									cin >> num;
									if (num >= 0 && num < temporal.size()) {
										string texto,  fecha,  titulo;
										cout << "Ingrese el nuevo titulo de la publicacion: ";
										cin >> titulo;
										cout << "Ingrese la nueva fecha de la publicacion: ";
										cin >> fecha;
										cout << "Ingrese el nuevo texto de la publicacion: ";
										cin.ignore();
										getline(cin, texto);
										Publicacion* p;
										p = temporal.at(num);
										temporal.erase(temporal.begin()+num);
										p->setFechapublicacion(fecha);
										p->setTitulo(titulo);
										p->setTexto(texto);
										temporal.push_back(p);
										users->setPublicaciones(temporal);
										cout << endl << "Se Modifico la publicacion exitosamente" << endl;
									} else {
										cout << endl << "Ingreso una posicion no valida" << endl;
									}

								} else {
									cout << endl << "No hay publicaciones Actualmente";
								}
							} else if (opcionAdmin == 3) {
								vector<Publicacion*> temporal;
								temporal = users->getPublicaciones();
								if (!temporal.empty()) {
									cout << endl << "Estas son las Publicaciones que ha publicado hasta el momento: " << endl;
									for (int i = 0; i < temporal.size(); i++) {
										Publicacion* p;
										p = temporal.at(i);
										cout << i << ") ";
										p->verPublicacion();
										delete p;
									}
									int num;
									cout << endl << "Ingrese el numero de la publicacion que desea borrar: ";
									cin >> num;
									if (num >= 0 && num < temporal.size()) {
										temporal.erase(temporal.begin()+num);
										users->setPublicaciones(temporal);
										cout << endl << "Se elimino la publicacion exitosamente" << endl;
									} else {
										cout << endl << "Ingreso una posicion no valida" << endl;
									}
								}
							}
						}
					} else if (z == 3) {
						string newpp;
						cout << "Ingrese su nueva password: ";
						cin >> newpp;
						users->setContra(newpp);
					}
					usuarios.erase(usuarios.begin()+aux);
					usuarios.push_back(users);
				}
				delete users;

			} else {
				cout << endl<< "USUARIO NO EXISTENTE, VERIFIQUE CON EL ADMIN POR SU USUARIO" << endl;
			}
			aux2 = false;
		}

	}
	if (!usuarios.empty()) {
		for (int i = 0; i < usuarios.size(); i++) {
			Usuario* user;
			user = usuarios.at(i);
			string name = user->getUser();
			string passw = user->getContra();
			bool adm = user->getEsAdmin();
			file << i + "," << name + "," << passw + "," << adm << endl;
			delete user;
		}
		for (int i = 0; i < usuarios.size(); i++) {
			Usuario* user;
			user = usuarios.at(i);
			vector<Publicacion*>temporal;
			temporal = user->getPublicaciones();
			if (!temporal.empty()) {
				for (int j = 0; j < temporal.size(); j++) {
					Publicacion* p;
					p = temporal.at(j);
					string texto = p->getTexto();
					string titulo = p->getTitulo();
					string fecha = p->getFechapublicacion();
					int id = p->getIdpublicacion();
					file2 << id + "," << titulo +"," << texto + "," << fecha << endl;
					delete p;
				}
			}
		}

	}
	file2.close();
	file.close();
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

Publicacion* agregarPublicacion() {
	int id;
	string titulo, texto, fecha;
	cout << "Ingrese el titulo de la publicacion: ";
	cin >> titulo;
	cout << "Ingrese la fecha de la publicacion: ";
	cin >> fecha;
	cout << "Ingrese el texto de la publicacion: ";
	cin.ignore();
	getline(cin, texto);
	return new Publicacion(id, titulo, texto, fecha);
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