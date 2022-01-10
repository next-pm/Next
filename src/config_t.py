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

    _data = {}

    def __init__(self, config_yaml, dir):
        self._data = config_yaml

    def print(self):
        print( "name_project: "         + self._data["name_project"])
        print( "description: "          + self._data["description"])
        print( "version: "              + self._data["version"])
        print( "build_dir: "            + self._data["build_dir"])
        print( "name_build: "           + self._data["name_build"])
        print( "build_system_exe: "     + self._data["build_system_exe"])
        print( "c_compiler: "           + self._data["c_compiler"])
        print( "cxx_compiler: "         + self._data["cxx_compiler"])
        print( "build_system: "         + self._data["build_system"])
        print( "cmake_flags: "          + listToString(self._data["cmake_flags"]))
        print( "build_system_flags: "   + listToString(self._data["build_system_flags"]))

    def get(self, option):
        return self._data[option]

    def set(self, option, value):
        self._data[option] = value
        return self._data[option]

    def add(self, option, value):
        self._data[option] += value
        return self._data[option]

    def to_map(self):
        return self._data