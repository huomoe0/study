package week4.ClassList;

import java.util.Scanner;

public class ClassListDriver {
    private static ClassList[] list = null;
    private static int count = 0;

    public static void main(String[] args) {

        list = new ClassList[5];

        int c = menu();
        while (c != 3) {
         switch (c) {
             case 1:create();break;
             case 2:print();break;
             default:
                 System.out.println("请重新选择");
         }
         c = menu();
        }
        System.out.println("程序结束");
    }

    public static int menu() {
        System.out.println("学生选课系统");
        System.out.println("1.Create Attendance List\n2.Print Attendance List\n3.Exit");
        System.out.println("请选择(1-3)");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static void create() {
        if(count >= 2) {
            System.out.println("无需创建");
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

        System.out.println("请输入学生1编号：");
        String studentID1 = sc.next();
        System.out.println("请输入学生1姓名：");
        String studentName1 = sc.next();
        System.out.println("请输入学生1班级：");
        String studentClass1 = sc.next();

        System.out.println("请输入学生2编号：");
        String studentID2 = sc.next();
        System.out.println("请输入学生2姓名：");
        String studentName2 = sc.next();
        System.out.println("请输入学生2班级：");
        String studentClass2 = sc.next();

        Student s1 = new Student(studentID1, studentName1, studentClass1);
        Student s2 = new Student(studentID2, studentName2, studentClass2);
        Subject subject = new Subject(subjectID, subjectName);
        list[count] = new ClassList(semester, year, subject, s1, s2);
        count++;
    }
    public static void print() {
        if(count == 0) System.out.println("请先添加课程信息");
        else for(int i = 0;i < count;i++) {
            System.out.println("第" + (i+1) + "个课程信息\n" + list[i]);
        }
    }
}
