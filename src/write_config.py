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

#System Packages
import os

#Local Packages
import tools    

def _this_is_a_dir(dir):
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

def _clear_config_file(dir):
        config_file = open( dir + "/config.yaml", "w")
        config_file.close()

def write_config(config_obj, dir):
    # pasos 
    # 1.- identificar si el directorio es un NextPackage o NextProject
    # 2.- buscar el archivo config.yaml
    if _this_is_a_dir(dir):

        config_map = config_obj.to_map()
                
        with open('config.yaml', 'w') as file:
            documents = yaml.dump(config_map, file)
        
        tools.remplace_in_file("config.yaml", "'[", "[")
        tools.remplace_in_file("config.yaml", "]'", "]")

    return False

def write_property(config_obj, dir):
    # pasos 
    # 1.- identificar si el directorio es un NextPackage o NextProject
    # 2.- buscar el archivo config.yaml
    if _this_is_a_dir(dir):

        config_map = config_obj.to_map()
                
        with open('config.yaml', 'w') as file:
            documents = config_obj.yaml.dump(config_map, file)
        
        tools.remplace_in_file("config.yaml", "'[", "[")
        tools.remplace_in_file("config.yaml", "]'", "]")

    return False