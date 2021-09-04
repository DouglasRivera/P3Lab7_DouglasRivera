#ifndef BLOG_H
#define BLOG_H
#include <string>
#include <vector>
#include "Usuario.h"
#include "Publicacion.h"
using namespace std;

class Blog {
	private:
	string youBlOg;
	vector <Usuario*> usuarios;

public:
	Blog(string, vector<Usuario*>);
	~Blog();
	void agregaruser();
	void verPublicaciones();
	bool compare(Publicacion*, Publicacion*);
	void cargarArchivos(string, string);
	void escribirUsuarios(string);
	void escribirPublicaciones(string);
};

#endif