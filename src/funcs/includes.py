import src.funcs.read_config
import src.tool.messages as MESSAGES_tools

def get_includes(route: str):
    
    list_includes = []
    
    try:
        
        # Read config of proyect
        config_obj = src.funcs.read_config.read_config(route)
        
        for include in config_obj.get('include_dirs'):
            list_includes.append(include)
        
    except OSError as exc:
        # Message(Error): OSError generate
        MESSAGES_tools.message_error(str(exc))
        
    return list_includes