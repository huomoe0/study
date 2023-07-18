package JDBC;

import jxl.read.biff.BiffException;
import jxl.write.WriteException;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Scanner;

public class Driver {
    public static void main(String[] args) throws SQLException, IOException, BiffException, WriteException {

        Connection con = JDBCUtil.getConnection();

        int c = menu();
        while (c != 7) {
            switch(c) {
                case 1:StudentDAO.inputFromKeyboard(con);break;
                case 2:StudentDAO.inputFromTXT(con);break;
                case 3:StudentDAO.inputFromXLS(con);break;
                case 4:StudentDAO.outputToScreen(con);break;
                case 5:StudentDAO.outputToTXT(con);break;
                case 6:StudentDAO.outputToXLS(con);break;
                default:
                    System.out.println("请重新输入");break;
            }
            c = menu();
        }

        JDBCUtil.close(con);
    }

    private static int menu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.键盘输入学生数据\n" +
                "2.txt导入学生数据\n" +
                "3.xls导入学生数据\n" +
                "4.屏幕输出学生数据\n" +
                "5.学生数据导出至txt\n" +
                "6.学生数据导出至xls\n" +
                "7.退出\n" +
                "请输入(1-7):");
        return sc.nextInt();
    }

}
