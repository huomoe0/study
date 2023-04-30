import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;

import java.io.*;
import java.util.*;


public class Sys {

    public static void inputXLS(ArrayList<Student> S, ArrayList<Course> C, ArrayList<CourseStatistic> SC) throws BiffException, IOException {
        File file = new File("data\\grade.xls");
        Workbook workbook = Workbook.getWorkbook(file);
        Sheet sheet = workbook.getSheet(0);

        for(int i = 1;i < sheet.getRows();i++) {
            String id = sheet.getCell(0, i).getContents();
            String name = sheet.getCell(1, i).getContents();
            String gender = sheet.getCell(2, i).getContents();
            String cname = sheet.getCell(3, i).getContents();
            double grade = Double.parseDouble(sheet.getCell(4, i).getContents());
            if(!existStudent(S, id)) S.add(new Student(id, name, gender));
            if(!existCourse(C, cname))    C.add(new Course(cname));
            SC.add(new CourseStatistic(id, cname, grade));

        }
        System.out.println("添加成功");
    }
    public static void saveToXLS(ArrayList<Student> S, ArrayList<Course> C, ArrayList<CourseStatistic> SC) throws IOException, WriteException {
        File file = new File("data\\grade.xls");
        if(file.exists())   file.delete();


        WritableWorkbook workbook = Workbook.createWorkbook(file);
        WritableSheet sheet = workbook.createSheet("学生信息", 0);
        String[] title = {"学号", "姓名", "性别", "课程名称", "成绩"};
        Label label;
        for (int i = 0;i < title.length;i++) {
            label = new Label(i, 0, title[i]);
            sheet.addCell(label);
        }
        for (int j = 0;j < SC.size();j++) {
            Student s = idgetStudent(S, SC.get(j).getSid());
            sheet.addCell(new Label(0, j+1, s.getId()));
            sheet.addCell(new Label(1, j+1, s.getName()));
            sheet.addCell(new Label(2, j+1, s.getGender()));
            sheet.addCell(new Label(3, j+1, SC.get(j).getCname()));
            sheet.addCell(new Label(4, j+1, String.valueOf(SC.get(j).getGrade())));
        }
        workbook.write();
        workbook.close();
        System.out.println("保存成功");
    }
    private static boolean existStudent(ArrayList<Student> S, String id) {
        for(Student i : S) {
            String[] info = i.toString().split("\t");
            if(info[0].equals(id))  return true;
        }
        return false;
    }
    private static boolean existCourse(ArrayList<Course> C, String name) {
        for(Course i : C) {
            if(name.equals(i.toString()))  return true;
        }
        return false;
    }
    public static void inputGrade(ArrayList<Student> S, ArrayList<Course> C, ArrayList<CourseStatistic> SC) {
        System.out.println("请输入学号，姓名，性别，课程，成绩（用逗号分隔）");
        Scanner sc = new Scanner(System.in);
        String[] info = sc.nextLine().split("[,，]");
        if(!existStudent(S, info[0])) S.add(new Student(info[0], info[1], info[2]));
        if(!existCourse(C, info[3]))    C.add(new Course(info[3]));
        SC.add(new CourseStatistic(info[0], info[3], Double.parseDouble(info[4])));
        System.out.println("添加成功");
    }
    public static void inputCSV(ArrayList<Student> S, ArrayList<Course> C, ArrayList<CourseStatistic> SC) throws IOException {
        File in = new File("data\\grade.txt");
        FileReader reader = new FileReader(in);
        BufferedReader br = new BufferedReader(reader);
        String tmp;

        while ((tmp = br.readLine()) != null && !tmp.equals("")) {
            String[] info = tmp.split("\t");
            if(!existStudent(S, info[0])) S.add(new Student(info[0], info[1], info[2]));
            if(!existCourse(C, info[3]))    C.add(new Course(info[3]));
            SC.add(new CourseStatistic(info[0], info[3], Double.parseDouble(info[4])));
        }

        System.out.println("添加成功");

        reader.close();
        br.close();
    }

    private static Student idgetStudent(ArrayList<Student> S, String id) {
        for(Student i : S) {
            if(id.equals(i.getId()))    return i;
        }
        return null;
    }
    public static void saveToCSV(ArrayList<Student> S, ArrayList<CourseStatistic> SC) throws IOException {
        File out = new File("data\\grade.txt");
        FileWriter writer = new FileWriter(out);
        PrintWriter pw = new PrintWriter(writer);

        for (CourseStatistic i : SC) {
            Student s = idgetStudent(S, i.getSid());
            pw.println(i.getSid() + "\t" + s.getName() + "\t" + s.getGender() + "\t" + i.getCname() + "\t" + i.getGrade());
        }

        pw.close();
        writer.close();
        System.out.println("保存成功");
    }


