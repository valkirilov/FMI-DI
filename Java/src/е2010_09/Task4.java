package е2010_09;

class Node {
	Node next;
	Node prev;
	char data;
	
	Node(char value) {
		next = null;
		prev = null;
		data = value;
	}
}

class Stack {
	
	Node first;
	Node last;
	
	Stack() {
		first = null;
		last = null;
	}
	
	void push(char value) {
		Node node = new Node(value);
		appendElement(node);
	}
	
	char pop() {
		Node node = removeLastElement();
		if (node == null) {
			return ' ';
		}
		
		return node.data;
	}
	
	void appendElement(Node node) {
		if (last == null) {
			first = node;
			last = node;
		}
		else {
			last.next = node;
			node.prev = last;
			last = node;
		}
	}
	
	Node removeLastElement() {
		if (isEmpty()) {
			return null;
		}
		
		if (last == first) {
			Node node = last;
			
			last = null;
			first = null;
			
			return node;
		}
		
		Node node = last;
		last = node.prev;
		last.next = null;
		
		node.prev = null;
		node.next = null;
		
		return node;
	}
	
	boolean isEmpty() {
		return last == null;
	}
	
}

public class Task4 {
	
	public static boolean validateBracketsString(String input) {
		Stack stack = new Stack();
		
		for (int i=0; i < input.length(); ++i) {
			if (input.charAt(i) == '(') {
				stack.push(input.charAt(i));
			}
			else if (input.charAt(i) == ')') {
				if (stack.pop() != '(') {
					return false;
				}
			}
		}
		
		return stack.isEmpty();
	}

	public static void main(String[] args) {
		
//		Stack stack = new Stack();
//		
//		stack.push('(');
//		stack.push(')');
//		
//		System.out.println("POP: " + stack.pop());
//		System.out.println("POP: " + stack.pop());
//		System.out.println("POP: " + stack.pop());

		String validInput1 = "((()))";
	    String validInput2 = "()()()";
	    String validInput3 = "(()())((()()))";

	    String invalidInput1 = "((()";
	    String invalidInput2 = "(((";
	    String invalidInput3 = ")))";
	    String invalidInput4 = ")()()(";
	    String invalidInput5 = "()())";
		
		System.out.println(validInput1 + " -> " + validateBracketsString(validInput1));
		System.out.println(validInput2 + " -> " + validateBracketsString(validInput2));
		System.out.println(validInput3 + " -> " + validateBracketsString(validInput3));
		
		System.out.println(invalidInput1 + " -> " + validateBracketsString(invalidInput1));
		System.out.println(invalidInput2 + " -> " + validateBracketsString(invalidInput2));
		System.out.println(invalidInput3 + " -> " + validateBracketsString(invalidInput3));
		System.out.println(invalidInput4 + " -> " + validateBracketsString(invalidInput4));
		System.out.println(invalidInput5 + " -> " + validateBracketsString(invalidInput5));
		
	}

}
