
#include "citas_medicas_controller.h"
#include <iostream>
citas_medicas_controller::citas_medicas_controller(SQLHDBC conn) : conexion(conn) {} //creamos nuestra conexion

//creamos nuestro metodo crear
void citas_medicas_controller::crear(const citas_medicas& Citas_Medicas) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a instertar con los comandos sql en la tabla
    SQLPrepare(stmt, (SQLCHAR*)"INSERT INTO Citas_Medicas(id_pacientes,id_medico,fecha_cita,id_estado) VALUES (?,?,?,?)", SQL_NTS);
    //le enviaremos los parametros de lo que deseamos insertar como nombre
    int id_paciente = Citas_Medicas.getId_pacientes();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &id_paciente, 0, NULL);
    int id_medico = Citas_Medicas.getId_medico();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &id_medico, 0, NULL);
    //le mandamos los parametros
    SQLBindParameter(stmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)Citas_Medicas.getFecha_cita().c_str(), 0, NULL);
    int id_estado = Citas_Medicas.getId_estado();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 4, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &id_estado, 0, NULL);
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Cita creado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void citas_medicas_controller::listar() {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //con el comando select vamos a mostrar en tabla los valores que hay en la tabla
    SQLExecDirect(stmt, (SQLCHAR*)"SELECT id_citas,id_pacientes,id_medico,fecha_cita,id_estado FROM Citas_Medicas", SQL_NTS);
    SQLINTEGER id_citas,id_pacientes,id_medico,id_estado;
    SQLCHAR fecha_cita[201];

    SQLBindCol(stmt, 1, SQL_C_LONG, &id_citas, 0, NULL);
    SQLBindCol(stmt, 2, SQL_C_LONG, &id_pacientes, 0, NULL);
    SQLBindCol(stmt, 3, SQL_C_LONG, &id_medico, 0, NULL);
    SQLBindCol(stmt, 4, SQL_C_CHAR, &fecha_cita, sizeof(fecha_cita), NULL);
    SQLBindCol(stmt, 5, SQL_C_LONG, &id_estado, 0, NULL);

    //Si todo esta bien mostraremos los datos
    while (SQLFetch(stmt) == SQL_SUCCESS) {

        std::cout << "ID: " << id_citas << " | Paciente: " << id_pacientes << " | Medico: " << id_medico << " | Fecha de la Cita: "<< fecha_cita<<" Estado "<<id_estado<<std::endl;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void citas_medicas_controller::actualizar(int id, const citas_medicas& nuevaCita) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a proceder actualizar dentro de mi tabla
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Citas_Medicas SET fecha_cita = ? WHERE id_citas = ?", SQL_NTS);
    //le mandaremos los parametros de lo que deseamos actualizar
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)nuevaCita.getFecha_cita().c_str(), 0, NULL);
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //manaremos un mensaje en caso de que todo se haya actualizado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Cita actualizado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void citas_medicas_controller::eliminar(int id) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);//hacemos la coneexion
    //para no utilizar el comando delete vamos a poner en estado 0 todos los registros que sean eliminados
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Citas_Medicas SET fecha_cita = '0' WHERE id_citas = ?", SQL_NTS);//mandamos actualziar el estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //mandamos un mensaje si se actualizo el estado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Cita eliminado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}