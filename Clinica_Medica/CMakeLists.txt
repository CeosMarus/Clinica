cmake_minimum_required(VERSION 3.30)
project(Clinica_Medica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clinica_Medica main.cpp
        Conexion_DB/conexion_DB.cpp
        Conexion_DB/conexion_DB.h
        Pacientes/pacienteController.cpp
        Pacientes/pacienteController.h
        Pacientes/paciente.cpp
        Pacientes/paciente.h
        Medicos/medicosController.cpp
        Medicos/medicosController.h
        Medicos/medicos.cpp
        Medicos/medicos.h
        Citas_Medicas/citas_medicas_controller.cpp
        Citas_Medicas/citas_medicas_controller.h
        Citas_Medicas/citas_medicas.cpp
        Citas_Medicas/citas_medicas.h
        Estado/estadoController.cpp
        Estado/estadoController.h
        Estado/Estado.cpp
        Estado/Estado.h)

target_link_libraries(Clinica_Medica odbc32)