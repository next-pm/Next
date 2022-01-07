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
import shutil
import os

#Local Packages
import read_config

def clean():
    this_dir = os.getcwd()
    try:
        config_obj = read_config.read_config(this_dir)

        if config_obj != False:
            shutil.rmtree(config_obj.build_dir)
    except OSError as exc:
        print(exc)
        exit()