######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 02/06/2022
### license = PSF
### version = 3.3.1 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import subprocess
import os

# Local Packages

from src.models.config_t import config_t as Config_t
import src.tool.messages as MESSAGES_tools
import src.funcs.includes as INCLUDE_funcs
import src.tool.string as STRING_tools

class Cmake_t:
    
    config_build = {}
    this_dir = ""
    build_name = ""
    
    def __init__(self, config_build, this_dir, build_name=""):
        self.config_build = config_build
        self.this_dir = this_dir
        self.build_name = build_name

    def _generateCommand(
        dir: str, 
        build_system: str, 
        type_project: str, 
        c_compiler: str, 
        cxx_compiler: str, 
        cmake_flags: list,
        include_dirs: list
        ):

        command = []

        # Add Cmake executable
        command.append ("cmake")

        # Add Directory of project
        command.append(dir + "/.")

        # Add BuildSystem
        if(STRING_tools.countWord(build_system) == 1):
            command.append( "-G"  + build_system  )
        else: 
            command.append( "-G" + "\"" + build_system + "\""  )

        # Add C compiler
        command.append( "-DCMAKE_C_COMPILER=" + c_compiler )

        # Add C++ compiler
        command.append( "-DCMAKE_CXX_COMPILER=" + cxx_compiler)

        # Add type Project
        command.append( "-D" + type_project + "=on" )

        # Add cmake_flags
        command += cmake_flags

        #Add inlucde Local
        command.append( "-DINCLUDE_LOCAL=\"" + STRING_tools.listToStr(include_dirs, ";") + "\"" )

        return command

    def _generateCommadBuildSystem(
        build_system_exce: str,
        build_system_flags: str
    ):
        command = []

        # Add build system executable
        command.append( build_system_exce )

        # Add build system flags
        command += build_system_flags

        return command
    
    def build(self,config_obj: Config_t):
        
        # Into in the directory of build
        os.chdir(config_obj.get("build_dir"))
        os.mkdir(self.build_name)
        os.chdir(self.build_name)

        # Get the include local
        include_local = INCLUDE_funcs.get_includes(self.this_dir)
        
        # Desactivate the output
        MESSAGES_tools.OUTPUT_ACTIVATED = False
        
        # create command of Cmake
        command = Cmake_t._generateCommand(
                dir=self.this_dir,
                build_system=self.config_build["build_system"],
                c_compiler=self.config_build["c_compiler"],
                cxx_compiler=self.config_build["cxx_compiler"],
                type_project=config_obj.get("type_project"),
                cmake_flags=self.config_build["cmake_flags"],
                include_dirs=include_local
            )

        # Run the Cmake Command
        subprocess.run(command)

        # Create command of build system
        buildSystemCommand = Cmake_t._generateCommadBuildSystem(
            build_system_exce=self.config_build["build_system_exe"],
            build_system_flags=self.config_build["build_system_flags"]
        )

        # Run the command of build system
        subprocess.run(buildSystemCommand)