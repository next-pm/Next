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
import subprocess

#Local Packages
import read_config

def run():

    this_dir = os.getcwd()
    try:
        config_obj = read_config.read_config(this_dir)

        if config_obj != False:
            os.chdir(config_obj.get("build_dir"))
            subprocess.run(["./" + config_obj.get("name_build")])
    except OSError as exc:
        print(exc)
        exit()