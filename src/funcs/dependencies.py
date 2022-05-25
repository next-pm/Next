
import src.funcs.read_config
import src.tool.messages as MESSAGES_tools


def get_dependencies(route: str): 
    
    list_dependencies = []
    
    try:
        
        # Read config of proyect
        config_obj = src.funcs.read_config.read_config(route)
        
        dependencies = config_obj.get('dependencies')
        
        if dependencies is not None:

            for name_include in dependencies:
                
                list_dependencies.append({name_include: dict(dependencies[name_include]) })

    except OSError as exc:
        # Message(Error): OSError generate
        MESSAGES_tools.message_error(str(exc))
        
    return list_dependencies