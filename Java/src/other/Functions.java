package other;

public class Functions {

	public static long factoriel(int number) {
		long result = 1;

		for (int i=2; i<=number; i++) {
			result *= i;
		}

		return result;
	}

	public static int fibonachi(int number) {
		if (number == 0 || number == 1) {
			return 1;
		}

		return fibonachi(number - 1) + fibonachi(number - 2);
	}

	public static double calculateDistance(Point a, Point b) {
		int dx = b.getX() - a.getX();
		int dy = b.getY() - a.getY();

		return Math.sqrt(Math.pow(dx, 2) + Math.pow(dy, 2));
	}

	public static void main(String[] args) {

		System.out.println("1! = " + factoriel(1));
		System.out.println("2! = " + factoriel(2));
		System.out.println("3! = " + factoriel(3));
		System.out.println("5! = " + factoriel(5));
		System.out.println("13! = " + factoriel(13));

		System.out.println("Fibonachi of 0 = " + fibonachi(0));
		System.out.println("Fibonachi of 1 = " + fibonachi(1));
		System.out.println("Fibonachi of 2 = " + fibonachi(2));
		System.out.println("Fibonachi of 3 = " + fibonachi(3));
		System.out.println("Fibonachi of 5 = " + fibonachi(5));

		Point O = new Point();
		Point A = new Point(1, 1);
		Point B = new Point(3, 0);

		System.out.println("The distance between 0(0, 0) and O(0, 0) = " + calculateDistance(O, O));
		System.out.println("The distance between 0(0, 0) and A(1, 1) = " + calculateDistance(O, A));
		System.out.println("The distance between A(1, 3) and B(3, 0) = " + calculateDistance(A, B));

	}

}
