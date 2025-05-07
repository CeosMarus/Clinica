
#include "medicos.h"
//agregamos los constructore uno inicializado con valores 0 y el otro le pasaremos los parametros de id, nombre, string
medicos::medicos() : id_medicos(0), nombre_completo(""), especialidad(""),dias_atencion(""){}
//le pasamos los parametros al constructor de nombre, id, estado
medicos::medicos(string nombre_Completo, string Especialidad,string Dias_atencion) : nombre_completo(nombre_Completo), especialidad(Especialidad),dias_atencion(Dias_atencion) {}

//utilizamos getter para obtener la informacion de los parametros y retornarla
int medicos::getId() const { return id_medicos; }
string medicos::getNombre() const { return nombre_completo; }
string medicos::getEspecialidad() const { return especialidad; }
string medicos::getDias_atencion() const { return dias_atencion; }


//utilizamos los etter para enviar los parametros al constructor
void medicos::setId(int _id) { id_medicos = _id; }
void medicos::setNombre(string _nombre) { nombre_completo = _nombre; }
void medicos::setEspecialidad(string _especialidad) { especialidad = _especialidad; }
void medicos::setDias_atencion(string _dias_atencion) { dias_atencion = _dias_atencion; }
