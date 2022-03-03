######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 02/03/2022
### license = PSF
### version = 3.0.2
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

# Packages Systems
import os
import shutil
import platform

# Packages Dependencies
import click
import ruamel.yaml

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
            home_dir = os.environ['HOME']
        else:
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
            os.environ[x] = _data[x]
        
    except:
        
        print("Error at Load Env")

def remplace_in_file(file_location, old_text, new_text):
    """replace selected text in a file

    Args:
        file_location (str): location of the file in which the string will be replaced
        old_text (str): old text
        new_text (str): new text
    """
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

def create_env_file(next_dir_custom, next_packages_dir_custom):
    
    this_dir = os.getcwd()
    
    env_example_dir = this_dir + '/assets/.next'
    
    #Get Home Dir
    system = platform.system()
    
    if system == 'Linux':
        home_dir = os.environ['HOME']
        programs_files = os.environ['HOME']
    else:
        home_dir = os.environ['LOCALAPPDATA']
        programs_files = os.environ['PROGRAMFILES']
    
    next_env_dir = home_dir + '/.next'
    
    
    print('this_dir: ' + this_dir)
    print('env_example_dir: ' + env_example_dir)
    print('home_dir: ' + home_dir)
    print('next_env_dir: ' + next_env_dir)
    print('programs_files: ' + programs_files)
    
    #ingreso en home_dir
    os.chdir(home_dir)
    
    #creo .next
    os.mkdir('.next')
    
    #copio env_yaml
    shutil.copytree(env_example_dir, '.next', dirs_exist_ok=True)
    
    #remplazo en env_yaml
    if next_dir_custom:
        remplace_in_file(next_env_dir + "/env.yaml", "__PROGRAMFILES_NEXT_DIR__", next_dir_custom)
    else:
        remplace_in_file(next_env_dir + "/env.yaml", "__PROGRAMFILES_NEXT_DIR__", programs_files)
    
    if next_packages_dir_custom:
        remplace_in_file(next_env_dir + "/env.yaml", "__PROGRAMFILES_NEXT_PACKAGES_DIR__", next_packages_dir_custom)
    else:
        remplace_in_file(next_env_dir + "/env.yaml", "__PROGRAMFILES_NEXT_PACKAGES_DIR__", programs_files)
    
def clean_env_file():
    
    home_dir = os.environ['LOCALAPPDATA']
    
    next_env_dir = home_dir + '/.next'
    
    try:
        shutil.rmtree(next_env_dir)
        
    except OSError as exc:
        print(exc)
        exit()
        
def install_next(next_dir_custom, next_packages_dir_custom):
    
    this_dir = os.getcwd()
    
    #creamos las variables de entorno
    create_env_file(next_dir_custom, next_packages_dir_custom)
    
    #cargamos las varibles de entorno
    load_env()
    
    #TODO: Remove TEST
    next_dir = os.environ['NEXT_DIR_TEST']
    
    next_packages_dir = os.environ['NEXT_PACKAGES_DIR_TEST']
    
    #creamos los directorios de las variables de entorno
    if(not os.path.exists(next_dir)):
        print('NEXT_DIR: ' + next_dir)
        os.mkdir(next_dir)
    
    if(not os.path.exists(next_packages_dir)):
        print('NEXT_PACKAGES_DIR: ' + next_packages_dir)
        os.mkdir(next_packages_dir)
        
    #copiamos Next/assets a NEXT_DIR/assets
    #copio env_yaml
    shutil.copytree(this_dir + '/assets', next_dir + '/assets', dirs_exist_ok=True)

@click.group()
def main():
    pass
    
@main.command('create_env', short_help='load env the NextPackages')
@click.option('--next_dir_custom', required=False, type=str, help='Select NEXT_DIR')
@click.option('--next_packages_dir_custom', required=False, type=str, help='Select NEXT_PACKAGES_DIR')
def create_env(next_dir_custom, next_packages_dir_custom):
    create_env_file(next_dir_custom, next_packages_dir_custom)
    
@main.command('clean_env', short_help='load env the NextPackages')
def clean_env():
    clean_env_file()
    
@main.command('install', short_help='load env the NextPackages')
@click.option('--next_dir_custom', required=False, type=str, help='Select NEXT_DIR')
@click.option('--next_packages_dir_custom', required=False, type=str, help='Select NEXT_PACKAGES_DIR')
def install(next_dir_custom, next_packages_dir_custom):
    install_next(next_dir_custom, next_packages_dir_custom)
    
@main.command('test', short_help='load env the NextPackages')
def test():
    programs_files = os.environ
    print(programs_files)

#if __name__ == "__main__":
main()
