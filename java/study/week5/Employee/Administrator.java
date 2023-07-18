package week5.Employee;

public class Administrator extends Employee{
    private double bonus;

    public Administrator(String name, String employeeID, String department, double baseSalary, double bonus) {
        super(name, employeeID, department, baseSalary);
        this.bonus = bonus;
    }

    public double getBonus() {
        return this.bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }
    public void updateSalary() {
        setBaseSalary(super.getBaseSalary() + this.bonus);
    }

    @Override
    public String toString() {
        return "Administrator{" +
                "bonus=" + bonus +
                "} " + super.toString();
    }
}
