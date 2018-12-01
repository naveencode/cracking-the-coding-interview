import java.util.Scanner;

class IsPermutation {
    public static void main(String args[]) {
        int[] count = new int[256];
        Scanner scan = new Scanner(System.in);
        String s1 = scan.nextLine();
        String s2 = scan.nextLine();
        scan.close();

        if (s1.length() != s2.length()) {
            System.out.println("Not permutations");
            return;
        }

        for (int i=0; i<s1.length(); i++) {
            count[s1.charAt(i)]++;
        }

        for (int i=0; i<s2.length(); i++) {
            count[s2.charAt(i)]--;
            if (count[s2.charAt(i)] < 0) {
                System.out.println("Not permutations");
                return;
            }
        }

        System.out.println("Permutations");


    }
}