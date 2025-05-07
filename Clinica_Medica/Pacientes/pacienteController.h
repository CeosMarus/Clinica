//
// Created by Axel Yoc on 4/05/2025.
//

#ifndef PACIENTECONTROLLER_H
#define PACIENTECONTROLLER_H

#include <windows.h>       // Para APIs de Windows
#include <sql.h>           // Para ODBC (Open Database Connectivity)
#include <sqlext.h>        // Extensiones de ODBC
#include <string>          // Para manejo de strings
#include "paciente.h"         // La clase Paciente que vamos a gestionar

class pacienteController {
private:
    SQLHDBC conexion;

public:
    pacienteController(SQLHDBC conn);

    void crear(const paciente& Paciente);
    void listar();
    void actualizar(int id, const paciente& Paciente);
    void eliminar(int id);
};



#endif //PACIENTECONTROLLER_H
