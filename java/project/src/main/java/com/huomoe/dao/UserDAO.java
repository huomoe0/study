package com.huomoe.dao;

import com.huomoe.mapper.UserMapper;
import com.huomoe.util.Encrypt;
import com.huomoe.util.Util;
import com.huomoe.vo.User;
import jxl.Sheet;
import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import org.apache.ibatis.session.SqlSession;

import java.io.*;
import java.util.List;
import java.util.Scanner;

public class UserDAO {
    public static User loginCheck(String username, String password) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        return mapper.checkAccount(username, Encrypt.MD5(password));
    }

    public static void changePassword(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        System.out.println("请输入当前密码：");
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if(user.getPassword().equals(Encrypt.MD5(s))) {
            System.out.println("请输入新的密码");
            String newPass = sc.next();
            while (!checkPassword(newPass)) {
                System.out.println("您的密码不符合复杂性要求（密码长度不少于6个字符，至少有一个小写字母，至少有一个大写字母，至少一个数字），请重新输入：");
                newPass = sc.next();
            }
            System.out.println("请输入确认密码：");
            String pass = sc.next();
            while (!newPass.equals(pass)) {
                System.out.println("两次输入的密码必须一致，请重新输入确认密码：");
                pass = sc.next();
            }
            mapper.update(user.getId(), Encrypt.MD5(pass));

            System.out.println("您已成功修改密码，请谨记");
        }
        else {
            System.out.println("密码错误");
        }
        sqlSession.close();
    }
    private static boolean checkPassword(String pass) {
        boolean upper = false, lower = false, digit = false, len = false;
        if(pass.length() >= 6)    len = true;
        for(int i = 0;i < pass.length();i++) {
            if(pass.charAt(i) >= 'A' && pass.charAt(i) <= 'Z')  upper = true;
            if(pass.charAt(i) >= 'a' && pass.charAt(i) <= 'z')  lower = true;
            if(pass.charAt(i) >= '0' && pass.charAt(i) <= '9')  digit = true;
        }
        return upper && lower && digit && len;
    }

    public static void addUser() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入姓名，用户名，密码，身份(用逗号分割)");
        String s = sc.nextLine();
        try {
            String[] split = s.split("[,，]");
            User user = new User();
            user.setName(split[0]);
            user.setUsername(split[1]);
            user.setPassword(Encrypt.MD5(split[2]));
            user.setRole(split[3]);
            mapper.add(user);

            System.out.println("添加成功");
        }
        catch (Exception e) {
            System.out.println("添加失败");
        }

        sqlSession.close();
    }
    public static void deleteUser() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        List<User> list = mapper.selectAll();

        System.out.println("编号\t姓名\t身份");
        for(User i : list)
            System.out.println(i);

        System.out.println("请输入要删除的编号");
        Scanner sc = new Scanner(System.in);
        Integer id = sc.nextInt();

        mapper.deleteById(id);
        System.out.println("删除成功");

        sqlSession.close();
    }

    private static int inputUserMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.导入csv文件(逗号分割，不含编号):\n" +
                "2.导入excel(第一行为列名,不含编号)\n" +
                "0.退出\n" +
                "请选择（0-2）：");
        return sc.nextInt();
    }

    private static void inputUserFromCSV() {
        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入导入文件绝对路径：");
            String s = sc.nextLine();
            File file = new File(s);
            FileReader reader = new FileReader(file);

            BufferedReader bf = new BufferedReader(reader);

            //读文件
            SqlSession sqlSession = Util.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            while ((s = bf.readLine()) != null) {
                try {
                    String[] split = s.split(",，");
                    User user = new User(null, split[0], split[1], split[2],split[3]);
                    mapper.add(user);

                }catch (Exception ignored) {

                }
            }
            System.out.println("导入成功");
            sqlSession.close();
            bf.close();
            reader.close();
        }
        catch (Exception e) {
            System.out.println("导入失败");
        }
    }
    private static void inputUserFromEXCEL() {
        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入导入文件绝对路径：");
            String s = sc.nextLine();
            File file = new File(s);

            SqlSession sqlSession = Util.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);

            Workbook workbook = Workbook.getWorkbook(file);
            Sheet sheet = workbook.getSheet(0);

            for(int i = 1;i < sheet.getRows();i++) {
                String username = sheet.getCell(1, i).getContents();
                String name = sheet.getCell(2, i).getContents();
                String password = sheet.getCell(3, i).getContents();
                String role = sheet.getCell(4, i).getContents();

                try{
                    mapper.add(new User(null, username, name, password, role));
                }catch (Exception ignored) {
                }

            }
            System.out.println("导入成功");

            sqlSession.close();
            workbook.close();
        }
        catch (Exception e) {
            System.out.println("导入失败");
        }
    }
    public static void inputUser() {
        int c = inputUserMenu();
        while (c != 0) {
            switch (c) {
                case 1:inputUserFromCSV();break;
                case 2:inputUserFromEXCEL();break;
                default:
                    System.out.println("请重新输入");
            }
            c = inputUserMenu();
        }
    }
    private static int outputUserMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.导出csv文件(逗号分割，不含编号):\n" +
                "2.导出excel(第一行为列名,不含编号)\n" +
                "0.退出\n" +
                "请选择（0-2）：");
        return sc.nextInt();
    }
    public static void outputUser() {
        int c = outputUserMenu();
        while (c != 0) {
            switch (c) {
                case 1:
                    outputUserToCSV();break;
                case 2:
                    outputUserToEXCEL();break;
                default:
                    System.out.println("请重新输入");
            }
            c = outputUserMenu();
        }
    }

    private  static void outputUserToCSV() {

        try {
            SqlSession sqlSession = Util.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);


            File out = new File("user.csv");
            FileWriter writer = new FileWriter(out);
            PrintWriter pw = new PrintWriter(writer);

            for (User user : mapper.selectAll())
                pw.println(user.getName() + "," + user.getUsername() + "," + user.getPassword() + "," + user.getRole());


            pw.close();
            writer.close();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\user.csv");
            sqlSession.close();
        } catch (Exception e) {
            System.out.println("导出失败");
        }
    }
    private  static void outputUserToEXCEL() {
        try {
            SqlSession sqlSession = Util.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);

            File file = new File("user.xls");

            WritableWorkbook workbook = Workbook.createWorkbook(file);
            WritableSheet sheet = workbook.createSheet("用户信息", 0);
            String[] title = {"姓名", "用户名", "密码", "身份"};
            Label label;
            for (int i = 0;i < title.length;i++) {
                label = new Label(i, 0, title[i]);
                sheet.addCell(label);
            }

            List<User> list = mapper.selectAll();


            for (int j = 0;j < list.size();j++) {
                sheet.addCell(new Label(0, j+1, list.get(j).getName()));
                sheet.addCell(new Label(1, j+1, list.get(j).getUsername()));
                sheet.addCell(new Label(2, j+1, list.get(j).getPassword()));
                sheet.addCell(new Label(3, j+1, list.get(j).getRole()));
            }
            workbook.write();
            workbook.close();
            sqlSession.close();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\user.xls");
        }catch (Exception e) {
            System.out.println("导出失败");
        }
    }
}
