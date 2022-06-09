#include "../../include/clases/Usuario.h"

Usuario::Usuario(string nom, string mail, string pass){
	nombre = nom;
	email = mail;
	password = pass;
}
string Usuario::getNombre(){
	return nombre;
}

string Usuario::getEmail(){
	return email;
}

string Usuario::getPassword(){
	return password;
}

void Usuario::setNombre(string nom){
	nombre=nom;
}

void Usuario::setEmail(string mail){
	email=mail;
}

void Usuario::setPassword(string pass){
	password=pass;
}

Usuario::~Usuario(){}
