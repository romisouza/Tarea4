#ifndef USUARIO
#define USUARIO
#include <iostream>
using namespace std;

class Usuario {
	protected:
		string nombre;
		string email;
		string password;
	public:
		Usuario(string nom, string mail, string pass);
		virtual ~Usuario()=0;
		string getNombre();
		string getEmail();
		string getPassword();
		void setNombre(string nom);
		void setEmail(string mail);
		void setPassword(string pass);
};

#endif