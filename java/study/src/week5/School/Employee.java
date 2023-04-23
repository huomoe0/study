package week5.School;

public class Employee extends Role{
    private String employeeID;
    private String date;

    @Override
    public String toString() {
        return super.toString() + "工号是" + employeeID + ", " + date + "入职。 ";
    }
    public String getEmployeeID() {
        return employeeID;
    }

    public void setEmployeeID(String employeeID) {
        this.employeeID = employeeID;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public Employee(String name, int age, String employeeID, String date) {
        super(name, age);
        this.employeeID = employeeID;
        this.date = date;
    }
}
