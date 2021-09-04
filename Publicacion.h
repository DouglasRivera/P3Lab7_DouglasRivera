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
		string texto;
		string fechapublicacion;
		
	public:
		Publicacion(int, string, string, string);
		~Publicacion();
		void verPublicacion();
		int getIdpublicacion();
		void setIdpublicacion(int);
		string getTitulo();
		void setTitulo(string);
		string getTexto();
		void setTexto(string);
		string getFechapublicacion();
		void setFechapublicacion(string);
		void guardarPublicaciones(ofstream*);
	
};

#endif