package week8.Student.vo;

// 用于输入数据的存放，用于处理结果的存放
public class Student {
    private String id;
    private String name;

    private String gender;
    private double avg;

    @Override
    public String toString() {
        return id + "\t" + name + "\t" + gender + "\t" + avg;
    }

    public Student() {
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public double getAvg() {
        return avg;
    }

    public void setAvg(double avg) {
        this.avg = avg;
    }

    public Student(String id, String name, String gender, double avg) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.avg = avg;
    }
}
