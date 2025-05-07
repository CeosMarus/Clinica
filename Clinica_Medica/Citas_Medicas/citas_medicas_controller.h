

#ifndef CITAS_MEDICAS_CONTROLLER_H
#define CITAS_MEDICAS_CONTROLLER_H

#include <windows.h>       // Para APIs de Windows
#include <sql.h>           // Para ODBC (Open Database Connectivity)
#include <sqlext.h>        // Extensiones de ODBC
#include <string>          // Para manejo de strings
#include "citas_medicas.h"         // La clase Paciente que vamos a gestionar

class citas_medicas_controller {
private:
    SQLHDBC conexion;

public:
    citas_medicas_controller(SQLHDBC conn);

    void crear(const citas_medicas& Citas_Medicas);
    void listar();
    void actualizar(int id, const  citas_medicas& Citas_Medicas);
    void eliminar(int id);
};



#endif //CITAS_MEDICAS_CONTROLLER_H
