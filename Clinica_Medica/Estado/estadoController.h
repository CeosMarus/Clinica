//
// Created by Axel Yoc on 4/05/2025.
//

#ifndef ESTADOCONTROLLER_H
#define ESTADOCONTROLLER_H

#include <windows.h>       // Para APIs de Windows
#include <sql.h>           // Para ODBC (Open Database Connectivity)
#include <sqlext.h>        // Extensiones de ODBC
#include <string>          // Para manejo de strings
#include "Estado.h"         // La clase Paciente que vamos a gestionar

class estadoController {
private:
    SQLHDBC conexion;

public:
    estadoController(SQLHDBC conn);

    void crear(const Estado& estados);
    void listar();
    void actualizar(int id, const  Estado& estados);
    void eliminar(int id);
};



#endif //ESTADOCONTROLLER_H
