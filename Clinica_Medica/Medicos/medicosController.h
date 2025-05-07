//
// Created by Axel Yoc on 4/05/2025.
//

#ifndef MEDICOSCONTROLLER_H
#define MEDICOSCONTROLLER_H

#include <windows.h>       // Para APIs de Windows
#include <sql.h>           // Para ODBC (Open Database Connectivity)
#include <sqlext.h>        // Extensiones de ODBC
#include <string>          // Para manejo de strings
#include "medicos.h"         // La clase Paciente que vamos a gestionar

class medicosController {
private:
    SQLHDBC conexion;

public:
    medicosController(SQLHDBC conn);

    void crear(const medicos& Medicos);
    void listar();
    void actualizar(int id, const  medicos& Medicos);
    void eliminar(int id);
};



#endif //MEDICOSCONTROLLER_H
