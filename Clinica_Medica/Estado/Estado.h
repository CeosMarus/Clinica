
#ifndef ESTADO_H
#define ESTADO_H

#include <string> //incluimos la calse string
using namespace std;

class Estado {
    //Creamos los atributos
private:
    int id_estado;
    int estado;
public:
    Estado();//se define un constructor vacio
    Estado(int estado);//se define un constructor con parametros
    //creamos los getter y setters
    int getId() const;
    int getEstado() const;


    void setId(int);
    void setEstado(int);

};



#endif //ESTADO_H
