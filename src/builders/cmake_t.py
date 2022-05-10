import src.config_t

class Cmake_t:
    
    config_build = {}
    
    def __init__(self, config_build):
        self.config_build = config_build
    
    def build(self,config_obj: src.config_t.config_t):
        
        cmake_config_str = src.tools.object_to_yaml_str(self.config_build).replace("...", "")
        
        print(cmake_config_str)