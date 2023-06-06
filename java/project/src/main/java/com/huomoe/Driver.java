package com.huomoe;

import com.huomoe.dao.CourseDAO;
import com.huomoe.dao.UserDAO;
import com.huomoe.vo.User;

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
            lastLoginTimes = Integer.parseInt(properties.getProperty("MAX_LOGIN_TIMES"));
        } catch (IOException e) {
            System.out.println("配置文件不存在");
        }
    }
    public static void main(String[] args) throws IOException {
        //登陆系统
        while (lastLoginTimes != 0) {
            currentUser = UserDAO.login();
            if(currentUser != null) {
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
        int c = mainMenu();
        while (c != 0) {
            switch (c) {
                case 1:courseManagement();break;
                case 2:gradeManagement();break;
                case 3:userManagement();break;
                default:
                    System.out.println("请重新输入");
            }
            c = mainMenu();
        }
        System.out.println("正在退出,欢迎下次使用");
    }
    private static int mainMenu() {
        System.out.println("========学生选课系统v2.0========\n" +
                "1.课程管理\n" +
                "2.成绩管理\n" +
                "3.用户管理\n" +
                "0.退出\n" +
                "请选择（0-3）：");
        return new Scanner(System.in).nextInt();
    }
    private static int courseManagementMenu() {
        System.out.println("========课程管理========\n" +
                "1.课程查询\n" +
                "2.查看相关课程\n" +
                "3.选课\n" +
                "4.退课\n" +
                "5.新增课程\n" +
                "6.删除课程\n" +
                "7.从电子表格导入课程\n" +
                "8.课程导出到电子表格\n" +
                "0.退出\n" +
                "请选择（0-8）：");
        return new Scanner(System.in).nextInt();
    }
    private static int gradeManagementMenu() {
        System.out.println("1.成绩查询\n" +
                "2.添加成绩\n" +
                "3.成绩导出到电子表格\n" +
                "0.退出\n" +
                "请选择（0-3）：");
        return new Scanner(System.in).nextInt();
    }
    private static int userManagementMenu() {
        System.out.println("1.修改密码\n" +
                "2.添加用户\n" +
                "3.删除用户\n" +
                "4.从电子表格导入用户\n" +
                "5.用户导出到电子表格\n" +
                "0.退出\n" +
                "请选择（0-5）：");
        return new Scanner(System.in).nextInt();
    }
    public static void courseManagement() throws IOException {
        int c;
        do {
            c = courseManagementMenu();
            if(!currentUser.getRole().equals("administrator") && c >= 5) {
                System.out.println("权限不足");
                continue;
            }
            else if(currentUser.getRole().equals("teacher") && (c == 3 || c == 4) || currentUser.getRole().equals("administrator") && (c >= 2 && c <= 4)) {
                System.out.println("无需使用该功能");
                continue;
            }

            switch (c) {
                case 1:CourseDAO.queryCourse();break;
                case 2:CourseDAO.viewRelatedCourse(currentUser);break;
                case 3:CourseDAO.selectCourse(currentUser);break;
                case 4:CourseDAO.dropCourse(currentUser);break;
                case 5:CourseDAO.addCourse();break;
                case 6:CourseDAO.deleteCourse();break;
                case 7:CourseDAO.inputCourse();break;
                case 8:CourseDAO.outputCourse();break;
                case 0:break;
                default:
                    System.out.println("请重新输入");
            }
        }while (c != 0);
    }
    private static void gradeManagement() throws IOException {
        int c;
        do {
            c = gradeManagementMenu();
            if(currentUser.getRole().equals("student") && c >= 2) {
                System.out.println("权限不足");
                continue;
            }
            if((currentUser.getRole().equals("teacher") || currentUser.getRole().equals("administrator")) && c == 1) {
                System.out.println("无需使用该功能");
                continue;
            }

            switch (c) {
                case 1:CourseDAO.queryGrade(currentUser);break;
                case 2:CourseDAO.addStudentGrade();break;
                case 3:CourseDAO.outputGrade();break;
                case 0:break;
                default:
                    System.out.println("请重新输入");
            }
        }while (c != 0);
    }
    public static void userManagement() throws IOException {
        int c;
        do {
            c = userManagementMenu();
            if(!currentUser.getRole().equals("administrator") && c >= 2) {
                System.out.println("权限不足");
                continue;
            }
            switch (c) {
                case 1:UserDAO.changePassword(currentUser);break;
                case 2:UserDAO.addUser();break;
                case 3:UserDAO.deleteUser();break;
                case 4:UserDAO.inputUser();break;
                case 5:UserDAO.outputUser();break;
                case 0:break;
                default:
                    System.out.println("请重新输入");
            }
        }while (c != 0);
    }
}
