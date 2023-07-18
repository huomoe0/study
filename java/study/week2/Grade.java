package week2;

import java.util.Scanner;
public class Grade {
    public static void main(String[] args) {
        int[] grade = new int[10];

        int ops;
        boolean flag = false;

        do {
            ops = menu();

            if(ops > 1 && ops < 6 && !flag) {
                System.out.println("请先输入成绩");
                continue;
            }

            switch(ops) {
                case 1:grade = input();flag = true;break;
                case 2:
                    System.out.println("平均成绩为: " + getAverage(grade));break;
                case 3:
                    System.out.println("最高分为: " + getHighestGrade(grade));break;
                case 4:
                    System.out.println("最低分为: " + getLowestGrade(grade));break;
                case 5:sort(grade);break;
                case 6:break;
                default:
                    System.out.println("sorry. invalid choose");

            }

        } while (ops != 6);

    }
    public static double getAverage(int[] grade) {
        double sum = 0;
        for(int i = 0;i < 5;i++) {
            sum += grade[i];
        }
        return sum / 5;

    }

    public static int getHighestGrade(int[] grade) {
        int max = grade[0];
        for(int i = 1;i < 5;i++) {
            max = Math.max(max, grade[i]);
        }
        return max;
    }

    public static void sort(int[] grade) {
        for(int i = 0;i < 4;i++) {
            for(int j = 0;j < 4-i;j++) {
                if(grade[j] > grade[j+1]) {
                    int t = grade[j];
                    grade[j] = grade[j+1];
                    grade[j+1] = t;
                }
            }
        }
        System.out.println("排序后成绩分别为: ");
        for(int i = 0;i < 5;i++) {
            System.out.print(grade[i] + " ");
        }
        System.out.println();
    }
    public static int getLowestGrade(int[] grade) {
        int min = grade[0];
        for(int i = 1;i < 5;i++) {
            min = Math.min(min, grade[i]);
        }
        return min;
    }
    public static int menu() {
        System.out.println("1. Enter Student Results\n" +
                "2. Class Average\n" +
                "3. Highest Grade\n" +
                "4. Lowest Grade\n" +
                "5. 排序\n" +
                "6. Exit");
        Scanner input = new Scanner(System.in);
        return input.nextInt();
    }

    public static int[] input() {
        int[] grade = new int[10];
        Scanner sc = new Scanner(System.in);
        for(int i = 0;i < 5;i++) {
            System.out.print("请输入第" + (i+1) + "名同学的成绩: ");
            grade[i] = sc.nextInt();
            while (grade[i] < 0 || grade[i] > 100) {
                System.out.print("请重新输入: ");
                grade[i] = sc.nextInt();
            }
        }
        return grade;
    }
}
