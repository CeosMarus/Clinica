
#include "pacienteController.h"
#include <iostream>


pacienteController::pacienteController(SQLHDBC conn) : conexion(conn) {} //creamos nuestra conexion

//creamos nuestro metodo crear
void pacienteController::crear(const paciente& Paciente) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a instertar con los comandos sql en la tabla
    SQLPrepare(stmt, (SQLCHAR*)"INSERT INTO Pacientes(nombre_completo, edad,DPI,numero_contacto) VALUES (?,?,?,?)", SQL_NTS);
    //le enviaremos los parametros de lo que deseamos insertar como nombre
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)Paciente.getNombre().c_str(), 0, NULL);
    int edad = Paciente.getEdad();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &edad, 0, NULL);
    int dpi = Paciente.getDPI();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &dpi, 0, NULL);
    int numero_contacto = Paciente.getNumeroContacto();
    //le mandamos los parametros de lo que deseamos insertar como estado
    SQLBindParameter(stmt, 4, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &numero_contacto, 0, NULL);
    //mandamos un mensaje y hacemos una condicion en caso de que todo este correcto sin erroes
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Paciente creado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void pacienteController::listar() {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //con el comando select vamos a mostrar en tabla los valores que hay en la tabla
    SQLExecDirect(stmt, (SQLCHAR*)"SELECT id_pacientes,nombre_completo,edad,DPI,numero_contacto FROM Pacientes", SQL_NTS);

    SQLINTEGER id_pacientes;
    SQLCHAR nombre_completo[201],edad[4],DPI[21], numero_contacto[21];

    SQLBindCol(stmt, 1, SQL_C_LONG, &id_pacientes, 0, NULL);
    SQLBindCol(stmt, 2, SQL_C_CHAR, &nombre_completo, sizeof(nombre_completo), NULL);
    SQLBindCol(stmt, 3, SQL_C_CHAR, &edad, sizeof(edad), NULL);
    SQLBindCol(stmt, 4, SQL_C_CHAR, &DPI, sizeof(DPI), NULL);
    SQLBindCol(stmt, 5, SQL_C_CHAR, &numero_contacto, sizeof(numero_contacto), NULL);
    //Si todo esta bien mostraremos los datos

    while (SQLFetch(stmt) == SQL_SUCCESS) {

        std::cout << "ID: " << id_pacientes << " | Nombre: " << nombre_completo << " | Edad: " << edad << " | DPI: "<< DPI<<" | Numero de Contacto: "<<numero_contacto<<std::endl;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void pacienteController::actualizar(int id, const paciente& nuevoPaciente) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);
    //vamos a proceder actualizar dentro de mi tabla
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Pacientes SET nombre_completo = ? WHERE id_pacientes = ?", SQL_NTS);
    //le mandaremos los parametros de lo que deseamos actualizar
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 200, 0, (SQLPOINTER)nuevoPaciente.getNombre().c_str(), 0, NULL);
    SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //manaremos un mensaje en caso de que todo se haya actualizado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Paciente actualizado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void pacienteController::eliminar(int id) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, conexion, &stmt);//hacemos la coneexion
    //para no utilizar el comando delete vamos a poner en estado 0 todos los registros que sean eliminados
    SQLPrepare(stmt, (SQLCHAR*)"UPDATE Pacientes SET numero_contacto = 0 WHERE id_pacientes = ?", SQL_NTS);//mandamos actualziar el estado
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
    //mandamos un mensaje si se actualizo el estado correctamente
    if (SQLExecute(stmt) == SQL_SUCCESS) {
        std::cout << "Paciente eliminado correctamente.\n";
    }
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}