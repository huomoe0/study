package week6.Password;

import java.util.Scanner;

public class PasswordDriver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String pass = sc.nextLine();

        Password P = new Password();

        String info = P.check(pass);
        if(info.equals("")) {
            System.out.println("密码有效");
        }
        else {
            System.out.println("密码无效，原因如下");
            System.out.println(info);
        }
    }
}
