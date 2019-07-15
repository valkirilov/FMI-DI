package e2010_07;

import java.util.*;

public class Task4 {

	public static int findDuplicates(List<Integer> list) {
		int duplicates = 0;
		
		int last = 0;
		int lastOccurancies = 0;
		
		for (Integer item: list) {
		    if (lastOccurancies == 0) {
		    	last = item;
		    	lastOccurancies = 1;
		    }
		    else if (item == last) {
		    	lastOccurancies++;
		    }
		    else if (item != last) {
		    	if (lastOccurancies > 1) {
		    		duplicates++;
		    	}
		    	
		    	last = item;
		    	lastOccurancies = 1;
		    }
		}
		
		// Check the last element
		if (lastOccurancies > 1) {
    		duplicates++;
    	}
		
		return duplicates;
	}
	
	public static void main(String[] args) {
		
		List<Integer> list = new ArrayList<Integer>();
		list.add(1);
		list.add(2);
		list.add(2);
		list.add(3);
		list.add(3);
		list.add(3);
		
		System.out.println("Number of duplicates: " + findDuplicates(list));
		
		list.add(4);
		
		System.out.println("Number of duplicates: " + findDuplicates(list));
		
		list.add(5);
		
		System.out.println("Number of duplicates: " + findDuplicates(list));
		
		list.add(4);
		list.add(4);
		
		System.out.println("Number of duplicates: " + findDuplicates(list));

	}

}
