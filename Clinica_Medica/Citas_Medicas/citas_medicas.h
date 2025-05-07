#ifndef CITAS_MEDICAS_H
#define CITAS_MEDICAS_H

#include <string> //incluimos la calse string
using namespace std;


class citas_medicas {
    //Creamos los atributos
private:
    int id_citas;
    int id_pacientes;
    int id_medico;
    string fecha_cita;
    int id_estado;

public:
    citas_medicas();//se define un constructor vacio
    citas_medicas(int id_pacientes,int id_medico,string fecha_cita,int id_estado);//se define un constructor con parametros
    //creamos los getter y setters
    int getId() const;
    int getId_pacientes() const;
    int getId_medico() const;
    string getFecha_cita() const;
    int getId_estado() const;

    void setId(int);
    void setId_pacientes(int);
    void setId_medico(int);
    void setFecha_cita(string);
    void setId_estado(int);
};



#endif //CITAS_MEDICAS_H
