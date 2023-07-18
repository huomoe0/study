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

import org.apache.ibatis.session.SqlSession;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class CourseDAO {

    public static void printCourse(List<Course> courses, String key) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        System.out.println("课程号\t课程名\t容量\t教师号\t教师名");
        for(Course i : courses) {
            if(!i.toString().contains(key)) continue;
            System.out.println(i + "\t" + userMapper.selectById(i.getTeacher()));
        }
        sqlSession.close();
    }
    public static void printCourse(List<Course> courses) throws IOException {
        printCourse(courses, "");
    }
    public static void viewAllCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);
        List<Course> courses = mapper.selectAll();
        printCourse(courses);
        sqlSession.close();
    }
    public static void selectCourse(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        //选课
        System.out.println("请输入要选的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();
        try {
            Course c = courseMapper.selectById(id);
            List<StudentCourse> studentCourses = studentCourseMapper.selectAll();
            if(studentCourses.size() >= c.getSize()) System.out.println("课程已满，请选择其他课程");
            else {
                studentCourseMapper.add(new StudentCourse(user.getId(), id, null));
                System.out.println("选课成功");
            }
        } catch (Exception e) {
            System.out.println("选课失败");
        }
        sqlSession.close();
    }

    public static void dropCourse(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);

        //打印已选课程
        viewRelatedCourse(user);

        System.out.println("请输入要退选的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        //如果课程号存在，就删除
        studentCourseMapper.deleteById(user.getId(), id);
        System.out.println("退选成功");

        sqlSession.close();
    }
    public static void printStudentCourse(List<StudentCourse> studentCourses) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        System.out.println("学号\t姓名\t课程号\t课程名\t成绩");
        for(StudentCourse i : studentCourses) {
            Course course = courseMapper.selectById(i.getCid());
            User user = userMapper.selectById(i.getUid());
            System.out.println(user.getId() + "\t" + user.getName() + "\t" + i.getCid() + "\t" + course.getName() + "\t" + i.getGrade());
        }
        sqlSession.close();
    }

    public static void queryGrade(User user) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

        List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(user.getId(), null, null));
        System.out.println("课程号\t课程名\t成绩");

        double sum = 0;
        int countNotNull = 0;
        for(StudentCourse  i : studentCourses) {
            Course c = courseMapper.selectById(i.getCid());
            if(i.getGrade() != null) {
                sum += i.getGrade();
                countNotNull++;
            }
            System.out.println(i.getCid() + "\t" + c.getName() + "\t" + i.getGrade());
        }
        System.out.println("共" + studentCourses.size() + "门课程\n有成绩的课程共" + countNotNull + "门，平均分为" + sum/countNotNull);
        sqlSession.close();
    }


    public static void outputGrade() {
        try {
            SqlSession sqlSession = Util.getSqlSession();
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
            CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

            System.out.println("请输入要导出的课程号");
            Scanner sc = new Scanner(System.in);
            int id = sc.nextInt();
            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(null, id, null));

            File file = new File("grade.xls");

            WritableWorkbook workbook = Workbook.createWorkbook(file);
            WritableSheet sheet = workbook.createSheet("学生名单", 0);
            String[] title = {"课程号","课程名","学号", "姓名", "成绩"};
            Label label;
            for (int i = 0;i < title.length;i++) {
                label = new Label(i, 0, title[i]);
                sheet.addCell(label);
            }

            for (int j = 0;j < studentCourses.size();j++) {
                Course course = courseMapper.selectById(studentCourses.get(j).getCid());

                label = new Label(0, j+1, course.getId().toString());
                sheet.addCell(label);
                label = new Label(1, j+1, course.getName());
                sheet.addCell(label);
                label = new Label(2, j+1, studentCourses.get(j).getUid().toString());
                sheet.addCell(label);
                label = new Label(3, j+1, userMapper.selectById(studentCourses.get(j).getUid()).getName());
                sheet.addCell(label);
                label = new Label(4, j+1, "" + studentCourses.get(j).getGrade());
                sheet.addCell(label);
            }
            workbook.write();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\grade.xls");

            workbook.close();
            sqlSession.close();
        }
        catch (Exception e) {
            System.out.println("导出失败");
        }
    }


    public static void addStudentGrade() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

        System.out.println("请输入要添加成绩的课程号");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();

        if(courseMapper.selectById(id) != null) {
            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(null, id, null));
            printStudentCourse(studentCourses);

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

    public static void addCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper mapper = sqlSession.getMapper(CourseMapper.class);

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入课程名,容量,教师编号(用逗号分割)");
        String s = sc.nextLine();
        try {
            String[] split = s.split("[,，]");
            Course course = new Course();
            course.setName(split[0]);
            course.setSize(Integer.valueOf(split[1]));
            course.setTeacher(Integer.valueOf(split[2]));
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
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

        List<Course> list = courseMapper.selectAll();
        printCourse(list);

        System.out.println("请输入要删除的编号");
        Scanner sc = new Scanner(System.in);
        Integer id = sc.nextInt();

        courseMapper.deleteById(id);
        System.out.println("删除成功");

        sqlSession.close();
    }
    public static void inputCourse() {

        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入导入文件绝对路径：");
            String s = sc.nextLine();
            File file = new File(s);

            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

            Workbook workbook = Workbook.getWorkbook(file);
            Sheet sheet = workbook.getSheet(0);

            for(int i = 1;i < sheet.getRows();i++) {

                Integer id = Integer.valueOf(sheet.getCell(0, i).getContents());
                String name = sheet.getCell(1, i).getContents();
                Integer size = Integer.valueOf(sheet.getCell(2,i).getContents());
                Integer teacher = Integer.valueOf(sheet.getCell(3, i).getContents());

                if(courseMapper.selectById(id) != null) continue;
                courseMapper.add(new Course(id, name, size,teacher));

            }
            sqlSession.close();
            workbook.close();
            System.out.println("导入成功");
        }
        catch (Exception e) {
            System.out.println("导入失败");
        }
    }
    public static void outputCourse() {
        try {
            SqlSession sqlSession = Util.getSqlSession();
            CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);

            File file = new File("course.xls");

            WritableWorkbook workbook = Workbook.createWorkbook(file);
            WritableSheet sheet = workbook.createSheet("课程信息", 0);

            String[] title = {"课程号","课程名", "容量", "教师编号"};
            Label label;
            for (int i = 0;i < title.length;i++) {
                label = new Label(i, 0, title[i]);
                sheet.addCell(label);
            }

            List<Course> list = courseMapper.selectAll();


            for (int j = 0;j < list.size();j++) {
                sheet.addCell(new Label(0, j+1, list.get(j).getId().toString()));
                sheet.addCell(new Label(1, j+1, list.get(j).getName()));
                sheet.addCell(new Label(2, j+1, list.get(j).getSize().toString()));
                sheet.addCell(new Label(3, j+1, list.get(j).getTeacher().toString()));
            }
            workbook.write();
            workbook.close();
            sqlSession.close();
            System.out.println("导出成功,保存至" + System.getProperty("user.dir") + "\\course.xls");
        }catch (Exception e) {
            System.out.println("导出失败");
        }
    }

    public static void queryCourse() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        Scanner sc = new Scanner(System.in);
        String s;
        while(true) {
            System.out.println("all:查看所有课程,exit:退出查询,其他:查询关键词\n" +
                    "请输入：");
            s = sc.nextLine();

            if(s.equalsIgnoreCase("all"))   viewAllCourse();
            else if(s.equalsIgnoreCase("exit")) break;
            else {
                List<Course> courses = courseMapper.selectAll();
                printCourse(courses, s);
            }
        }
        sqlSession.close();
    }
    public static void viewRelatedCourse(User currentUser) throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        CourseMapper courseMapper = sqlSession.getMapper(CourseMapper.class);
        StudentCourseMapper studentCourseMapper = sqlSession.getMapper(StudentCourseMapper.class);
        List<Course> courses = null;
        if(currentUser.getRole().equals("student")) {
            List<StudentCourse> studentCourses = studentCourseMapper.selectByCondition(new StudentCourse(currentUser.getId(),null,null));
            courses = new ArrayList<>();
            for (StudentCourse i : studentCourses)
                courses.add(courseMapper.selectById(i.getCid()));
        }
        else if(currentUser.getRole().equals("teacher")) {
            courses = courseMapper.selectByCondition(null,null,currentUser.getId());
        }
        printCourse(courses);
        sqlSession.close();
    }
}
