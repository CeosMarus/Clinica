
#include "estadoController.h"
#include <iostream>


estadoController::estadoController(SQLHDBC conn) : conexion(conn) {} //creamos nuestra conexion

//creamos nuestro metodo crear
void estadoController::crear(const Estado& estado) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a instertar con los comandos sql en la tabla
    SQLPrepare(stmt, (SQLCHAR*)"INSERT INTO Estado(estado) VALUES (?)", SQL_NTS);
    int Estado = estado.getEstado();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &Estado, 0, NULL);
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Estado creado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void estadoController::listar() {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //con el comando select vamos a mostrar en tabla los valores que hay en la tabla
    SQLExecDirect(stmt, (SQLCHAR*)"SELECT id_estado, estado FROM Estado", SQL_NTS);
    SQLINTEGER id_estado,estado;

    SQLBindCol(stmt, 1, SQL_C_LONG, &id_estado, 0, NULL);
    SQLBindCol(stmt, 2, SQL_C_LONG, &estado, 0, NULL);

    //Si todo esta bien mostraremos los datos
    while (SQLFetch(stmt) == SQL_SUCCESS) {

        std::cout << "ID: " << id_estado << " | Estado: "<<estado<<std::endl;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void estadoController::actualizar(int id, const Estado& nuevoEstado) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a proceder actualizar dentro de mi tabla
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Estado SET estado = ? WHERE id_estado = ?", SQL_NTS);
    //le mandaremos los parametros de lo que deseamos actualizar
    int Estado=nuevoEstado.getEstado();
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 200, 0, &Estado, 0, NULL);
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //manaremos un mensaje en caso de que todo se haya actualizado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Estado actualizado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void estadoController::eliminar(int id) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);//hacemos la coneexion
    //para no utilizar el comando delete vamos a poner en estado 0 todos los registros que sean eliminados
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Estado SET estado = '0' WHERE id_estado = ?", SQL_NTS);//mandamos actualziar el estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //mandamos un mensaje si se actualizo el estado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Estado eliminado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}