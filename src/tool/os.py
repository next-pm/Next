import src.tool.messages as MESSAGES_tools
import os

def mkdirDir(dir:str):
    
    try:
        # Try create build_dir
        os.mkdir(dir)
        
        # Message(Successful): The dir directory was created
        MESSAGES_tools.message_successful('Create : ' + dir)
        
    except:
        # Message(Waiting): The dir folder already exists
        MESSAGES_tools.message_warning("Warning " + dir +  " folder already exists")
                