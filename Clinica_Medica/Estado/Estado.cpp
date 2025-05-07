
#include "Estado.h"
//agregamos los constructore uno inicializado con valores 0 y el otro le pasaremos los parametros de id, nombre, string
Estado::Estado() : id_estado(0), estado(0){}
//le pasamos los parametros al constructor de nombre, id, estado
Estado::Estado(int Estado) : estado(Estado){}

//utilizamos getter para obtener la informacion de los parametros y retornarla
int Estado::getId() const { return id_estado; }
int Estado::getEstado() const { return estado; }



//utilizamos los etter para enviar los parametros al constructor
void Estado::setId(int _id) { id_estado = _id; }
void Estado::setEstado(int _estado ) { estado = _estado; }
