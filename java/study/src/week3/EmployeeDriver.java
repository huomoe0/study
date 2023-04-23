package week3;

public class EmployeeDriver {
    public static void main(String[] args) {
        Employee emp1 = new Employee();
        Employee emp2 = new Employee("1001", "", "", 5800f);

        emp1.setBaseSalary(2000);

        System.out.println("员工1基本薪水" + emp1.getBaseSalary());
        System.out.println("员工2基本薪水" + emp2.getBaseSalary());

        emp1.updateBaseSalary();
        emp2.updateBaseSalary();

        System.out.println(emp1.toString());
        System.out.println(emp2.toString());

    }
}
