
#include "medicosController.h"
#include <iostream>


medicosController::medicosController(SQLHDBC conn) : conexion(conn) {} //creamos nuestra conexion

//creamos nuestro metodo crear
void medicosController::crear(const medicos& Medicos) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a instertar con los comandos sql en la tabla
    SQLPrepare(stmt, (SQLCHAR*)"INSERT INTO Medicos(nombre_completo,especialidad,dias_atencion) VALUES (?,?,?)", SQL_NTS);
    //le enviaremos los parametros de lo que deseamos insertar como nombre
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)Medicos.getNombre().c_str(), 0, NULL);
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)Medicos.getEspecialidad().c_str(), 0, NULL);
    SQLBindParameter(stmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)Medicos.getDias_atencion().c_str(), 0, NULL);
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Medico creado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void medicosController::listar() {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //con el comando select vamos a mostrar en tabla los valores que hay en la tabla
    SQLExecDirect(stmt, (SQLCHAR*)"SELECT id_medicos, nombre_completo,especialidad,dias_atencion FROM Medicos", SQL_NTS);
    SQLINTEGER id_medicos;
    SQLCHAR nombre_completo[201];
    SQLCHAR especialidad[201];
    SQLCHAR dias_atencion[201];

    SQLBindCol(stmt, 1, SQL_C_LONG, &id_medicos, 0, NULL);
    SQLBindCol(stmt, 2, SQL_C_CHAR, &nombre_completo, sizeof(nombre_completo), NULL);
    SQLBindCol(stmt, 3, SQL_C_CHAR, &especialidad, sizeof(especialidad), NULL);
    SQLBindCol(stmt, 4, SQL_C_CHAR, &dias_atencion, sizeof(dias_atencion), NULL);
    //Si todo esta bien mostraremos los datos
    while (SQLFetch(stmt) == SQL_SUCCESS) {

        std::cout << "ID: " << id_medicos << " | Nombre: " << nombre_completo << " | Especialidad: " << especialidad << " | Dias de atencion: "<< dias_atencion<<std::endl;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void medicosController::actualizar(int id, const medicos& nuevoMedico) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a proceder actualizar dentro de mi tabla
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Medicos SET nombre_completo = ? WHERE id_medicos = ?", SQL_NTS);
    //le mandaremos los parametros de lo que deseamos actualizar
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)nuevoMedico.getNombre().c_str(), 0, NULL);
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //manaremos un mensaje en caso de que todo se haya actualizado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Medico actualizado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void medicosController::eliminar(int id) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);//hacemos la coneexion
    //para no utilizar el comando delete vamos a poner en estado 0 todos los registros que sean eliminados
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Medicos SET dias_atencion = '0' WHERE id_medicos = ?", SQL_NTS);//mandamos actualziar el estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //mandamos un mensaje si se actualizo el estado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Medico eliminado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}