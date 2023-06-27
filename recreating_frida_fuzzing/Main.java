public class Main {
	private native static void fuzzMe(String byteArrray, int length);

	public static void main(String[] args) {
        	System.loadLibrary("Main");

		// System.out.println("Our input data: " + args[0]);
		// String inputString = "Quarksl4bfuzzMe?"; // Replaced ! with ?
		fuzzMe(args[0], args[0].length());

        	// fuzzMe(inputString, inputString.length());
    }

}
