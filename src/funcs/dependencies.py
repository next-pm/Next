import src.funcs.read_config


def get_dependencies(route: str):
    
    list_dependencies = []
    
    try:
        
        # Read config of proyect
        config_obj = src.funcs.read_config.read_config(route)
        
        dependencies = config_obj.get('dependencies')
        
        for name_include in dependencies:
            
            list_dependencies.append({name_include: dict(dependencies[name_include]) })

    except OSError as exc:
        # Message(Error): OSError generate
        src.tools.message_error(str(exc))
        
    return list_dependencies