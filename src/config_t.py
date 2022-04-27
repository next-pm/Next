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
import ruamel.yaml

def listToString(s): 
    
    # initialize an empty string
    str1 = " " 
    
    # return string  
    return (str1.join(s))

class Config_t:

    _data = {}
    file = ''
    yaml = ''

    def __init__(self, dir):
        #creamos un Yaml
        self.yaml = ruamel.yaml.YAML()
        self.yaml.preserve_quotes = True

        #Leemos el Archivo
        self.file = open( dir + "/config.yaml", "r")

        #Guardamos los datos
        self._data = self.yaml.load(self.file)

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
        try:
            value = self._data[option]
        except:
            value = "null"
        return value

    def set(self, option, value):
        try:
            current_value = self._data[option]
            self._data[option] = value
            new_value = self._data[option]
        except:
            print("Property does not exist")
            new_value = "null"
        return new_value

    def add(self, option, value):
        try:
            self._data[option] = value
            new_value = self._data[option]
        except:
            print("Property does not exist")
            new_value = "null"
        return new_value

    def to_map(self):
        return self._data