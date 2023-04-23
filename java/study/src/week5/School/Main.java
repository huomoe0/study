package week5.School;

public class Main {
    public static void main(String[] args) {

        Faculty faculty = new Faculty("张三", 32, "33006", "2021年9月1日", "讲师");
        Staff staff = new Staff("王五", 27, "32011", "2017年7月23日", "教务员");
        Student stu = new Student("李四", 19, "20201103", "202011班");

        System.out.println(faculty);
        System.out.println(staff);
        System.out.println(stu);
    }
}
