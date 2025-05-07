#ifndef ODBCCONNECTION_H
#define ODBCCONNECTION_H
//incluimos las librerias para poder utilizar sus comandos
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

class conexion_DB {
    //vamos a preparar lo que son la conexion
private:
    SQLHENV hEnv;
    SQLHDBC hDbc;
    bool conectado;

public:
    conexion_DB();//constructor
    ~conexion_DB();//destructor

    bool conectar(const std::string& dsn, const std::string& usuario, const std::string& contrasena);//retorna true o false si la conexion fue exitosa
    void desconectar();//cierra la conexion activa para liberar recursos
    SQLHDBC getConexion();
};



#endif //CONEXION_DB_H
