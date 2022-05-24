# Packages Systems
import os
import platform

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