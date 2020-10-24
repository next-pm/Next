//mod comman_base;
//use comman_base::CommandBase;

mod ./comman_base;

pub struct ManagerCommand {
	stack: Vec<Box<dyn CommandBase>>,
}

impl ManagerCommand {
	fn new() -> ManagerCommand {
	    ManagerCommand {
	        stack: Vec::new(),
	    }
	}
	fn append(&mut self, cmd: Box<dyn CommandBase>) {
	    self.stack.push(cmd);
	}
	fn undo(&mut self) {
	    self.stack.pop();
	}
	fn clear(&mut self) {
	    self.stack.clear();
	}
}