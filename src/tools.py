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

# Packages Systems
import os
import platform

# Packages Dependencies
import ruamel.yaml

def remplace_in_file(file_location, old_text, new_text):
    try:
        #input file
        fin = open(file_location, "rt")

        old_data = fin.readlines()

        new_data = ""

        #for each line in the input file
        for line in old_data:
            #read replace the string and write to output file
            new_data += line.replace(old_text, new_text)
        #close input and output files
        fin.close()

        #output file to write the result to
        fout = open(file_location, "wt")

        #Write new data
        fout.write(new_data)

        #Close output file
        fout.close()
    except BaseException as err:
        print("Not remplace " + old_text + " in " + file_location)
        print(f"Unexpected {err=}, {type(err)=}")
        
def load_env():
    """load the environment variables in the current execution
    """
    try:
        env_yaml = ''
        
        file = ''
        
        _data = {}
        
        #Get Home Dir
        system = platform.system()
        
        if system == 'Linux':
            print('Linux System')
            home_dir = os.environ['HOME']
        else:
            print('Windows System')
            home_dir = os.environ['LOCALAPPDATA']
        
        next_env_file_dir = home_dir + '/.next/env.yaml'
        
        env_yaml = ruamel.yaml.YAML()
        
        env_yaml.preserve_quotes = True

        #Read the file
        file = open( next_env_file_dir, "r")

        #Safe the data
        _data = env_yaml.load(file)
        
        #Load the environment variables in the current execution
        for x in _data:
            print(x + '= ' + _data[x])
            os.environ[x] = _data[x]
        
    except:
        
        print("Error at Load Env")
        
from colorama  import Fore
from colorama import Style
from colorama import Back
from colorama import init

# For colorama in Windows load ANSI
system = platform.system()
if system != 'Linux':
    init(convert = True)

def message_error(str):
    print(f'{Fore.RED}{Style.BRIGHT} <<ERROR>> {Style.RESET_ALL}' + str)
    
def message_warning(str):
    print(f'{Fore.YELLOW}{Style.BRIGHT} <<WARNING>> {Style.RESET_ALL}' + str)
    
def message_successful(str):
    print(f'{Fore.LIGHTGREEN_EX}{Style.BRIGHT} <<SUCCESSFUL>> {Style.RESET_ALL}' + str)
    
def message_info(str):
    print(f'{Fore.WHITE}{Style.BRIGHT} <<INFO>> {Style.RESET_ALL}' + str)
    
def message_waiting(str):
    print(f'{Fore.BLUE}{Style.BRIGHT} <<WAITING...>> {Style.RESET_ALL}' + str)
    
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
    #print("##################################")
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