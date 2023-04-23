package week8.Regex;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Html {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //String s = sc.nextLine();
        String s = "<html><head><title>欢迎访问武汉纺织大学主页</title></head></html>\n" +
                "<body><img src=’1.jpg’/>\n" +
                "<a href=’1.htm’>首页</a>\n" +
                "<a href=’2.htm’>教务处</a>\n" +
                "<a href=’3.htm’>数计学院</a>\n" +
                "<img src=’2.jpg’/>\n" +
                "<img src=’3.jpg’/>\n" +
                "</body></html>";

        Matcher jpg = Pattern.compile(    "<img src=’(.*)’/>"       ).matcher(s);
        Matcher htm = Pattern.compile(    "<a\\s+href=’(.*)’>(.*)</a>"       , Pattern.CASE_INSENSITIVE).matcher(s);
        Matcher title = Pattern.compile(    "<title>(.*)</title>"       ).matcher(s);
        int count_jpg = 0, count_htm = 0;
        ArrayList<String> jpgList = new ArrayList<>();
        ArrayList<String> htmList = new ArrayList<>();

        if(title.find())
            System.out.println("网页标题：" + title.group(1));

        while (jpg.find())  {
            count_jpg++;
            jpgList.add(jpg.group(1));
        }

        System.out.println("网页中共 " + count_jpg +" 个图片，");

        System.out.print("文件名为");
        for(String i : jpgList) System.out.print(" " + i);
        System.out.println();

        while (htm.find())  {
            count_htm++;
            htmList.add(htm.group(2) + " " + htm.group(1));
        }

        System.out.println("网页中包含 " + count_htm + " 个超链接，");

        System.out.println("超链接信息如下： \n名称 地址");
        for(String i : htmList) System.out.println(i);
    }

}
