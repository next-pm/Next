# Remove commnets of String
import re
def stripComments(code):
    code = str(code)
    return re.sub(r'(?m)^ *#.*\n?', '', code)

def countWord(text: str, separator:str=" "):
    text_list = text.split(sep=separator)
    return len(text_list)