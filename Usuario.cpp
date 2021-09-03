#include "Usuario.h"

Usuario::Usuario(int id, string _nombre,string _usuario,string _contra, bool esAdmin ){
	id = _id;
	nombre=_nombre;
	usuario = _usuario;
	contra = _contra;
	esAdmin = _esadmin;
}

Usuario::~Usuario(){
}

int Usuario::getId(){
	return id;
}

void Usuario::setId(int _id){
	id= _id;
}

string Usuario::getNombre(){
	return nombre;
}

void Usuario::setNombre(string _nombre){
	nombre= _nombre;
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

void Usuario::setEsAdmin(bool _esadmin){
	nombre= _esadmin;
}

vector<Publicacion*> Usuario::getPublicaciones(){
	return misPublicaciones;
}

void Usuario::setPublicaciones(Publicacion* publicaciones){
	misPublicaciones.push_back(publicaciones);
}

void Usuario::guardarUsuarios(ofstream* archivoUsuarios){
	if (archivoUsuarios-> is_open()){
		*archivoUsuarios << this->id << "," << this->usuario << "," << this->contra << "," << this->esAdmin;
	}
}
