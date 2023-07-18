package week4.System;


public class SubjectEnrolment {
    private int semester;
    private int year;
    private Subject subj;
    private Student[] stu;

    @Override
    public String toString() {
        String info = "学年 " + year + "\n" + "学期 " + semester + "\n" + subj + "\n" + "学号\t姓名\t班级\n";
        for(int i = 0;i < stu.length && stu[i] != null; i++) {
            info += stu[i] + "\n";
        }
        return info;
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

    public Student[] getStu() {
        return stu;
    }

    public void setStu(Student[] stu) {
        this.stu = stu;
    }

    public SubjectEnrolment() {
    }

    public SubjectEnrolment(int semester, int year, Subject subj, Student[] stu) {
        this.semester = semester;
        this.year = year;
        this.subj = subj;
        this.stu = stu;
    }
}
