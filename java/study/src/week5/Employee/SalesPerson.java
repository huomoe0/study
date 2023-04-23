package week5.Employee;

public class SalesPerson extends Employee{
    private double yearlySales;


    public double getYearlySales() {
        return yearlySales;
    }

    public void setYearlySales(double yearlySales) {
        this.yearlySales = yearlySales;
    }

    public SalesPerson(String name, String employeeID, String department, double baseSalary, double yearlySales) {
        super(name, employeeID, department, baseSalary);
        this.yearlySales = yearlySales;
    }

    public void updateSalary() {
        setBaseSalary(super.getBaseSalary() + this.yearlySales * 0.1);
    }
}
