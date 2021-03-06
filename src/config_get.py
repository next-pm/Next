######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 20/03/2022
### license = PSF
### version = 3.3.1 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import os

#Local Packages
import src.read_config
import src.tools

def get(property, comments = True):
    """Get a property to the current project

    Args:
        property (str): name of property

    Returns:
        value_of_property([str, null]): value of property
    """

    # default value of property
    value_of_property = "null"

    # alone Next version
    if(property != ""):

        # View the dir of current project {name}
        dir_project = os.getcwd()

        #Read config of current project
        config_obj = src.read_config.read_config(dir_project)

        #Wrapper for properties
        value_of_property = config_obj.get(property)
        
        #If it was added correctly
        if(value_of_property != "null"):
            
            value_of_property_str = src.tools.object_to_yaml_str(value_of_property).replace("...", "")
            
            if comments == False:
                value_of_property_str = src.tools.stripComments(value_of_property_str)
            # Message(Successful): Getting property
            src.tools.message_successful('Getting property \n' + property + ': ' +  value_of_property_str)
            
        else:
            # Message(Error): Could not add
            src.tools.message_error('Could not get ' + property)

    #Value of new property ([str, null])
    return value_of_property