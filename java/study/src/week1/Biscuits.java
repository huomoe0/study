package week1;

import java.util.Scanner;

public class Biscuits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        final int BOXMAXN = 24, CONTAINERMAXN = 75;
        System.out.print("请输入饼干数量：");
        int biscuitsCount = input.nextInt();

        int boxCount = biscuitsCount / BOXMAXN;
        int biscuitsLeftover = biscuitsCount % BOXMAXN;

        int containerCount = boxCount / CONTAINERMAXN;
        int boxLeftover = boxCount % CONTAINERMAXN;

        System.out.println("饼干剩余：" + biscuitsLeftover);
        System.out.println("盒子数量：" + boxCount);

        System.out.println("盒子剩余：" + boxLeftover);
        System.out.println("箱子数量：" + containerCount);

    }
}
