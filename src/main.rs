/*
#[warn(dead_code)]
mod comman_base;

use comman_base::CommandBase;

use std::process::Command;

struct LineCommand{
    command: &'static str,
    args: Vec<&'static str>
}

impl LineCommand{
    fn new(command: &'static str, args: Vec<&'static str>) -> LineCommand {
	    LineCommand {
            command: command,
            args: args,
	    }
	}
}

impl comman_base::CommandBase for LineCommand{
    fn execute(&self) {
        println!("Estoy haciendo el comando {} con los args {:?}", self.command, self.args);
        Command::new(self.command)
        .args(self.args.to_vec())
        .output()
        .expect("failed to execute process")..;
    }
}

struct ReadFileCommand{
    file_name: &'static str,
}

impl comman_base::CommandBase for ReadFileCommand{
    fn execute(&self) {
        println!("Estoy leyendo un archivo {}", self.file_name);
    }
}

struct ManagerCommand{
    stack: Vec<Box<dyn comman_base::CommandBase>>,
}

impl ManagerCommand {
	fn new() -> ManagerCommand {
	    ManagerCommand {
	        stack: Vec::new(),
	    }
	}
	fn append(&mut self, cmd: Box<dyn comman_base::CommandBase>) {
	    self.stack.push(cmd);
	}
	fn undo(&mut self) {
	    self.stack.pop();
	}
	fn clear(&mut self) {
	    self.stack.clear();
	}
}

fn main() {
    let a = LineCommand{command: "touch", args: vec!["text.txt"]};
    let b = ReadFileCommand{file_name: "text.txt", };
    a.execute(); 
    b.execute();

    let mut man = ManagerCommand::new();
    man.append(cmd: Box::new(LineCommand::new(command: "touch", args: vec!["text.txt"])));
}
*/
mod comman_base;
use comman_base::CommandBase;
mod manager_command;
use manager_command::ManagerCommand;

struct MyCommand{
	command: &'static str,
    args: Vec<&'static str>
}

impl MyCommand {
	fn new(command: &'static str, args: Vec<&'static str>) -> MyCommand {
	    MyCommand {
			command: command,
			args: args
	    }
	}
}

impl comman_base::CommandBase for MyCommand {
	fn execute(&self) {
	    println!("{} {:?}", self.command, self.args);
	}
}

fn main() {
    let mut history = ManagerCommand::new();
    
    let cmd3 = Box::new(MyCommand::new("ls", vec!["text.txt"]));
    let cmd4 = Box::new(MyCommand::new("pwd", vec![]));
    
    history.append(cmd3);
    history.append(cmd4);
	println!("----------");
	history.execute();
	println!();
	println!("---undo---");
	history.undo();
	history.execute();
	println!();
	println!("---clear---");
	history.clear();
	history.execute();
}