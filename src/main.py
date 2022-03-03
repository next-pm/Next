######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 08/01/2022
### license = PSF
### version = 3.0.0 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

# Packages Dependencies
import click

#Local Packages
import info_next
import version_next
import create_next
import build_next
import run_next
import clean_next
import config_env
import config_get
import config_set
import config_add
import tools

### Update 7/01/2022
### ✓ create                   Create a new Next project.
### ✓ build                    Build this project
### ✓ run                      Run your app
### ✓ clean                    Remove the binaries
### × doctor                   Show information about the installed tooling.
### ✓ version                  List Next and plugins version.
### × install                  Install a Plugin
### × upgrade                  Upgrade a Plugin or Next
### ✓ info                    Print Info verbose of Next

@click.group()
def main():
    tools.load_env()
    pass

@main.command('info', short_help='view info the Next')
def info():
    info_next.info()

@main.command('version', short_help='view version the Next')
@click.option('--all',default=0, required=False, help='view version of all NextPackages installed <default=0>')
def version(all):
    # alone Next version
    if(all == 0):
        version_next.version()
    # all NextPackages
    elif(all == 1):
        version_next.version_all()
    # Error Not show any version
    else:
        exit()

@main.command('check_env', short_help='check env the NextPackages')
def check_env():
    config_env.check_env()

@main.command('create', short_help='Create a new project of Next', options_metavar='<name> <options>')
@click.argument('name', required=True, type=str, metavar='')
@click.option('--build_dir', required=False, type=str, help='Select Build Dir')
@click.option('--name_build', required=False, type=str, help='Select name of build')
@click.option('--build_system_exe', required=False, type=str, help='Select Build System executable')
@click.option('--c_compiler', required=False, type=str, help='Select C Compiler')
@click.option('--cxx_compiler', required=False, type=str, help='Select C++ Compiler')
@click.option('--build_system', required=False, type=str, help='Select Build System')
@click.option('--type_project', required=False, type=str, help='Select Type Project')
def create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system, type_project):
    create_next.create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system, type_project)

@main.command('build', short_help='Build a project of Next')
def build():
    build_next.build()

@main.command('run', short_help='Run a project of Next')
def run():
    run_next.run()

@main.command('clean', short_help='Clean a project of Next')
def clean():
    clean_next.clean()

@main.command('get', short_help='Get property of current Next Project')
@click.option('--property',default="name", required=True, help='Select property of current Next Project <default=name>')
def get(property):
    value_of_property = config_get.get(property)
    if isinstance(value_of_property, list):
        value_in_str = ''
        value_in_str += '['
        for x in value_of_property:
            value_in_str += x + ','
        len_value = len(value_in_str)
        value_in_str = value_in_str[:len_value-1]
        value_in_str += ']' 
    else:
        value_in_str = value_of_property
    
    print(property + ": " + value_in_str)

@main.command('set', short_help='Set property of current Next Project')
@click.option('--property',default="name", required=True, help='Select property of current Next Project <default=name>')
@click.option('--value',default="name", required=True, help='Select value of current Next Project <default=null>')
def set(property, value):
    config_set.set(property, value)


@main.command('add', short_help='Add to property of current Next Project')
@click.option('--property',default="name", required=True, help='Select property of current Next Project <default=name>')
@click.option('--value',default="name", required=True, help='Select value of current Next Project <default=null>')
def add(property, value):
    config_add.add(property, value)
        

#if __name__ == "__main__":
main()
