#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Publicacion.h"

using namespace std;


class Usuario
{
	public:
		Usuario(int, string,string,string, bool);
		~Usuario();	
		int getId();
		void setId(int);
		string getNombre();
		void setNombre(string);
		string getUser();
		void setUser(string);
		string getContra();
		void setContra(string);
		bool getEsAdmin();
		void setEsAdmin(bool);
		vector<Publicacion*> getPublicaciones();
		void setPublicaciones(Publicacion*);	
		void guardarUsuarios(ofstream*);

	private:
		vector <Publicacion*> misPublicaciones;
		int id;
		string nombre;
		string usuario;
		string contra;
		bool esAdmin;
		vector<Punlicacion*> misPublicaciones;

};

#endif