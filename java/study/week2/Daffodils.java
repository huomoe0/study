package week2;

import java.util.Scanner;
public class Daffodils {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int maxNum = (int)Math.pow(10, n);
        int minNum = (int)Math.pow(10, n-1);

        for(int i = minNum;i < maxNum;i++) {
            int sum = getsum(i, n);

            if(sum == i) System.out.println(i);
        }
    }

    public static int getsum(int t, int n) {
        int sum = 0;
        while(t != 0) {
            sum += (int)Math.pow(t % 10, n);
            t /= 10;
        }
        return sum;
    }
}