    public static void total(ArrayList<Student> S, ArrayList<CourseStatistic> SC) {
        ArrayList<String> totalInfo = new ArrayList<>();
        // 统计总分，平均分
        for(Student stu : S) {
            int count = 0;
            double sum = 0;
            String[] info = stu.toString().split("\t");
            for (CourseStatistic c : SC)
                if(c.getSid().equals(info[0])) {
                    count++;
                    sum += c.getGrade();
                }
            totalInfo.add(stu.toString() + "\t" + sum + "\t" + sum/count);
        }

        if(totalInfo.size() == 0) {
            System.out.println("当前学生信息为空");
            return;
        }

        totalInfo.sort((s1, s2) -> {
            double a1 = Double.parseDouble(s1.split("\t")[3]);
            double a2 = Double.parseDouble(s2.split("\t")[3]);
            return (int)(a2 - a1);
        });

        System.out.println("学号\t姓名\t性别\t总分\t平均分\t名次");
        for (int i = 0;i < totalInfo.size();i++) {
            System.out.println(totalInfo.get(i) + "\t" + (i+1));
        }
    }
    private static int queryMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.按学号查询平均分\n" +
                "2.按课程查询平均分\n" +
                "3.返回上一级");
        return sc.nextInt();
    }
    private static  void queryFromId(ArrayList<Student> S, ArrayList<CourseStatistic> SC) {
        int count = 0;
        double sum = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入要查询的学生id");
        String id = sc.nextLine();

        System.out.println("课程名\t成绩");
        for (CourseStatistic i : SC) {
            if(i.getSid().equals(id)) {
                System.out.println(i.getCname() + "\t" + i.getGrade());
                count++;
                sum += i.getGrade();
            }
        }
        System.out.println("共" + count + "门课程, 平均分为" + sum/count);
    }
    private static  void queryFromCourse(ArrayList<Student> S, ArrayList<CourseStatistic> SC) {
        int count = 0;
        double sum = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入要查询的课程名");
        String name = sc.nextLine();

        System.out.println("学号\t姓名\t性别\t成绩");
        for (CourseStatistic i : SC) {
            if(i.getCname().equals(name)) {
                System.out.println(idgetStudent(S, i.getSid()) + "\t" + i.getGrade());
                count++;
                sum += i.getGrade();
            }
        }
        System.out.println("共" + count + "名学生, 平均分为" + sum/count);
    }
    public static void query(ArrayList<Student> S, ArrayList<CourseStatistic> SC) {
        int choice = queryMenu();
        while (choice != 3) {
            switch (choice) {
                case 1:queryFromId(S, SC);break;
                case 2:queryFromCourse(S, SC);break;
                default:
                    System.out.println("请重新输入：");
            }
            choice = queryMenu();
        }
    }
    public static void modifyPass(String user) throws IOException {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入新密码");
        String newPass = sc.nextLine();


        System.out.println("请输入当前用户密码：");
        String in = sc.nextLine();

        String[] info = user.split("[,，]");
        if(in.equals(info[1])) {
            File file_old = new File("data\\user.txt");
            File file_new = new File("data\\user_new.txt");
            FileWriter writer = new FileWriter(file_new);
            PrintWriter pw = new PrintWriter(writer);
            FileReader reader = new FileReader(file_old);
            BufferedReader br = new BufferedReader(reader);

            String s;
            while ((s = br.readLine()) != null) {
                if(s.equals(user)) {
                    pw.println(info[0] + "," + newPass + "," + info[2]);
                }
                else pw.println(s);
            }



            System.out.println("修改成功");
            reader.close();
            writer.close();
            pw.close();
            writer.close();

            file_old.delete();
            file_new.renameTo(file_old);
        }
        else {
            System.out.println("密码错误");
        }
    }

    public static String login() throws IOException {
        String currentUser = null;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入用户名和密码，用逗号分割");
        String[] input = sc.nextLine().split("[,，]");

        File userList = new File("data\\user.txt");
        FileReader reader = new FileReader(userList);
        BufferedReader br = new BufferedReader(reader);
        String userInfo;

        while ((userInfo = br.readLine()) != null) {
            String[] info = userInfo.split("[,，]");
            if(input[0].equals(info[0]) && input[1].equals(info[1])) {
                System.out.println("登录成功，当前用户为" + info[2]);
                currentUser = userInfo;
                break;
            }
        }


        reader.close();
        br.close();

        return currentUser;
    }

    public static int menu(String userName) {
        System.out.println("====学生成绩管理系统v1.0====\n" +
                "当前用户：" + userName + "\n" +
                "1.键盘输入成绩\n" +
                "2.csv文件读取成绩\n" +
                "3.xls文件读取成绩\n" +
                "4.成绩查询\n" +
                "5.统计结果保存至csv文件\n" +
                "6.统计结果保存至xls文件\n" +
                "7.直接显示统计结果\n" +
                "8.修改密码\n" +
                "9.退出\n" +
                "请选择(1-9):");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
}
