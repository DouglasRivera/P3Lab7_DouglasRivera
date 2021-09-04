#include "Publicacion.h"

Publicacion::Publicacion(int idpublicacion, string titulo, string texto, string fechapublicacion){
	idpublicacion = idpublicacion;
	titulo = titulo;
	texto = texto;
	fechapublicacion = fechapublicacion;
}

Publicacion::~Publicacion(){
}

void Publicacion::verPublicacion() {
	cout << endl << "Fecha: "<< this->fechapublicacion<< endl << "Titulo: "<< this->titulo << endl << "  " << texto << endl;
}

int Publicacion::getIdpublicacion(){
	return idpublicacion;
}

void Publicacion::setIdpublicacion(int idpublicacion){
	idpublicacion = idpublicacion;
}

string Publicacion::getTitulo(){
	return titulo;
}

void Publicacion::setTitulo(string titulo){
	titulo = titulo;
}

string Publicacion::getTexto(){
	return texto;
}

void Publicacion::setTexto(string texto){
	texto = texto;
}

string Publicacion::getFechapublicacion(){
	return titulo;
}

void Publicacion::setFechapublicacion(string fechapublicacion){
	fechapublicacion = fechapublicacion;
}

void Publicacion::guardarPublicaciones(ofstream* archivoPublicaciones){
	if (archivoPublicaciones-> is_open()){
		*archivoPublicaciones << this->idpublicacion << "," << this->titulo << "," << this->texto << "," << this->fechapublicacion;
	}
}

