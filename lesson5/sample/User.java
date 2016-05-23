package sample;

public class User {
	private String name;
	private int age;

	public User(String name, int age){

	this.name = name;
	this.age = age;
	}

	public String toString(){
		return String.format("User name %s age %d",this.name,this.age);
	}
}

