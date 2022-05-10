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
        
        # Save the config_obj
        self.config_obj = config_obj
        
        # Get Builds
        builds = config_obj.get('builds')

        # Check that it is not None
        if build_name != None:
            
            # Select the Builder
            self._select_builder(build_name, builds)
        else:
            
            # Setup if no name explicit
            self._none_name()
            
    def _select_builder(self, build_name: str, builds):
        """ Select a Build

        Args:
            build_name (str): Name of Build
            builds (list: {}): List of Builds
        """
        # Try get Build 
        try:
            
            #Find Build
            self.config_build = builds[build_name]
        
            # Selctor of base of Build
            if self.config_build['base'] == 'cmake':
                self.builder = src.builders.cmake_t.Cmake_t(self.config_build)
        except KeyError as exc:
            
            # Message(Error): OSError generate
            src.tools.message_error('The name of the requested build does not exist: ' + str(exc))
                
    def _none_name(self):
        """Initialize a src.models.Build_t without build_name explicit
        """
        
        # Get a Builds
        builds = self.config_obj.get('builds')
        
        if builds != None:
            
            # Get a first builder
            for builder in builds:
                self._select_builder(builder, builds)
                break
        else:
            # Message(Error): OSError generate
            src.tools.message_error('There are no builds to be able to build the project')
                
    def build(self):
        
        # check that it is not None
        if self.builder != None:
            
            # Call to Build
            self.builder.build(self.config_obj)