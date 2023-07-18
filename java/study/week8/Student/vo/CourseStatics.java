package week8.Student.vo;

public class CourseStatics {
    private String courseName;
    private int count;
    private double avg;

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    @Override
    public String toString() {
        return courseName + "\t" + count + "\t" + avg;
    }

    public CourseStatics() {
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public double getAvg() {
        return avg;
    }

    public void setAvg(double avg) {
        this.avg = avg;
    }

    public CourseStatics(String courseName, int count, double avg) {
        this.courseName = courseName;
        this.count = count;
        this.avg = avg;
    }
}
