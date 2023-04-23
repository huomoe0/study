package week4.System;

import java.util.Scanner;

public class SubjectEnrolmentDriver {
    private static SubjectEnrolment se;
    private static int count;
    private static final int max = 100;
    private static boolean flag = false;


    public static void main(String[] args) {

        int c;
        do {
            c = menu();
            if(c != 1 && !flag) {
                System.out.println("请先创建课程");
                continue;
            }

            switch (c) {
                case 1:create();break;
                case 2:add();break;
                case 3:del();break;
                case 4:print();break;
                case 5:break;
                default:
                    System.out.println("请重新输入");
            }


        } while (c != 5);
    }

    public static void print() {
        System.out.println(se);

    }
    public static void create() {
        if(se != null) {
            System.out.println("无需重复创建");
            return;
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入学年：");
        int year = sc.nextInt();
        System.out.println("请输入学期：（1-2）");
        int semester = sc.nextInt();
        System.out.println("请输入课程号：");
        String subjectID = sc.next();

        System.out.println("请输入课程名称：");
        String subjectName = sc.next();

        Subject subject = new Subject(subjectID, subjectName);

        se = new SubjectEnrolment(semester, year, subject,new Student[max]);
        flag = true;

    }
    public static void add() {
        if(count >= max) System.out.println("人数已满");

        Scanner sc = new Scanner(System.in);

        System.out.println("请输入学号：");
        String stuId = sc.next();
        System.out.println("请输入姓名：");
        String name = sc.next();
        System.out.println("请输入班级：");
        String stuClass = sc.next();

        Student student = new Student(stuId, name, stuClass);

        se.getStu()[count] = student;
        count++;
        System.out.println("学生添加成功，还有" + (max-count) + "个空位");
    }
    public static void del() {
        Scanner sc = new Scanner(System.in);


        System.out.println("输入要退选的学号：");
        String stuID = sc.next();
        int index = indexOf(stuID);

        if(index != -1) {
            System.out.println("确定要退选吗（1-0）");
            int c = sc.nextInt();
            if(c == 0) return;

            Student[] stu = se.getStu();
            for(int i = index;i < stu.length && stu[i] != null;i ++) {
                stu[i] = stu[i+1];
            }
            count--;
            System.out.println("退选成功");
        }
        else {
            System.out.println("未找到该学号");
        }
    }
    public static int indexOf(String stuID) {
        Student[] stu = se.getStu();
        for (int i = 0;i < stu.length && stu[i] != null;i ++) {
            if(stuID.equals(stu[i].getStudentID())) return i;
        }
        return -1;
    }

    public static int menu() {
        System.out.println("1.Create Subject");
        System.out.println("2.Add student");
        System.out.println("3.delete Student");
        System.out.println("4.print");
        System.out.println("5.exit");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
}
