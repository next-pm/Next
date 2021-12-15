# Next info
_info_string = """
Manage your C/C++ Proyect development.
Common commands:
  next create <output directory>
    Create a new C++ project in the specified directory.
  next run [options]
    Run your C/C++ Proyect application.
Usage: next <command> [arguments]
Global options:
--help                  Print this usage information.
info                    Print Info verbose of Next
Available commands:
  create                   Create a new Next project.
  build                    Build this project
  run                      Run your app
  clean                    Remove the binaries
  doctor                   Show information about the installed tooling.
  version                  List Next and plugins version.
  install                  Install a Plugin
  upgrade                  Upgrade a Plugin or Next
"""

def info():
    print(_info_string)