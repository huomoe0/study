package week5.Employee;

public class Employee {
    private String name;
    private String EmployeeID;
    private String department;
    private double baseSalary;

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", EmployeeID='" + EmployeeID + '\'' +
                ", department='" + department + '\'' +
                ", baseSalary=" + baseSalary +
                '}';
    }
    public void displayEmployee() {
        System.out.println(this);
    }
    public Employee() {
    }

    public Employee(String name, String employeeID, String department, double baseSalary) {
        this.name = name;
        EmployeeID = employeeID;
        this.department = department;
        this.baseSalary = baseSalary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmployeeID() {
        return EmployeeID;
    }

    public void setEmployeeID(String employeeID) {
        EmployeeID = employeeID;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    public void updateSalary() {
        baseSalary *= 1.0725;
    }
    public void updateSalary(double rate) {
        this.baseSalary *= 1 + rate;
    }
}
