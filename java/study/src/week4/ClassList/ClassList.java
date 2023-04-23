package week4.ClassList;

public class ClassList {
    private int semester;
    private int year;
    private Subject subj;
    private Student s1;
    private Student s2;

    @Override
    public String toString() {
        return "学年 " + year + "\n"
                + "学期 " + semester + "\n"
                + "课程信息\n" + subj + "\n"
                + "学号\t姓名\t班级\n" + s1 + "\n" + s2;
    }

    public ClassList(int semester, int year, Subject subj, Student s1, Student s2) {
        this.semester = semester;
        this.year = year;
        this.subj = subj;
        this.s1 = s1;
        this.s2 = s2;
    }

    public ClassList() {
    }

    public int getSemester() {
        return semester;
    }

    public void setSemester(int semester) {
        this.semester = semester;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public Subject getSubj() {
        return subj;
    }

    public void setSubj(Subject subj) {
        this.subj = subj;
    }

    public Student getS1() {
        return s1;
    }

    public void setS1(Student s1) {
        this.s1 = s1;
    }

    public Student getS2() {
        return s2;
    }

    public void setS2(Student s2) {
        this.s2 = s2;
    }
}
