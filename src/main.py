######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 07/01/2022
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

@main.command()
@click.argument('name', required=True, type=str)
@click.option('--build_dir', required=False, type=str)
@click.option('--name_build', required=False, type=str)
@click.option('--build_system_exe', required=False, type=str)
@click.option('--c_compiler', required=False, type=str)
@click.option('--cxx_compiler', required=False, type=str)
@click.option('--build_system', required=False, type=str)
def create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system):
    create_next.create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system)

@main.command()
def build():
    build_next.build()

@main.command()
def run():
    run_next.run()

@main.command()
def clean():
    clean_next.clean()

#if __name__ == "__main__":
main()
