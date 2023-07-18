package week7.Sale;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {

        System.out.println("请输入最后一个序号");
        Scanner sc = new Scanner(System.in);
        int last = sc.nextInt();
        String newNo = new SimpleDateFormat("yyyyMMdd").format(new Date()) + GenerateSequence.generate(last);
        System.out.println("下一个流水号为: " + newNo);


    }
}
