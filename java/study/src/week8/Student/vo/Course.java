package week8.Student.vo;

public class Course {
    private String id;
    private String courseName;
    private double score;
    public Course() {
    }

    public Course(String id, String courseName, double score) {
        this.id = id;
        this.courseName = courseName;
        this.score = score;
    }



    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public double getScore() {
        return score;
    }

    public void setScore(double score) {
        this.score = score;
    }



}
