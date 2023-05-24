package com.huomoe.dao;

import com.huomoe.mapper.CourseMapper;

import com.huomoe.mapper.StudentCourseMapper;
import com.huomoe.mapper.UserMapper;
import com.huomoe.util.Util;
import com.huomoe.vo.Course;
import com.huomoe.vo.StudentCourse;
import com.huomoe.vo.User;
import jxl.Sheet;
import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;
import org.apache.ibatis.session.SqlSession;

import java.io.*;
import java.util.List;
import java.util.Scanner;

public class CourseDAO {
    public static void viewAllCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        List<Course> courses = mapper.selectAll();
        System.out.println("课程号\t课程名\t教师编号\t教师名");
        for(Course i : courses) {
            User user = userMapper.selectById(i.getTeacher());
            System.out.println(i + "\t" + user.getId() + "\t" + user.getName());
        }


        sqlSession.close();
    }
    public static void selectCourse(User user) throws IOException { //学生选课
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

        //打印所有课程
        viewAllCourse();

        //选课
        System.out.println("请输入要选的课程号");
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        Course course = mapper.selectById(s);

        if(course != null) {
            StudentCourseMapper mapper1 = sqlSession.getMapper(StudentCourseMapper.class);
            try {
                mapper1.add(new StudentCourse(user.getId(), s, null));
                System.out.println("选课成功");
            } catch (Exception e) {
                System.out.println("请不要重复选课");
            }
        }
        else {
            System.out.println("此课程不存在");
        }

        sqlSession.close();
    }
    public static void dropCourse(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        //打印已选课程
        List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(user.getId(), null, null));
        System.out.println("已选课程：\n" +
                "课程号\t课程名\t教师");
        for(StudentCourse  i : studentCourses) {
            Course c = courseMapper.selectById(i.getCid());
            System.out.println(c + "\t" +  userMapper.selectById(c.getTeacher()).getName());
        }

        System.out.println("请输入要退选的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        //如果课程号存在，就删除
        if(studentCourseMapper.selectById(user.getId(), id) != null) {
            studentCourseMapper.deleteById(user.getId(), id);

            System.out.println("退选成功");
        }
        else {
            System.out.println("课程不存在");
        }


        sqlSession.close();
    }
    public static void gradeQuery(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(user.getId(), null, null));
        System.out.println("已有成绩课程\n" +
                "课程号\t课程名\t教师\t成绩");

        double sum = 0;
        int countNotNull = 0;
        for(StudentCourse  i : studentCourses) {
            Course c = courseMapper.selectById(i.getCid());
            if(i.getGrade() != null) {
                sum += i.getGrade();
                countNotNull++;
            }
            System.out.println(c + "\t" + userMapper.selectById(c.getTeacher()).getName() + "\t" + i.getGrade());
        }
        System.out.println("共" + studentCourses.size() + "门课程\n有成绩的课程共" + countNotNull + "门，平均分为" + sum/countNotNull);
        sqlSession.close();
    }

    public static void viewTeacherCourse(User user) throws IOException { //教师查看教授课程
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

        List<Course> courses = courseMapper.selectByCondition(new Course(null, null, user.getId()));

        System.out.println("课程号\t课程名");
        for (Course i : courses) {
            System.out.println(i);
        }

        sqlSession.close();
    }

    public static void viewSelectCourseList(User user) throws IOException, WriteException { //查看课程选课名单
        viewTeacherCourse(user);

        System.out.println("请输入要查询的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        if(courseMapper.selectById(id) != null) {
            System.out.println("学号\t姓名");

            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(null, id, null));
            for(StudentCourse i : studentCourses)
                System.out.println(i.getUid() + "\t" + userMapper.selectById(i.getUid()).getName());

            //选择是否导出到文件
            int c = outputListMenu();
            switch (c) {
                case 1:outputToTXT(studentCourses, false);break;
                case 2:outputToEXCEL(studentCourses, false);break;
                default:
                    System.out.println("请输入正确的选项");
            }
        }
        else {
            System.out.println("课程不存在");
        }

        sqlSession.close();
    }

    private static void outputToTXT(List<StudentCourse> studentCourses, boolean isOutputGrade) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);



        File out = new File("grade.txt");
        FileWriter writer = new FileWriter(out);
        PrintWriter pw = new PrintWriter(writer);

        for (StudentCourse i : studentCourses) {
            String s = i.getUid() + "\t" + userMapper.selectById(i.getUid()).getName();
            if(isOutputGrade)
                s += "\t" + i.getGrade();
            pw.println(s);
        }

        System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\grade.txt");

        pw.close();
        writer.close();
        sqlSession.close();
    }
    private static void outputToEXCEL(List<StudentCourse> studentCourses, boolean isOutputGrade) throws IOException, WriteException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        File file = new File("grade.xls");

        WritableWorkbook workbook = Workbook.createWorkbook(file);
        WritableSheet sheet = workbook.createSheet("学生名单", 0);
        String[] title = {"学号", "姓名"};
        Label label;
        for (int i = 0;i < title.length;i++) {
            label = new Label(i, 0, title[i]);
            sheet.addCell(label);
        }
        if(isOutputGrade) {
            label = new Label(2, 0, "成绩");
            sheet.addCell(label);
        }
        for (int j = 0;j < studentCourses.size();j++) {
            label = new Label(0, j+1, studentCourses.get(j).getUid().toString());
            sheet.addCell(label);
            label = new Label(1, j+1, userMapper.selectById(studentCourses.get(j).getUid()).getName());
            sheet.addCell(label);
            if(isOutputGrade) {
                label = new Label(2, j+1, "" + studentCourses.get(j).getGrade());
                sheet.addCell(label);
            }
        }
        workbook.write();
        System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\grade.xls");

        workbook.close();
        sqlSession.close();
    }
    private static int outputListMenu() {
        System.out.println("1.导出到txt\n" +
                "2.导出到excel\n" +
                "0.退出\n" +
                "请选择（0-2）：");
        return new Scanner(System.in).nextInt();
    }

    public static void addStudentGrade(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        viewTeacherCourse(user);

        System.out.println("请输入要查询的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        if(courseMapper.selectById(id) != null) {
            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(null, id, null));
            System.out.println("学号\t姓名\t成绩");
            for (StudentCourse i : studentCourses) {
                User u = userMapper.selectById(i.getUid());
                System.out.println(u.getId() + "\t" + u.getName() + "\t" + i.getGrade());
            }


            String s;

            do {
                System.out.println("请输入要添加成绩的学号和分数，如（1001,90）,输入exit退出");
                s = sc.next();
                if(s.equalsIgnoreCase("exit"))  break;
                try {
                    String[] tmp = s.split("[,，]");
                    studentCourseMapper.update(Integer.parseInt(tmp[0]), id, Double.parseDouble(tmp[1]));

                    System.out.println("添加成功");
                }catch (Exception e) {
                    System.out.println("添加失败");
                }
            } while (true);
        }
        else {
            System.out.println("课程不存在");
        }


        sqlSession.close();
    }

    public static void outputGradeList(User user) throws IOException, WriteException {
        viewTeacherCourse(user);

        System.out.println("请输入要导出的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);


        if(courseMapper.selectById(id) != null) {
            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(null, id, null));

            //选择是否导出到文件
            int c = outputListMenu();
            switch (c) {
                case 1:outputToTXT(studentCourses, true);break;
                case 2:outputToEXCEL(studentCourses, true);break;
                default:
                    System.out.println("请输入正确的选项");
            }
        }
        else {
            System.out.println("课程不存在");
        }

        sqlSession.close();
    }

    public static void addCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入课程名，教师编号(用逗号分割)");
        String s = sc.nextLine();
        try {
            String[] split = s.split("[,，]");
            Course course = new Course();
            course.setName(split[0]);
            course.setTeacher(Integer.valueOf(split[1]));
            mapper.add(course);
            System.out.println("添加成功");
        }
        catch (Exception e) {
            System.out.println("添加失败");
        }
        sqlSession.close();
    }
    public static void deleteCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        List<Course> list = mapper.selectAll();

        System.out.println("编号\t课程名\t教师编号\t教师名");
        for(Course i : list) {
            User user = userMapper.selectById(i.getTeacher());
            System.out.println(i + "\t" + user.getId() + "\t" + user.getName());
        }

        System.out.println("请输入要删除的编号");
        Scanner sc = new Scanner(System.in);
        Integer id = sc.nextInt();

        mapper.deleteById(id);
        System.out.println("删除成功");

        sqlSession.close();
    }
    private static int inputCourseMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.导入csv文件(逗号分割，不含编号):\n" +
                "2.导入excel(第一行为列名,不含编号)\n" +
                "0.退出\n" +
                "请选择（0-2）：");
        return sc.nextInt();
    }
    private static void inputCourseFromCSV() {

        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入导入文件绝对路径：");
            String s = sc.nextLine();
            File file = new File(s);
            FileReader reader = new FileReader(file);

            BufferedReader bf = new BufferedReader(reader);

            //读文件
            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);
            while ((s = bf.readLine()) != null) {
                try {
                    String[] split = s.split(",，");
                    Course course = new Course(null, split[0], Integer.parseInt(split[1]));
                    mapper.add(course);

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
    private static void inputCourseFromEXCEL() {

        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入导入文件绝对路径：");
            String s = sc.nextLine();
            File file = new File(s);

            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

            Workbook workbook = Workbook.getWorkbook(file);
            Sheet sheet = workbook.getSheet(0);

            for(int i = 1;i < sheet.getRows();i++) {
                String name = sheet.getCell(1, i).getContents();
                Integer teacher = Integer.parseInt(sheet.getCell(2, i).getContents());

                try{
                    mapper.add(new Course(null, name, teacher));
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
    public static void inputCourse() {
        int c = inputCourseMenu();
        while (c != 0) {
            switch (c) {
                case 1:inputCourseFromCSV();break;
                case 2:inputCourseFromEXCEL();break;
                default:
                    System.out.println("请重新输入");
            }
            c = inputCourseMenu();
        }
    }
    private static int outputCourseMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("1.导出csv文件(逗号分割，不含编号):\n" +
                "2.导出excel(第一行为列名,不含编号)\n" +
                "0.退出\n" +
                "请选择（0-2）：");
        return sc.nextInt();
    }
    public static void outputCourse() {
        int c = outputCourseMenu();
        while (c != 0) {
            switch (c) {
                case 1:
                    outputCourseToCSV();break;
                case 2:
                    outputCourseToEXCEL();break;
                default:
                    System.out.println("请重新输入");
            }
            c = outputCourseMenu();
        }
    }
    private  static void outputCourseToCSV() {

        try {
            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

            File out = new File("course.csv");
            FileWriter writer = new FileWriter(out);
            PrintWriter pw = new PrintWriter(writer);

            for (Course course : mapper.selectAll())
                pw.println(course.getName() + "," + course.getTeacher());

            pw.close();
            writer.close();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\course.csv");
            sqlSession.close();
        } catch (Exception e) {
            System.out.println("导出失败");
        }
    }
    private  static void outputCourseToEXCEL() {
        try {
            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

            File file = new File("course.xls");

            WritableWorkbook workbook = Workbook.createWorkbook(file);
            WritableSheet sheet = workbook.createSheet("课程信息", 0);
            String[] title = {"课程名", "教师编号"};
            Label label;
            for (int i = 0;i < title.length;i++) {
                label = new Label(i, 0, title[i]);
                sheet.addCell(label);
            }

            List<Course> list = mapper.selectAll();


            for (int j = 0;j < list.size();j++) {
                sheet.addCell(new Label(0, j+1, list.get(j).getName()));
                sheet.addCell(new Label(1, j+1, list.get(j).getTeacher().toString()));
            }
            workbook.write();
            workbook.close();
            sqlSession.close();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\course.xls");
        }catch (Exception e) {
            System.out.println("导出失败");
        }
    }
}
