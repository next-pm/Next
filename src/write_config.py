######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 28/03/2022
### license = PSF
### version = 3.3.1 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import os

#Local Packages
import src.tools    

def _this_is_a_dir(dir):
    """Identify if this is Dir

    Args:
        dir (str): Direction of proyect

    Returns:
        bool: Flag
    """
    
    # Flag 
    done = False

    # Is a Directory
    if os.path.isdir(dir):
        done = True
        
        # Message(Successful): Is a directory
        src.tools.message_successful(dir + " Is a directory")
    else:
        
        # Message(Error): Not ss a directory
        src.tools.message_error(dir + " Not is a directory")
    
    return done

def write_property(config_obj, dir):
    """Write a new Property

    Args:
        config_obj (src.config_t): Configuration of project
        dir (str): Directory

    Returns:
        flag: Flag successful
    """
    
    # Identify if this is a directory
    if _this_is_a_dir(dir):

        # Get Map of Config_object
        config_map = config_obj.to_map()
                
        # Write Config
        with open('config.yaml', 'w') as file:
            documents = config_obj.yaml.dump(config_map, file)
        
        # Remplace chars '[' and ']'
        src.tools.remplace_in_file("config.yaml", "'[", "[")
        src.tools.remplace_in_file("config.yaml", "]'", "]")
        
        return True

    return False