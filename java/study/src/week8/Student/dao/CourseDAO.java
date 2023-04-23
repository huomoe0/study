package week8.Student.dao;

import week8.Student.vo.Course;
import week8.Student.vo.CourseStatics;
import week8.Student.vo.Student;

import java.util.ArrayList;
import java.util.Scanner;

public class CourseDAO {
    public static ArrayList<Student> inputStudent() {
        ArrayList<Student> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        String tmp = sc.nextLine();

        while (!tmp.equals("end")) {
            String[] s = tmp.split("[,，]");
            list.add(new Student(s[0], s[1], s[2], 0));
            tmp = sc.nextLine();
        }

        return list;
    }
    public static ArrayList<Course> inputCourse() {
        ArrayList<Course> listCourse = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        String tmp = sc.nextLine();

        while (!tmp.equals("end")) {
            String[] s = tmp.split("[,，]");
            listCourse.add(new Course(s[0], s[1], Double.parseDouble(s[2])));
            tmp = sc.nextLine();
        }
        return listCourse;
    }

    public static void calStudentAvg(ArrayList<Student> list, ArrayList<Course> listCourse) {
        double[] sum = new double[list.size()];
        int[] count = new int[list.size()];

        for(Course i : listCourse) {
            for(int j = 0;j < list.size();j++) {
                if(i.getId().equals(list.get(j).getId())) {
                    sum[j] += i.getScore();
                    count[j]++;
                }
            }
        }

        for(int i = 0;i < sum.length;i++) {
            if(count[i] != 0) {
                Student s = list.get(i);
                list.get(i).setAvg(sum[i] / count[i]);
            }
        }

    }
    private static ArrayList<CourseStatics> getCourse(ArrayList<Course> listCourse) {
        ArrayList<CourseStatics> list = new ArrayList<>();

        for(Course i : listCourse) {
            boolean isfind = false;
            for (CourseStatics courseStatics : list) {
                if (courseStatics.getCourseName().equals(i.getCourseName())) {
                    isfind = true;
                    break;
                }
            }
            if(!isfind) {
                list.add(new CourseStatics(i.getCourseName(), 0, 0));
            }
        }

        return list;
    }
    public static ArrayList<CourseStatics> calCourseAvg(ArrayList<Course> listCourse) {
        ArrayList<CourseStatics> list = getCourse(listCourse);


        for(Course i : listCourse) {
            for(int j = 0;j < list.size();j++) {
                if(list.get(j).getCourseName().equals(i.getCourseName())) {
                    list.get(j).setCount(list.get(j).getCount() + 1);
                    list.get(j).setAvg(list.get(j).getAvg() + i.getScore());
                    break;
                }
            }
        }

        for(int j = 0;j < list.size();j++) {
            list.get(j).setAvg(list.get(j).getAvg() / list.get(j).getCount());
        }

        return list;
    }
}
