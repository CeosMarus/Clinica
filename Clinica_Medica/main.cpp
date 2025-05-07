#include <iostream>
#include <windows.h>
#include "Conexion_DB/conexion_DB.h"
#include "Pacientes/pacienteController.h"
#include "Medicos/medicosController.h"
#include "Estado/estadoController.h"
#include "Citas_Medicas/citas_medicas_controller.h"
int main() {
    SetConsoleOutputCP(65001); // <-- Esto configura la consola a UTF-8
    try {
        conexion_DB conexion; //mandamos a llamar a conexion

        //mandamos un mensaje si la conexion tubo algun problema al establecer la conexion
        if (!conexion.conectar("", "", "")) {
            throw std::runtime_error("❌ No se pudo establecer la conexión con SQL Server.");
        }
        //en caso de que no mandara un mensaje de conectado exitosamente
        std::cout << "✅ Conectado exitosamente a SQL Server.\n";

        pacienteController paciente_controller(conexion.getConexion());//mandamos a llamar a la conexion
        medicosController medicos_Controller(conexion.getConexion());//mandamos a llamar a la conexion
        estadoController estado_Controller(conexion.getConexion());
        citas_medicas_controller Citasmedicas_Controller(conexion.getConexion());
        //OPERACIONES CRUD DE PACIENTE
        /* //Creamos un nuevo Paciente
        paciente nuevo("Daniel Ochoa", 19,1245879658745,13857478);
        paciente_controller.crear(nuevo);

        //Listar Pacientes
        paciente_controller.listar();

        //Actualizar Paciente con ID 1
        paciente_controller.actualizar(3, paciente("Juan Perez", 100,1,5874));

        //Eliminación lógica: marcar estado = 0
        paciente_controller.eliminar(2);*/

        //TODO OPERACIONES CRUD DE Medicos

        /* //Creamos un nuevo Medico
        medicos nuevo("Pedro Martinez","Cirujano","Lunes,Miercoles");
        medicos_Controller.crear(nuevo);

        //Listar Medicos
        medicos_Controller.listar();

        //Actualizar Medicos con ID 1
        medicos_Controller.actualizar(1, medicos("Bryan Ochoa","Doctor","Martes, Jueves"));

        //Eliminación lógica: marcar estado = 0
        medicos_Controller.eliminar(1);*/

        //TODO OPERACIONES CRUD DE ESTADO
        /*//Creamos un nuevo Paciente
        Estado nuevo(1);
        estado_Controller.crear(nuevo);

        //Listar Pacientes
        estado_Controller.listar();

        //Actualizar Paciente con ID 1
        estado_Controller.actualizar(1, Estado(3));

        //Eliminación lógica: marcar estado = 0
        estado_Controller.eliminar(1);*/

        //TODO OPERACIONES CRUD CITAS MEDICAS
        /*//Creamos un nuevo Paciente
        // citas_medicas nuevo(1,2,"02/10/2023",1);
         Citasmedicas_Controller.crear(nuevo);

        //Listar Pacientes
        Citasmedicas_Controller.listar();

        //Actualizar Paciente con ID 1
        Citasmedicas_Controller.actualizar(9, citas_medicas(1,2,"10/10/2025",1));

        //Eliminación lógica: marcar estado = 0
         Citasmedicas_Controller.eliminar(9);*/ //no funciona bien no ejectuta la sentencia SQL

    }catch (const std::exception& e) {
        std::cerr << "⚠️ Error en ejecución: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}