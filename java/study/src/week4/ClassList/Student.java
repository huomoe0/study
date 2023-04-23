package week4.ClassList;

public class Student {
    private String studentID;
    private String studentName;
    private String studentClass;

    public Student() {

    }

    public String getStudentName() {
        return studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }

    public String getStudentClass() {
        return studentClass;
    }

    public void setStudentClass(String studentclass) {
        this.studentClass = studentclass;
    }

    public Student(String studentID, String studentName, String studentclass) {
        this.studentID = studentID;
        this.studentName = studentName;
        this.studentClass = studentclass;
    }

    public String getStudentID() {
        return studentID;
    }

    public void setStudentID(String studentID) {
        this.studentID = studentID;
    }

    @Override
    public String toString() {
        return studentID + "\t" + studentName + "\t" + studentClass;
    }


}
