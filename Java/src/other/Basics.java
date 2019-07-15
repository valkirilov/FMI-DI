package other;

import java.util.Arrays;

public class Basics {

	public static void print_2d_array(int array[][]) {
		for (int i = 0; i < array.length; i++) {
			System.out.print("[");
			for (int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j] + " ");
			}
			System.out.println("]");
		}
	}

	public static void main(String[] args) {

		int integer = 3;
		double doubleRealNumber = 3.14;
		char character = 'V';
		String string = "Hello world!";

		System.out.println("Integer: " + integer);
		System.out.println("Double: " + doubleRealNumber);
		System.out.println("Character: " + character);
		System.out.println("String: " + string);

		int arrayOfIntegers[] = { 1, 2, 3 };
		int twoDimencionalArrayOfIntegers[][] = { { 1, 2, 3 }, {4, 5, 6 } };

		System.out.println("Array of integers: " + Arrays.toString(arrayOfIntegers));
		print_2d_array(twoDimencionalArrayOfIntegers);

	}

}
