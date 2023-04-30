public class CourseStatistic {
    private String sid;
    private String cname;
    private double grade;


    public String getCname() {
        return cname;
    }

    public void setCname(String cname) {
        this.cname = cname;
    }

    public double getGrade() {
        return grade;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    public String getSid() {
        return sid;
    }

    public void setSid(String sid) {
        this.sid = sid;
    }

    public CourseStatistic(String sid, String cname, double grade) {
        this.sid = sid;
        this.cname = cname;
        this.grade = grade;
    }
}
