#include "Publicacion.h"

Publicacion::Publicacion(int idpublicacion, string titulo, Usuario* autor, string texto, string fechapublicacion){
	idpublicacion=idpublicacion;
	titulo = titulo;
	autor = autor;
	texto = texto;
	fechapublicacion = fechapublicacion;
}

Publicacion::~Publicacion(){
}

int Publicacion::getIdpublicacion(){
	return idpublicacion;
}

void Publicacion::setIdPublicacion(int idpublicacion){
	idpublicacion = idpublicacion;
}

string Publicacion::getTitulo(){
	return titulo;
}

void Publicacion::setTitulo(string titulo){
	titulo = titulo;
}

Usuario* Publicacion::getAutor(){
	return autor;
}

void Publicacion::setAutor(Usuario* autor){
	autor = autor;
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
		*archivoUsuarios << this->idpublicacion << "," << this->titulo << "," << this->autor << "," << this->texto << "," this->fechapublicacion;
	}
}

