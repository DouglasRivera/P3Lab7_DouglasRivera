#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Usuario.h"

using namespace std;

class Publicacion
{
    private:
		int idpublicacion; 
		string titulo;
		Usuario* autor;
		string texto;
		string fechapublicacion;
		
	public:
		Publicacion(int, string, Usuario*, string, string);
		~Publicacion();
		int getIdpublicacion();
		void setIdpublicacion(int);
		string getTitulo();
		void setTitulo(string);
		Usuario* getAutor();
		void setAutor(Usuario*);
		string getTexto();
		void setTexto(string);
		string getFechapublicacion();
		void setFechapublicacion(string);
		void guardarPublicaciones(ofstream*);
	
};

#endif