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

def build():

    try:
        this_dir = os.getcwd()
        try:
            config_obj = read_config.read_config(this_dir)

            if config_obj != False:
                os.mkdir(config_obj.build_dir)

                os.chdir(config_obj.build_dir)

                subprocess.run([
                    "cmake", this_dir + "/.", 
                    "-G" + config_obj.build_system, 
                    "-DCMAKE_CXX_COMPILER=" +  config_obj.cxx_compiler, 
                    "-DCMAKE_C_COMPILER=" +  config_obj.c_compiler] + config_obj.cmake_flags)

                subprocess.run([config_obj.build_system_exe] + config_obj.build_system_flags)

        except OSError as exc:
            print(exc)
    except OSError as exc:
        print(exc)
        exit()