######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 07/01/2022
### license = PSF
### version = 3.0.0 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import os

# Packages Dependencies
import yaml

#Local Packages
import config_t    

def _this_is_a_next_project_dir(dir):
    done = False

    if os.path.isdir(dir):
        done = True
    else:
        print(dir + " Not is a directory")
    
    return done

def _exists_config_file(dir):
    done = False
    try:
        config_file = open( dir + "/config.yaml", "r")
        config_file.close()
        done = True
    except:
        print(dir + " Not is a NextProject")
    
    return done

def _get_config_data(dir):
    config_data = ""
    try:
        config_file = open( dir + "/config.yaml", "r")
        config_data = config_file.read()
        config_file.close()
    except:
        print(dir + "Error when opening " + dir + "/config.yaml")
    
    return config_data

def read_config(dir):
    # pasos 
    # 1.- identificar si el directorio es un NextPackage o NextProject
    # 2.- buscar el archivo config.yaml
    if _this_is_a_next_project_dir(dir) and _exists_config_file(dir):
        # 3.- abrir y leer el archivo
        #config_data = _get_config_data(dir)
        #config_yaml = yaml.safe_load(config_data)
        # 4.- Crear un objeto Config
        config_obj = config_t.Config_t(dir)
        return config_obj
    return False