package com.huomoe;

import com.huomoe.dao.CourseDAO;
import com.huomoe.dao.UserDAO;
import com.huomoe.vo.User;
import jxl.write.WriteException;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;
import java.util.Scanner;


public class Driver {
    private static int lastLoginTimes;
    private static User currentUser;

    //加载配置文件
    static {
        Properties properties = new Properties();
        try {
            properties.load(new FileReader("src\\main\\resources\\config.properties"));
        } catch (IOException e) {
            System.out.println("配置文件不存在");
        }
        lastLoginTimes = Integer.parseInt(properties.getProperty("MAX_LOGIN_TIMES"));
    }

    public static void main(String[] args) throws IOException, WriteException {

        //登陆系统
        while (lastLoginTimes != 0) {
            if(login()) {
                System.out.println("登录成功,欢迎使用学生选课系统\n姓名: " + currentUser.getName() + "\n" + "身份: " + currentUser.getRole());
                break;
            }
            else {
                lastLoginTimes--;
                System.out.println("用户名或密码错误，请重试。你还有" + lastLoginTimes + "次机会");
            }

        }

        if(lastLoginTimes == 0) {
            System.out.println("登陆失败,系统即将退出...");
            return;
        }

        //功能选择
        switch(currentUser.getRole()) {
            case "学生":studentInterface();break;
            case "教师":teacherInterface();break;
            case "管理员":adminInterface();break;
        }

        System.out.println("正在退出,欢迎下次使用");
    }

    private static int menu(String role) {
        System.out.println("========学生选课系统v0.1========");
        switch (role) {
            case "学生":
                System.out.println("1.查看所有课程\n" +
                        "2.选课\n" +
                        "3.退选\n" +
                        "4.成绩查询统计\n" +
                        "5.修改密码\n" +
                        "0.退出\n" +
                        "请选择（0-5）：");
                break;
            case "教师":
                System.out.println("1.查看担任的课程信息\n" +
                        "2.查看课程选课名单\n" +
                        "3.输入某课程学生成绩\n" +
                        "4.成绩导出\n" +
                        "5.修改密码\n" +
                        "0.退出\n" +
                        "请选择（0-5）：");
                break;
            case "管理员":
                System.out.println("1.用户管理\n" +
                        "2.课程管理\n" +
                        "3.修改密码\n" +
                        "0.退出\n" +
                        "请选择（0-3）：");
                break;
        }
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }


    private static void studentInterface() throws IOException {
        int c = menu("学生");
        while (c != 0) {
            switch (c) {
                case 1:CourseDAO.viewAllCourse();break;
                case 2:CourseDAO.selectCourse(currentUser);break;
                case 3:CourseDAO.dropCourse(currentUser);break;
                case 4:CourseDAO.gradeQuery(currentUser);break;
                case 5:UserDAO.changePassword(currentUser);break;
                default:
                    System.out.println("请重新输入");
            }
            c = menu("学生");
        }
    }


    private static void teacherInterface() throws IOException, WriteException {
        int c = menu("教师");
        while (c != 0) {
            switch (c) {
                case 1:CourseDAO.viewTeacherCourse(currentUser);break;
                case 2:CourseDAO.viewSelectCourseList(currentUser);break;
                case 3:CourseDAO.addStudentGrade(currentUser);break;
                case 4:CourseDAO.outputGradeList(currentUser);break;
                case 5:UserDAO.changePassword(currentUser);break;
                default:
                    System.out.println("请重新输入");
            }
            c = menu("教师");
        }
    }
    private static void adminInterface() throws IOException {
        int c = menu("管理员");
        while (c != 0) {
            switch (c) {
                case 1:userManagement();break;
                case 2:courseManagement();break;
                case 3:UserDAO.changePassword(currentUser);break;
                default:
                    System.out.println("请重新输入");
            }
            c = menu("管理员");
        }
    }

    private static boolean login() throws IOException {
        System.out.println("请输入用户名：");
        Scanner sc = new Scanner(System.in);
        String username = sc.nextLine();
        System.out.println("请输入密码：");
        String password = sc.nextLine();

            currentUser = UserDAO.loginCheck(username, password);
        return currentUser != null;
    }


    private static int userManagementMenu() {
        System.out.println("1.添加用户\n" +
                "2.删除用户\n" +
                "3.用户导入\n" +
                "4.用户导出\n" +
                "0.退出\n" +
                "请选择（0-4）：");
        return new Scanner(System.in).nextInt();
    }

    public static void userManagement() throws IOException {
        int c = userManagementMenu();
        while (c != 0) {
            switch (c) {
                case 1:UserDAO.addUser();break;
                case 2:UserDAO.deleteUser();break;
                case 3:UserDAO.inputUser();break;
                case 4:UserDAO.outputUser();break;
                default:
                    System.out.println("请重新输入");
            }
            c = userManagementMenu();
        }
    }

    private static int courseManagementMenu() {
        System.out.println("1.添加课程\n" +
                "2.删除课程\n" +
                "3.课程导入\n" +
                "4.课程导出\n" +
                "0.退出\n" +
                "请选择（0-4）：");
        return new Scanner(System.in).nextInt();
    }

    public static void courseManagement() throws IOException {
        int c = courseManagementMenu();
        while (c != 0) {
            switch (c) {
                case 1:CourseDAO.addCourse();break;
                case 2:CourseDAO.deleteCourse();break;
                case 3:CourseDAO.inputCourse();break;
                case 4:CourseDAO.outputCourse();break;
                default:
                    System.out.println("请重新输入");
            }
            c = courseManagementMenu();
        }
    }
}
