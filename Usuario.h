#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
class Publicacion;

using namespace std;


class Usuario
{
    private:
		vector <Publicacion*> misPublicaciones;
		int id;
		string usuario;
		string contra;
		bool esAdmin;
		
	public:
		Usuario(int,string,string, bool);
		~Usuario();	
		int getId();
		void setId(int);
		string getUser();
		void setUser(string);
		string getContra();
		void setContra(string);
		bool getEsAdmin();
		void setEsAdmin(bool);
		vector<Publicacion*> getPublicaciones();
		void setPublicaciones(Publicacion*);	
		void guardarUsuarios(ofstream*);

	

};

#endif