######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 12/03/2022
### license = PSF
### version = 3.3.1
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import os
import subprocess

#Local Packages
import src.read_config
import src.tools
import src.models.build_t

def build(build_name=None):
    """Build project from current directory
    """
    
    try:
        
        # Current directory
        this_dir = os.getcwd()
        
        try:
            
            # Read config of proyect
            config_obj = src.read_config.read_config(this_dir)

            # If the configuration is not empty
            if config_obj != False:

                try:
                    # Try create build_dir
                    os.mkdir(config_obj.get("build_dir"))
                    
                    # Message(Successful): The build_dir directory was created
                    src.tools.message_successful(this_dir + '/' + config_obj.get("build_dir"))
                    
                except:
                    # Message(Waiting): The build_dir folder already exists
                    src.tools.message_warning("Warning " + this_dir + "/" + config_obj.get("build_dir") +  " folder already exists")
                
                # Entering the directory build_dir
                os.chdir(config_obj.get("build_dir"))
                
                # Message(Waiting): Build Proyect
                src.tools.message_waiting("Build Proyect")
                
                # Create a buider
                build_obj = src.models.build_t.Build_t(build_name, config_obj, this_dir)
                
                #Build the Builder
                build_obj.build()
                
            # The configuration is empty
            else:
                # Message(Warning): The configuration is empty
                src.tools.message_warning("The configuration is empty")

        except OSError as exc:
            
            # Message(Error): OSError generate
            src.tools.message_error(str(exc))
    except OSError as err:
        
        # Message(Error): OSError generate
        src.tools.message_error(str(err))
        
        # Exit to program
        exit()