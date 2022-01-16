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
import shutil

#Local Packages
import tools

def create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system, type_project):

    next_dir = ""
    try:
        #Search NEXT_PACKAGES_DIR
        next_dir = os.environ['NEXT_DIR']
        print("NEXT_DIR in:", next_dir)

    except:
        #Not Find NEXT_PACKAGES_DIR
        print("It was not found ENV NEXT_PACKAGES_DIR in func --version_next.version_all()--")
        exit()

    print("Create a proyect of next in")
    try:
        # Create the dir
        os.mkdir(name)

        # Get nextEmptyProjectDir
        next_empty_project_dir = next_dir + "/assets/empty-project/"

        # Copy the nextEmptyProjectDir in new project {name}
        shutil.copytree(next_empty_project_dir, name, dirs_exist_ok=True)

        # View the dir of new project {name}
        dir_new_project = os.getcwd() + "/" + name

        print(os.getcwd() + "/" + name)

        tools.remplace_in_file(dir_new_project + "/config.yaml", "__name_project__", name)
        tools.remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_project__", name)

        if build_dir:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_dir__", build_dir)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_dir__", "build")

        if name_build:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__name_build__", name_build)
            tools.remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_build__", name_build)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__name_build__", "app")
            tools.remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_build__", "app")

        if build_system_exe and build_system:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_system_exe__", build_system_exe)
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_system__", build_system)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_system_exe__", "ninja")
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__build_system__", "Ninja")

        if c_compiler:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__c_compiler__", c_compiler)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__c_compiler__", "gcc")

        if cxx_compiler:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__cxx_compiler__", cxx_compiler)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__cxx_compiler__", "g++")

        if type_project:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__type_project__", type_project)
        else:
            tools.remplace_in_file(dir_new_project + "/config.yaml", "__type_project__", "g++")

    except OSError as exc:
        print(exc)