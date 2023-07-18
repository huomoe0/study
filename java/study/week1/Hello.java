package week1;

import java.util.Scanner;

public class Hello {
    // 有若干个method 方法，有且只有一个main方法
    public static void main(String[] args) {
        // 1. 定义变量： 名字， 类型

        final float MANAGER_COMMISSION = 0.12f; // 常量定义：全大写，单词间以下划线分隔
        final float SITE_COMMISSION = 0.03f;
        
        String songTitle;
        float price;
        int copies;

        float totalRevence;
        float managerRevence;
        float siteRevence;



        // 2.通过键盘输入给某些变量赋值
        Scanner input = new Scanner(System.in);
        System.out.printf("请输入歌曲名称");
        songTitle = input.nextLine();
        System.out.printf("请输入歌曲单价");
        price = input.nextFloat();
        System.out.printf("请输入下载份数");
        copies = input.nextInt();

        // 3.通过计算赋值给某些变量
        totalRevence = copies * price;
        managerRevence = totalRevence * MANAGER_COMMISSION;
        siteRevence = totalRevence * SITE_COMMISSION;


        // 4.输出某些变量到控制台中
        System.out.println("歌曲名称" + songTitle);
        
        System.out.println("总利润" + totalRevence);
        System.out.println("经纪人利润" + managerRevence);
        System.out.println("站点利润" + siteRevence);

        }

}
