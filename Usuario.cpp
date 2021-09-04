#include "Usuario.h"

Usuario::Usuario(int id,string _usuario,string _contra, bool esAdmin ){
	id = id;
	usuario = _usuario;
	contra = _contra;
	esAdmin = esAdmin;
}

Usuario::~Usuario(){
}

void Usuario::agregarPublicacion(Publicacion* p){
	this->misPublicaciones.push_back(p);
}

int Usuario::getId(){
	return id;
}

void Usuario::setId(int id){
	id= id;
}

string Usuario::getUser(){
	return usuario;
}

void Usuario::setUser(string _usuario){
	usuario = _usuario;
}

string Usuario::getContra(){
	return contra;
}

void Usuario::setContra(string _contra){
	contra = _contra;
}

bool Usuario::getEsAdmin(){
	return esAdmin;
}

void Usuario::setEsAdmin(bool esAdmin){
	esAdmin= esAdmin;
}

vector<Publicacion*> Usuario::getPublicaciones(){
	return misPublicaciones;
}

void Usuario::setPublicaciones(vector<Publicacion*> p){
	this->misPublicaciones = p;
}

void Usuario::guardarUsuarios(ofstream* archivoUsuarios){
	if (archivoUsuarios-> is_open()){
		*archivoUsuarios << this->id << "," << this->usuario << "," << this->contra << "," << this->esAdmin;
	}
}
