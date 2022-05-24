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


        
from colorama  import Fore
from colorama import Style
from colorama import Back
from colorama import init

OUTPUT_ACTIVATED = True

# For colorama in Windows load ANSI
system = platform.system()
if system != 'Linux':
    init(convert = True)

def message_error(messageStr: str):
    if OUTPUT_ACTIVATED == True : print(f'{Fore.RED}{Style.BRIGHT} <<ERROR>> {Style.RESET_ALL}' + messageStr)
    
def message_warning(messageStr: str):
    if OUTPUT_ACTIVATED == True : print(f'{Fore.YELLOW}{Style.BRIGHT} <<WARNING>> {Style.RESET_ALL}' + messageStr)
    
def message_successful(messageStr: str):
    if OUTPUT_ACTIVATED == True : print(f'{Fore.LIGHTGREEN_EX}{Style.BRIGHT} <<SUCCESSFUL>> {Style.RESET_ALL}' + messageStr)
    
def message_info(messageStr: str):
    if OUTPUT_ACTIVATED == True : print(f'{Fore.WHITE}{Style.BRIGHT} <<INFO>> {Style.RESET_ALL}' + messageStr)
    
def message_waiting(messageStr: str):
    if OUTPUT_ACTIVATED == True : print(f'{Fore.BLUE}{Style.BRIGHT} <<WAITING...>> {Style.RESET_ALL}' + messageStr)
    
def absoluteFilePaths(directory):
    for dirpath,_,filenames in os.walk(directory):
        for f in filenames:
            yield os.path.abspath(os.path.join(dirpath, f))
            

import ruamel.yaml
from io import StringIO
from pathlib import Path

# setup loader (basically options)
yaml = ruamel.yaml.YAML()
yaml.allow_duplicate_keys = True
# show null
def represent_of_null(self, data):
    return self.represent_scalar(u'tag:yaml.org,2002:null', u'null')
yaml.representer.add_representer(type(None), represent_of_null)

# o->s
def object_to_yaml_str(obj, options=None):
    if options == None: options = {}
    string_stream = StringIO()
    yaml.dump(obj, string_stream, **options)
    output_str = string_stream.getvalue()
    string_stream.close()
    return output_str

# s->o
def yaml_string_to_object(string, options=None):
    if options == None: options = {}
    return yaml.load(string, **options)

# f->o
def yaml_file_to_object(file_path, options=None):
    if options == None: options = {}
    as_path_object = Path(file_path)
    return yaml.load(as_path_object, **options)

# o->f
def object_to_yaml_file(obj, file_path, options=None):
    if options == None: options = {}
    as_path_object = Path(Path(file_path))
    with as_path_object.open('w') as output_file:
        return yaml.dump(obj, output_file, **options)

# Remove commnets of String
import re
def stripComments(code):
    code = str(code)
    return re.sub(r'(?m)^ *#.*\n?', '', code)