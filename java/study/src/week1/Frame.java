package week1;

import java.util.Scanner;

public class Frame {
    public static void main(String[] args) {
        final double COST_REGULAR = 0.15, COST_FANCY = 0.25, COST_CORNER = 0.35;
        final double COST_COLOUR = 0.1, COST_CARDBOARD = 0.02, COST_GLASS = 0.07;

        Scanner input = new Scanner(System.in);
        System.out.print("请输入长度和宽度：");
        double length = input.nextDouble(), width = input.nextDouble();
        System.out.print("请输入框架类型：（0.regular 1.fancy）");
        int type = input.nextInt();
        System.out.print("请输入颜色：（0. 白色 1.其他颜色）");
        int colour = input.nextInt();
        System.out.print("请输入要装饰的角数：");
        int crownNum = input.nextInt();

        double area = length * width, totalLen = (length + width) * 2;
        double money = area * (COST_CARDBOARD + COST_GLASS) + totalLen * (type == 0 ? COST_REGULAR : COST_FANCY)
                + (colour == 0 ? 0 : COST_COLOUR) * totalLen  + crownNum * COST_CORNER;

        System.out.println("共需要 " + money + "美元");
    }
}
