from distutils.command import config
import src.config_t
import src.builders.cmake_t

class Build_t:
    
    builder = None
    config_build = {}
    config_obj = None

    def __init__(self, build_name, config_obj: src.config_t.config_t):
        """Initialize a src.models.Build_t

        Args:
            build_name (str): Name of Build
            config_obj (src.models.Config_t)
        """
        self.config_obj = config_obj
        
        builds = config_obj.get('builds')

        if build_name != None:
            try:
                self.config_build = builds[build_name]
            
                if self.config_build['base'] == 'cmake':
                    self.builder = src.builders.cmake_t.Cmake_t(self.config_build)
            except KeyError as exc:
                
                # Message(Error): OSError generate
                src.tools.message_error('The name of the requested build does not exist: ' + str(exc))
        else:
            self._none_name(config_obj)
                
    def _none_name(self, config_obj: src.config_t.config_t):
        """Initialize a src.models.Build_t

        Args:
            build_name (str): Name of Build
            config_obj (src.models.Config_t)
        """
        self.config_obj = config_obj
        
        builds = config_obj.get('builds')

        print("Set iene que usar el primer builder")
                
    def build(self):
        self.builder.build(self.config_obj)