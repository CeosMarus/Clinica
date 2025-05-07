//
// Created by Axel Yoc on 4/05/2025.
//

#ifndef MEDICOS_H
#define MEDICOS_H
#include <string> //incluimos la calse string
using namespace std;


class medicos {
    //Creamos los atributos
private:
    int id_medicos;
    string nombre_completo;
    string especialidad;
    string dias_atencion;

public:
    medicos();//se define un constructor vacio
    medicos(string nombre_completo, string especialidad,string dias_atencion);//se define un constructor con parametros
    //creamos los getter y setters
    int getId() const;
    string getNombre() const;
    string getEspecialidad() const;
    string getDias_atencion() const;

    void setId(int);
    void setNombre(string);
    void setEspecialidad(string);
    void setDias_atencion(string);
};



#endif //MEDICOS_H
