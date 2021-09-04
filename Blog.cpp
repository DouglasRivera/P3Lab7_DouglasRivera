#include "Blog.h"

Blog::Blog(string youBlOg, vector<Usuario*> usuarios) {
	this->youBlOg = youBlOg;
	this->usuarios = usuarios;
}

Blog::~Blog(){
}

bool Blog::compare(Publicacion* a, Publicacion* b) {
	return true;
}

void Blog::verPublicaciones() {
	int idPublicacion;
	string titulo;
	string autor;
	string texto;
	string fecha;
	ifstream archPublicaciones("Publicaciones.csv");
	while (archPublicaciones >> idPublicacion >> titulo >> autor >> texto >> fecha) {
		cout << idPublicacion << " " << titulo << " " << autor << " " << texto << " " << fecha << endl;
	}
}

void Blog::agregaruser() {
	int id;
	string nombre;
	string contra;
	char esAdmin;
	bool admin;
	cout << "Escriba el id del usuario: "; cin >> id;
	cout << "Escriba el nombre del usuario: "; cin >> nombre;
	cout << "Escriba su password: "; cin >> contra;
	cout << "Es User ser a un administrador? (s/n)"; cin >> esAdmin;
	if (esAdmin == 's') {
		admin == true;
	}
	else {
		admin == false;
	}
	Usuario* u = new Usuario(id, nombre, contra, admin);
	usuarios.push_back(u);
}

void Blog::escribirUsuarios(string nombre) {
	ofstream* archivo = new ofstream(nombre);
	for (int i = 0; i < usuarios.size(); i++) {
		usuarios[i]->guardarUsuarios(archivo);
	}
}

void Blog::escribirPublicaciones(string nombre) {
	ofstream* archivo = new ofstream(nombre);
	
}