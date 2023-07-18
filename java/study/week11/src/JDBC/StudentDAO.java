package JDBC;

import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;

import java.io.*;
import java.sql.*;
import java.util.Scanner;

public class StudentDAO {
    private static int insertStudent(Connection con, Student stu) throws SQLException {
        PreparedStatement ps = con.prepareStatement("insert into t_student values(?,?,?,?,?)");
        ps.setString(1, stu.getId());
        ps.setString(2, stu.getName());
        ps.setString(3, stu.getGender());
        ps.setString(4, stu.getProvince());
        ps.setString(5, stu.getBirth());
        return  ps.executeUpdate();
    }
    private static boolean checkExist(Connection con, String id) throws SQLException {
        PreparedStatement ps = con.prepareStatement("select * from t_student where id=?");
        ps.setString(1, id);
        ResultSet res = ps.executeQuery();
        return res.next();
    }
    public static void inputFromKeyboard(Connection con) throws SQLException {
        System.out.println("请输入学号，姓名，性别，省份，出生年月（用逗号分隔）:");
        Scanner sc = new Scanner(System.in);
        String[] info = sc.nextLine().split("[,，]");
        if(checkExist(con, info[0])) {
            System.out.println("学号已存在");
            return;
        }

        int c = insertStudent(con, new Student(info[0], info[1], info[2], info[3], info[4]));
        if(c != 0) {
            System.out.println("添加成功");
        }
        else {
            System.out.println("添加失败");
        }
    }
    public static void inputFromTXT(Connection con) throws IOException, SQLException {
        File file = new File("data/stu.txt");
        FileReader reader = new FileReader(file);
        BufferedReader bf = new BufferedReader(reader);
        String line;
        while ((line = bf.readLine()) != null) {
            String[] info = line.split("[,，]");
            if(checkExist(con, info[0])) continue;
            insertStudent(con, new Student(info[0], info[1], info[2], info[3], info[4]));
        }
        bf.close();
        reader.close();
        System.out.println("导入成功");
    }
    public static void inputFromXLS(Connection con) throws BiffException, IOException, SQLException {
        File file = new File("data/stu.xls");
        Workbook workbook = Workbook.getWorkbook(file);
        Sheet sheet = workbook.getSheet(0);
        for(int i = 0;i < sheet.getRows();i++) {
            String id = sheet.getCell(0, i).getContents();
            if(checkExist(con, id)) continue;
            String name = sheet.getCell(1, i).getContents();
            String gender = sheet.getCell(2, i).getContents();
            String province = sheet.getCell(3, i).getContents();
            String birth = sheet.getCell(4, i).getContents();
            insertStudent(con, new Student(id, name, gender, province, birth));
        }
        workbook.close();
        System.out.println("导入成功");
    }
    public static void outputToScreen(Connection con) throws SQLException {
        PreparedStatement ps = con.prepareStatement("select * from t_student");
        ResultSet res =  ps.executeQuery();
        while (res.next()) {
            String id = res.getString("id");
            String name = res.getString("name");
            String gender = res.getString("gender");
            String province = res.getString("province");
            String birth = res.getString("birth");
            System.out.println(id + "\t" + name + "\t" + gender + "\t" + province + "\t" + birth);
        }
        ps.close();
    }
    public static void outputToTXT(Connection con) throws IOException, SQLException {
        File file = new File("data/output.txt");
        FileWriter writer = new FileWriter(file);
        PrintWriter pw = new PrintWriter(writer);

        PreparedStatement ps = con.prepareStatement("select * from t_student");
        ResultSet res =  ps.executeQuery();

        while (res.next()) {
            String id = res.getString("id");
            String name = res.getString("name");
            String gender = res.getString("gender");
            String province = res.getString("province");
            String birth = res.getString("birth");
            pw.println(id + "," + name + "," + gender + "," + province + "," + birth);
        }
        pw.close();
        writer.close();

    }
    public static void outputToXLS(Connection con) throws IOException, SQLException, WriteException {
        File file = new File("data/output.xls");
        WritableWorkbook workbook = Workbook.createWorkbook(file);
        WritableSheet ws = workbook.createSheet("学生信息", 0);

        PreparedStatement ps = con.prepareStatement("select * from t_student");
        ResultSet res =  ps.executeQuery();

        int r = 0;
        while (res.next()) {
            String id = res.getString("id");
            String name = res.getString("name");
            String gender = res.getString("gender");
            String province = res.getString("province");
            String birth = res.getString("birth");
            ws.addCell(new Label(0, r, id));
            ws.addCell(new Label(1, r, name));
            ws.addCell(new Label(2, r, gender));
            ws.addCell(new Label(3, r, province));
            ws.addCell(new Label(4, r, birth));
            r++;
        }

        workbook.write();
        workbook.close();
    }
}
