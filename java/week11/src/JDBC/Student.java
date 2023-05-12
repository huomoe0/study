package JDBC;

public class Student {
    private String id;
    private String name;
    private String gender;
    private String province;
    private String birth;

    @Override
    public String toString() {
        return id + "," + name + "," + gender + "," + province + "," + birth;
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

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public String getBirth() {
        return birth;
    }

    public void setBirth(String birth) {
        this.birth = birth;
    }

    public Student(String id, String name, String gender, String province, String birth) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.province = province;
        this.birth = birth;
    }
}
