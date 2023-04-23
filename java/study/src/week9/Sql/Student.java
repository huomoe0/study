package week9.Sql;

public class Student {
    private String id;
    private String name;
    private String sex;
    private String province;
    private String birthday;
    private double grade;

    @Override
    public String toString() {
        return id + "\t" + name + "\t" + sex + "\t" + province + "\t" + birthday + "\t" + grade;
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

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public double getGrade() {
        return grade;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    public Student(String id, String name, String sex, String province, String birthday, double grade) {
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.province = province;
        this.birthday = birthday;
        this.grade = grade;
    }
}
