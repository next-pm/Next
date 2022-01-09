######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 08/01/2022
### license = PSF
### version = 3.0.0 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

# Packages Dependencies
import yaml

def listToString(s): 
    
    # initialize an empty string
    str1 = " " 
    
    # return string  
    return (str1.join(s))

class Config_t:
    name_project        = ""
    description         = ""
    version             = ""
    build_dir           = ""
    name_build          = ""
    build_system_exe    = ""
    c_compiler          = ""
    cxx_compiler        = ""
    build_system        = ""
    cmake_flags         = []
    build_system_flags  = []

    def __init__(self, config_yaml, dir):
        try:
            self.name_project = config_yaml["name_project"]
        except:
            print(" ERROR Not find value name_project in " + dir)

        try:
            self.description = config_yaml["description"]
        except:
            print(" ERROR Not find value description in " + dir)

        try:
            self.version = config_yaml["version"]
        except:
            print(" ERROR Not find value version in " + dir)

        try:
            self.build_dir = config_yaml["build_dir"]
        except:
            print(" ERROR Not find value build_dir in " + dir)

        try:
            self.name_build = config_yaml["name_build"]
        except:
            print(" ERROR Not find value name_build in " + dir)

        try:
            self.build_system_exe = config_yaml["build_system_exe"]
        except:
            print(" ERROR Not find value build_system_exe in " + dir)

        try:
            self.c_compiler = config_yaml["c_compiler"]
        except:
            print(" ERROR Not find value c_compiler in " + dir)

        try:
            self.cxx_compiler = config_yaml["cxx_compiler"]
        except:
            print(" ERROR Not find value cxx_compiler in " + dir)

        try:
            self.build_system = config_yaml["build_system"]
        except:
            print(" ERROR Not find value build_system in " + dir)

        try:
            self.cmake_flags = config_yaml["cmake_flags"]
        except:
            print(" ERROR Not find value cmake_flags in " + dir)

        try:
            self.build_system_flags = config_yaml["build_system_flags"]
        except:
            print(" ERROR Not find value build_system_flags in " + dir)

    def print(self):
        print( "name_project: "         + self.name_project)
        print( "description: "          + self.description)
        print( "version: "              + self.version)
        print( "build_dir: "            + self.build_dir)
        print( "name_build: "           + self.name_build)
        print( "build_system_exe: "     + self.build_system_exe)
        print( "c_compiler: "           + self.c_compiler)
        print( "cxx_compiler: "         + self.cxx_compiler)
        print( "build_system: "         + self.build_system)
        print( "cmake_flags: "          + listToString(self.cmake_flags))
        print( "build_system_flags: "   + listToString(self.build_system_flags))

    def get(self, option):
        if option == "name_project": 
            return self.name_project

        elif option == "description":
            return self.description

        elif option == "version":
            return self.version

        elif option == "build_dir":
            return self.build_dir

        elif option == "name_build":
            return self.name_build

        elif option == "build_system_exe":
            return self.build_system_exe

        elif option == "c_compiler":
            return self.c_compiler

        elif option == "cxx_compiler":
            return self.cxx_compiler

        elif option == "build_system":
            return self.build_system

        elif option == "cmake_flags":
            return self.cmake_flags

        elif option == "build_system_flags":
            return self.build_system_flags
        else:
            return "null"

    def set(self, option, value):
        if option == "name_project": 
            self.name_project = value
            return self.name_project

        elif option == "description":
            self.description = value
            return self.description

        elif option == "version":
            self.version = value
            return self.version

        elif option == "build_dir":
            self.build_dir = value
            return self.build_dir

        elif option == "name_build":
            self.name_build = value
            return self.name_build

        elif option == "build_system_exe":
            self.build_system_exe = value
            return self.build_system_exe

        elif option == "c_compiler":
            self.c_compiler = value
            return self.c_compiler

        elif option == "cxx_compiler":
            self.cxx_compiler = value
            return self.cxx_compiler

        elif option == "build_system":
            self.build_system = value
            return self.build_system

        elif option == "cmake_flags":
            self.cmake_flags = value
            return self.cmake_flags

        elif option == "build_system_flags":
            self.build_system_flags = value
            return self.build_system_flags
        else:
            return "null"

    def to_map(self):
        object_map = {
            "name_project":        self.name_project,
            "description":         self.description,
            "version":             self.version,
            "build_dir":           self.build_dir,
            "name_build":          self.name_build,
            "build_system_exe":    self.build_system_exe,
            "c_compiler":          self.c_compiler,
            "cxx_compiler":        self.cxx_compiler,
            "build_system":        self.build_system,
            "cmake_flags":         self.cmake_flags,
            "build_system_flags":  self.build_system_flags,
        }
        return object_map