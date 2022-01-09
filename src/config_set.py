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
import read_config
import write_config

def set(property, value):

    # default value of property
    value_of_property = "null"

    # alone Next version
    if(property != ""):

        # View the dir of current project {name}
        dir_project = os.getcwd()

        #Read config of current project
        config_obj = read_config.read_config(dir_project)

        #Wrapper for properties
        value_of_property = config_obj.set(property, value)

        if(value_of_property != "null"):
            write_config.write_config(config_obj, dir_project)

    return value_of_property