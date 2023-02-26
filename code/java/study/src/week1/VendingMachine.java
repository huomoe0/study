package week1;

import java.util.Scanner;

public class VendingMachine {
    public static void main(String[] args) {
        final int[] COINS = {50, 20, 10, 5, 2, 1};
        Scanner input = new Scanner(System.in);

        System.out.print("请输入金额：");
        double money = input.nextDouble();
        int coinsmoney = (int)(money * 100);

        if (coinsmoney >= 100)System.out.println("$" + coinsmoney / 100);
        coinsmoney %= 100;

        for (int coin : COINS) {
            int num = coinsmoney / coin;
            if(num > 0)
                System.out.println(num + " x " + coin + "c");
            coinsmoney -= num * coin;
        }
    }

}
