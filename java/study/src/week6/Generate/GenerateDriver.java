package week6.Generate;

import java.util.Scanner;

public class GenerateDriver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String cls = sc.nextLine();
        String var = sc.nextLine();

        System.out.println(Generate.generate(cls, var));


    }
}
