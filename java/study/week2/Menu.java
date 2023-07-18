package week2;

import java.util.Scanner;

public class Menu {
    public static void main(String[] args) {

        int ops = choose();
        while(ops != 5) {
            switch(ops) {
                case 1:createNewAccount();break;
                case 2:deposit();break;
                case 3:withdraw();break;
                case 4:balance();break;
                default:
                    System.out.println("invaild choose");
            }

            ops = choose();
        }

    }

    public static int choose() {
        Scanner input = new Scanner(System.in);
        System.out.println("On opening the menu should look something like this:\n" +
                "WTU Bank – Main Menu\n" +
                "1. Create New Account\n" +
                "2. Deposit\n" +
                "3. Withdraw\n" +
                "4. Balance\n" +
                "5. Exit\n" +
                "Please question.txt your choose(1-5):____");
        int ops = input.nextInt();
        return ops;
    }

    public static void createNewAccount() {

    }

    public static void balance() {

    }
    public static void withdraw() {

    }
    public static void deposit() {

    }
}
