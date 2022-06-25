

class Node_t:
    
    data = None
    childs = []
    
    def __init__(self, data):
        self.data = data
        
    def new_child(self,child):
        self.childs.append(child)
        
    def lenChilds(self):
        return self.childs.count()