
import java.util.Arrays;
class Main {

	public static void main(String... args){
				
		if(args.length != 0)System.out.println(Arrays.toString(args));
	
	}


	public native int getResult();

	public native void print();	
}
