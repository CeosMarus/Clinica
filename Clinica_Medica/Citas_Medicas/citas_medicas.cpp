
#include "citas_medicas.h"
//agregamos los constructore uno inicializado con valores 0 y el otro le pasaremos los parametros de id, nombre, string
citas_medicas::citas_medicas() : id_citas(0), id_pacientes(0), id_medico(0),fecha_cita(""),id_estado(0){}
//le pasamos los parametros al constructor de nombre, id, estado
citas_medicas::citas_medicas(int Id_Pacientes, int Id_Medico,string Fecha_Cita,int Id_Estado) : id_pacientes(Id_Pacientes), id_medico(Id_Medico),fecha_cita(Fecha_Cita),id_estado(Id_Estado) {}

//utilizamos getter para obtener la informacion de los parametros y retornarla
int citas_medicas::getId() const { return id_citas; }
int citas_medicas::getId_pacientes() const { return id_pacientes; }
int citas_medicas::getId_medico() const { return id_medico; }
string citas_medicas::getFecha_cita() const { return fecha_cita; }
int citas_medicas::getId_estado() const { return id_estado; }


//utilizamos los etter para enviar los parametros al constructor
void citas_medicas::setId(int _id) { id_citas = _id; }
void citas_medicas::setId_pacientes(int _Id_pacientes) { id_pacientes = _Id_pacientes; }
void citas_medicas::setId_medico(int _id_medico) { id_medico = _id_medico; }
void citas_medicas::setFecha_cita(string _fecha_cita) { fecha_cita = _fecha_cita; }
void citas_medicas::setId_estado(int _Id_estado) { id_estado = _Id_estado; }
