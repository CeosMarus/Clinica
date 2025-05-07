//
// Created by Axel Yoc on 4/05/2025.
//

#ifndef PACIENTE_H
#define PACIENTE_H
#include <string> //incluimos la calse string
using namespace std;



class paciente {
    //Creamos los atributos
private:
    int id_pacientes;
    string nombre_completo;
    int edad;
    int DPI;
    int numero_contacto;

public:
    paciente();//se define un constructor vacio
    paciente(string nombre_completo, int edad,int DPI,int numero_contacto);//se define un constructor con parametros
    //creamos los getter y setters
    int getId() const;
    string getNombre() const;
    int getEdad() const;
    int getDPI() const;
    int getNumeroContacto() const;

    void setId(int);
    void setNombre(string);
    void setEdad(int);
    void setDPI(int);
    void setNumeroContacto(int);
};



#endif //PACIENTE_H
