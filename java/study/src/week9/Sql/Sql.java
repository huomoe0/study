package week9.Sql;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Sql {
    public static ArrayList<String> column = new ArrayList<>();
    public static ArrayList<Student> students = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        File data = new File("src//week9//Sql//data.txt");
        FileReader reader = new FileReader(data);
        BufferedReader bufferedReader = new BufferedReader(reader);


        Load(bufferedReader, column, students);

        System.out.println("请输入查询语句,输入exit退出: ");
        String s = sc.nextLine();
        while (!s.equalsIgnoreCase("exit")) {
            String[] tmp = s.split("\\s+");

            switch (tmp[0]) {
                case "select":select(tmp);break;
                default:break;
            }

            s = sc.nextLine();
        }
    }

    private static void Load(BufferedReader br, ArrayList<String> column, ArrayList<Student> stu) throws IOException {
        String s = br.readLine();
        String[] tmp = s.split("\\s+");
        Collections.addAll(column, tmp);

        br.readLine();

        while ((s = br.readLine()) != null) {
            tmp = s.split("\\s+");
            stu.add(new Student(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], Double.parseDouble(tmp[5])));
        }
    }

    private static void select(String[] s) {

        int wherePos = -1;
        // 确定where的位置
        for(int i = 1;i < s.length;i++) {
            if(s[i].equals("where")) {
                wherePos = i;
                break;
            }
        }
        ArrayList<String> printColumn = new ArrayList<>();
        ArrayList<String> limits = new ArrayList<>();
        if(wherePos == -1) {
            printColumn.addAll(Arrays.asList(s).subList(1, s.length));
        }
        else {
            printColumn.addAll(Arrays.asList(s).subList(1, wherePos));
            limits.addAll(Arrays.asList(s).subList(wherePos+1, s.length));
        }

        for (Student i : students) {
            if(selectCheck(i, limits)) {
                String[] tmp = i.toString().split("\\s+");
                for (String j : printColumn) {
                    int pos = column.indexOf(j);
                    System.out.print(tmp[pos] + " ");
                }
                System.out.println();
            }
        }

    }
    private static boolean selectCheck(Student stu, ArrayList<String> limits) {
        Pattern pattern = Pattern.compile("(\\S+)([<>=])(\\S+)");
        String[] tmp = stu.toString().split("\\s+");

        for(String i : limits) {
            Matcher matcher = pattern.matcher(i);
            if(matcher.find()) {
                int pos = column.indexOf(matcher.group(1));
                String op = matcher.group(2);

                if(matcher.group(1).equals("成绩")) {
                    double a = Double.parseDouble(tmp[pos]);
                    double b = Double.parseDouble(matcher.group(3));
                    if(op.equals("=") && a != b)  return false;
                    if(op.equals("<") && a >= b)    return false;
                    if(op.equals(">") && a <= b)    return false;
                }
                else {
                    switch (matcher.group(2)) {
                        case "=":if(!tmp[pos].equals(matcher.group(3))) return false;break;
                        case "<":if(tmp[pos].compareTo(matcher.group(3)) >= 0) return false;break;
                        case ">":if(tmp[pos].compareTo(matcher.group(3)) <= 0) return false;break;
                        default:break;
                    }
                }

            }
        }

        return true;
    }
}
