package week8.Student;

import week8.Student.dao.CourseDAO;
import week8.Student.vo.Course;
import week8.Student.vo.CourseStatics;
import week8.Student.vo.Student;

import java.util.ArrayList;


public class Driver {
    public static void main(String[] args) {
        ArrayList<Student> list = CourseDAO.inputStudent();
        ArrayList<Course> listCourse = CourseDAO.inputCourse();

        CourseDAO.calStudentAvg(list, listCourse);

        ArrayList<CourseStatics> listStatics = CourseDAO.calCourseAvg(listCourse);

        System.out.println("按学生统计：");
        System.out.println("学号\t\t姓名\t性别\t平均分");
        for (Student student : list) {
            System.out.println(student);
        }
        System.out.println("按课程统计：");
        System.out.println("课程名称\t选课人数\t平均分");
        for(CourseStatics i : listStatics) {
            System.out.println(i);
        }

        
    }
}
