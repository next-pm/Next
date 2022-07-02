######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 02/06/2022
### license = PSF
### version = 3.3.1 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

class Node_t:
    
    data = None
    childs = []
    
    def __init__(self, data):
        self.data = data
        
    def new_child(self,child):
        self.childs.append(child)
        
    def lenChilds(self):
        return self.childs.count()