package week5.School;

public class Staff extends Employee{
    private String zw;

    @Override
    public String toString() {
        return super.toString() + "是一名" + zw + "。";
    }

    public Staff(String name, int age, String employeeID, String date, String zw) {
        super(name, age, employeeID, date);
        this.zw = zw;
    }

    public String getZw() {
        return zw;
    }

    public void setZw(String zw) {
        this.zw = zw;
    }
}
