package week3;

public class StudentDriver {
    public static void main(String[] args) {
        Student a1 = new Student("l", 123, 1000);
        Student a2 = new Student("a", 1432411, 10001);

        a2.setId(1001);

        a1.displayStudent();
        a2.displayStudent();

    }
}
