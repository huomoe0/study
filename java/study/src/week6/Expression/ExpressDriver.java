package week6.Expression;

import java.util.Scanner;

public class ExpressDriver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        double result = Express.cal(str);

        System.out.println(str + "=" + result);
        
    }
}
