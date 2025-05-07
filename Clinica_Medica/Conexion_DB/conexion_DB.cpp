//
// Created by Axel Yoc on 4/05/2025.
//

#include "conexion_DB.h"
#include <iostream>
//realizaremos lo que es la conexxion
conexion_DB::conexion_DB() : conectado(false) {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
}
//creamos el destructor para poder cerrar la conexion y liberar recursos
conexion_DB::~conexion_DB() {
    desconectar();
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}

//vamos a ingresar todos los datos para la conexion de la base
bool conexion_DB::conectar(const std::string& dsn_unused, const std::string& usuario, const std::string& contrasena) {
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    // Cadena completa, ignorando los parámetros dsn/usuario/contrasena
    std::string connStr =
        "Driver={ODBC Driver 17 for SQL Server};"//ingresamos el codigo de nuestro odbc
        "Server=DESKTOP-8PGVTQL;"//ingresamos el servidor de SQL
        "Database=Clinica;"//nombre de la base de datos
        "Trusted_Connection=Yes;"//ponemos que si para que nos haga la conexxion sin problemas
        //"Uid=sa;"
        //"Pwd=;"
        "Encrypt=yes;"
        "TrustServerCertificate=yes;";

    SQLRETURN ret = SQLDriverConnect(hDbc, NULL,
        (SQLCHAR*)connStr.c_str(), SQL_NTS,
        outstr, sizeof(outstr), &outstrlen, SQL_DRIVER_COMPLETE);


    //mandamos un mensaje si la conexion fue exitosa y en caso contratrio mandamos que hubo un error
    if (SQL_SUCCEEDED(ret)) {
        conectado = true;//ingresamos en true de que se conecto correctamente
        return true;//retonramos true
    } else {
        std::cerr << "❌ Error al conectar con SQL Server usando ODBC Driver 18.\n"; //mandamos un mensaje en caso de error
        return false;//retonramos false
    }
}

//vamos a utilizar la desconexion para liberar recursos
void conexion_DB::desconectar() {
    if (conectado) {
        SQLDisconnect(hDbc);
        conectado = false;//ingresamos false para desconectar la abse de datos
    }
}
//vamos a obtener la conexion y liberaremos recursos
SQLHDBC conexion_DB::getConexion() {
    return hDbc;
}