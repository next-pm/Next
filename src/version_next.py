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

# Update 05/01/2022
_VERSION = "3.0.0"

#System Packages
import os

#Local Packages
import read_config


def version():
    print("Next version: " + _VERSION)

def version_all():
    next_dir = ""
    try:
        #Search NEXT_PACKAGES_DIR
        next_dir = os.environ['NEXT_PACKAGES_DIR']
        print("NEXT_PACKAGES_DIR in:", next_dir)

    except:
        #Not Find NEXT_PACKAGES_DIR
        print("It was not found ENV NEXT_PACKAGES_DIR in func --version_next.version_all()--")
        exit()

    list_next_packages = os.listdir(next_dir)

    for next_pakage_dir in list_next_packages:

        config_obj = read_config.read_config(next_dir+ "/" + next_pakage_dir)

        if config_obj != False:
            print(config_obj.name_project + " " + config_obj.version + "\n")
    