import os

from src.config_t import config_t as Config_t

import src.funcs.includes
import src.funcs.dependencies
"""
# Command to build the project of Cmake
subprocess.run([
    "cmake", this_dir + "/.", 
    "-G" + config_obj.get("build_system"), 
    "-DCMAKE_CXX_COMPILER=" +  config_obj.get("cxx_compiler"), 
    "-DCMAKE_C_COMPILER=" +  config_obj.get("c_compiler"),
    "-D" + config_obj.get("type_project") +"=on" ] + config_obj.get("cmake_flags"))

# Command to build the project of build_system
subprocess.run([config_obj.get("build_system_exe")] + config_obj.get("build_system_flags"))
"""

def listToStr(list, separator=None):
    str1 = ""
    for e in list:
        str1 += e
        if separator:
            str1 += separator
    return str1
    

class Cmake_t:
    
    config_build = {}
    this_dir = ""
    
    def __init__(self, config_build, this_dir):
        self.config_build = config_build
        self.this_dir = this_dir
    
    def build(self,config_obj: Config_t):
        
        # Paso(1): Conocre el directorio, el build system subyaciente de cmake, los compiladores que se usaran, el tipo de proyecto que sera (libreria o ejecutable), y la lista de flags para cmake
        # Paso(2): Conocer los directorios include del proyecto
        # Paso(3): Generar el tree del proyecto
        # Paso(4): Conocer las dependencias del proyecto
        #   Paso(4.1): Conocer los directorios include del proyecto
        #   Paso(4.2): Conocer el nombre y la direccion de la biblioteca (.a, .so .lib .dll)
        # Paso(5): Acumular el include 
        
        command = "cmake" + " " + self.this_dir + "/." + " " +"-G" + "\"" + self.config_build["build_system"] + "\"" + " " + "-DCMAKE_CXX_COMPILER=" +  self.config_build["cxx_compiler"] + " " + "-DCMAKE_C_COMPILER=" +  self.config_build["c_compiler"] + " " + "-D" + config_obj.get("type_project") +"=on" + " " + listToStr(self.config_build["cmake_flags"], separator=" ")
        
        print(src.funcs.dependencies.get_dependencies(self.this_dir))
        
        #print(command)