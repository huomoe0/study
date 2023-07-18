import jxl.read.biff.BiffException;
import jxl.write.WriteException;

import java.io.*;
import java.util.ArrayList;

public class Driver {
    static ArrayList<Student> S = new ArrayList<>();
    static ArrayList<Course> C = new ArrayList<>();
    static ArrayList<CourseStatistic>  SC = new ArrayList<>();

    public static void main(String[] args) throws IOException, BiffException, WriteException {

        // 登录系统
        String currentUser = null;
        int lastLoginTimes = 3;
        while (lastLoginTimes != 0)
        {
            lastLoginTimes--;
            if((currentUser = Sys.login()) != null) break;
            else {
                System.out.println("用户名或密码错误，你还有" + lastLoginTimes + "次尝试机会");
            }
        }
        if(lastLoginTimes == 0) {
            System.out.println("失败次数过多，系统即将自动退出");
            return;
        }
        String[] userInfo = currentUser.split("[，,]");

        // 选择功能
        int choice = Sys.menu(userInfo[2]);
        while (choice != 9) {
            switch (choice) {
                case 1:Sys.inputGrade(S, C, SC);break;
                case 2:Sys.inputCSV(S, C, SC);break;
                case 3:Sys.inputXLS(S, C, SC);break;
                case 4:Sys.query(S, SC);break;
                case 5:Sys.saveToCSV(S, SC);break;
                case 6:Sys.saveToXLS(S, C, SC);break;
                case 7:Sys.total(S, SC);break;
                case 8:Sys.modifyPass(currentUser);break;
                default:
                    System.out.println("请重新选择：");break;
            }
            choice = Sys.menu(currentUser);
        }
    }


}
