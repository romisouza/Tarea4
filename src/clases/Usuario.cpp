#include "../../include/clases/Usuario.h"

Usuario::Usuario(std::string nom, std::string mail, std::string pass){
	nombre = nom;
	email = mail;
	password = pass;
}
std::string Usuario::getNombre(){
	return nombre;
}

std::string Usuario::getEmail(){
	return email;
}

std::string Usuario::getPassword(){
	return password;
}

void Usuario::setNombre(std::string nom){
	nombre=nom;
}

void Usuario::setEmail(std::string mail){
	email=mail;
}

void Usuario::setPassword(std::string pass){
	password=pass;
}

Usuario::~Usuario(){}
