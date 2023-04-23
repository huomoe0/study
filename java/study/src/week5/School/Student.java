package week5.School;

public class Student extends Role {
    private String stuID;
    private String stuClass;

    @Override
    public String toString() {
        return super.toString() + "学号是" + stuID + ", 来自" + stuClass + "。";
    }

    public String getStuID() {
        return stuID;
    }

    public void setStuID(String stuID) {
        this.stuID = stuID;
    }

    public Student(String name, int age, String stuID, String stuClass) {
        super(name, age);
        this.stuID = stuID;
        this.stuClass = stuClass;
    }

    public String getStuClass() {
        return stuClass;
    }

    public void setStuClass(String stuClass) {
        this.stuClass = stuClass;
    }
}
