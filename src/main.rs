use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("{:?}", args);
    let contents = fs::read_to_string("assets/help.next")
    .expect("Something went wrong reading the file");

    println!("{}", contents);
}