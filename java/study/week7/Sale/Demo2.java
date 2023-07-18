package week7.Sale;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Demo2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = 0, num = 0;
        double sum = 0;

        System.out.println("请依次输入商品名称，商品单价，销售数量等信息（每项之间以,分割，当输入0000时结束）");
        String s = sc.nextLine();


        StringBuffer buf = new StringBuffer();

        while (!s.equals("0000")) {
            String[] tmp = s.split("[,，]");
            int n = Integer.parseInt(tmp[1]);
            double price = Double.parseDouble(tmp[2]);

            Sale sale = new Sale(tmp[0], new SimpleDateFormat("yyyyMMdd").format(new Date()) + GenerateSequence.generate(cnt), price, n, n * price);

            buf.append(sale).append("\n");

            cnt++;
            num += n;
            sum += n*price;


            s = sc.nextLine();


        }

        System.out.println("流水号\t\t\t商品名称\t商品数量\t单价\t总价");
        System.out.println("======================================");
        System.out.println(buf);
        System.out.println("总计：销售笔数 " + cnt + "，销售数量 " + num + "，销售金额 " + sum);
    }
}
