
#include "paciente.h"
//agregamos los constructore uno inicializado con valores 0 y el otro le pasaremos los parametros de id, nombre, string
paciente::paciente() : id_pacientes(0), nombre_completo(""), edad(1),DPI(1),numero_contacto(1) {}
//le pasamos los parametros al constructor de nombre, id, estado
paciente::paciente(string nombre_Completo, int Edad,int dpi,int Numero_Contacto) : nombre_completo(nombre_Completo), edad(Edad),DPI(dpi),numero_contacto(Numero_Contacto) {}

//utilizamos getter para obtener la informacion de los parametros y retornarla
int paciente::getId() const { return id_pacientes; }
string paciente::getNombre() const { return nombre_completo; }
int paciente::getEdad() const { return edad; }
int paciente::getDPI() const { return DPI; }
int paciente::getNumeroContacto() const { return numero_contacto; }

//utilizamos los etter para enviar los parametros al constructor
void paciente::setId(int _id) { id_pacientes = _id; }
void paciente::setNombre(string _nombre) { nombre_completo = _nombre; }
void paciente::setEdad(int _edad) { edad = _edad; }
void paciente::setDPI(int _DPI) { DPI = _DPI; }
void paciente::setNumeroContacto(int _NumeroContacto) { numero_contacto = _NumeroContacto; }
