package week5.School;

public class Faculty extends Employee{
    private String zc;


    @Override
    public String toString() {
        return super.toString() + "是一名教师, " + zc + "职称。";
    }

    public Faculty(String name, int age, String employeeID, String date, String zc) {
        super(name, age, employeeID, date);
        this.zc = zc;
    }

    public String getZc() {
        return zc;
    }

    public void setZc(String zc) {
        this.zc = zc;
    }
}
