package week5.Employee;

public class Driver {
    public static void main(String[] args) {
        Administrator administrator = new Administrator("张三", "1001", "董事会", 10000, 5000);

        System.out.println(administrator.getBaseSalary());
        administrator.updateSalary();
        System.out.println(administrator.getBaseSalary());
        System.out.println(administrator);

        SalesPerson salesPerson = new SalesPerson("李四", "1002", "员工", 3000, 20000);
        System.out.println(salesPerson.getBaseSalary());
        salesPerson.updateSalary();
        System.out.println(salesPerson.getBaseSalary());
        System.out.println(salesPerson);

    }
}

