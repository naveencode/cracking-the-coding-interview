import java.util.Scanner;
import java.util.Arrays;

// Check if string has all unique characters.
class IsUnique1 {
    public static void main(String args[]) {
        // for (int i : count) {
            //     System.out.println(i);
            // }
        
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();
        
        if (input.length() > 256) {
            System.out.println("Not unique!");
            return;
        }
            
        boolean[] found = new boolean[256];
        // System.out.println("You entered " + input);

        for (int i=0; i<input.length(); i++) {
            int val = count[input.charAt(i)];
            if (found[val]) {
                System.out.println("Not unique!");
                return;
            }
            found[val] = true;
        }
        System.out.println("Unique");
    }
}

class IsUnique2{
    public static void main(String args[]) {
        // Assuming only char from 'a' to 'z'

        // Bit vector counter
        // Integers in Java are 32 bit
        int counter = 0;

        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        for (int i=0; i<input.length(); i++) {
            int val = input.charAt(i) - 'a';
            if ((counter & (1<<val)) > 0) {
                System.out.println("Not Unique");
                return;
            }
            counter = counter | (1 << val);
        }
        System.out.println("Not Unique");
    }
}

class IsUnique{
    public static void main(String args[]) {
        // int[] count = new int[256];
        // for (int i : count) {
        //     System.out.println(i);
        // }

        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        // System.out.println("You entered " + input);
        char[] input_arr = input.toCharArray();
        Arrays.sort(input_arr);
        String sorted_string = new String(input_arr);

        for (int i=0; i<sorted_string.length()-1; i++) {
            if (sorted_string.charAt(i) == sorted_string.charAt(i+1)) {
                System.out.println("Not Unique");
                return;
            }
        }
        System.out.println("Unique");

        // System.out.println("Sorted string is " + new String(input_arr));

        
    }
}