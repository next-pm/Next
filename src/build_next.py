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

                try:
                    os.mkdir(config_obj.get("build_dir"))
                except:
                    print("Warning " + this_dir + "/" + config_obj.get("build_dir") +  " folder already exists")
                os.chdir(config_obj.get("build_dir"))

                subprocess.run([
                    "cmake", this_dir + "/.", 
                    "-G" + config_obj.get("build_system"), 
                    "-DCMAKE_CXX_COMPILER=" +  config_obj.get("cxx_compiler"), 
                    "-DCMAKE_C_COMPILER=" +  config_obj.get("c_compiler")] + config_obj.get("cmake_flags"))

                subprocess.run([config_obj.get("build_system_exe")] + config_obj.get("build_system_flags"))

        except OSError as exc:
            print(exc)
    except OSError as exc:
        print(exc)
        exit()