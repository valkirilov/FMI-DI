package e2016_09;

import java.util.ArrayList;
import java.util.LinkedList;

class Tree {
	
	int value;
	ArrayList<Tree> children;
	
	Tree(int value) {
		this.value = value;
		this.children = new ArrayList<Tree>();
	}
	
	Tree add_child(int value) {
		Tree tree = new Tree(value);
		this.children.add(tree);
		
		return tree;
	}
	
	void print() {
		System.out.print(this.value);
		
		System.out.print("(");
		
		for (int i=0; i < children.size(); i++) {
			children.get(i).print();
			
			if (i+1 != children.size()) {
				System.out.print(",");
			}
		}
		
		System.out.print(")");
	}
}

public class Task2 {

	public static int[] initArray(int size) {
		int array[] = new int[size];
		
		for (int i=0; i < size; i++) {
			array[i] = i + 1;
		}
		
		return array;
	}
	
	public static void printArray(int array[]) {
		for (int i=0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println("");
	}
	
	public static Tree buildTree(int k, int array[]) {
		Tree tree = new Tree(array[0]);
		
		LinkedList<Tree> nodes = new LinkedList<Tree>(); 
		nodes.add(tree);
		
		Tree root = null;
		for (int i=1; i < array.length; ++i) {
			if ((i-1) % k == 0) {
				root = nodes.getFirst();
				nodes.removeFirst();
			}
			
			Tree newNode = root.add_child(array[i]);
			nodes.add(newNode);
		}
		
		return tree;
	}
	
	public static int findDepth(Tree tree, int depth) {
		if (tree.children.size() == 0) {
			return depth;
		}
		
		int maxDepth = depth;
		for (Tree child: tree.children) {
			if (findDepth(child, depth + 1) > maxDepth) {
				maxDepth++;
			}
		}
		
		return maxDepth;
	}
	
	public static void main(String[] args) {
		
		int A[] = initArray(10);
		printArray(A);
		
		Tree tree = buildTree(3, A);
		tree.print();
		
		System.out.println("");
		System.out.println("Depth: " + findDepth(tree, 1));

	}

}

