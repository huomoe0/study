package week3;

public class Employee {
    private String id, name, department;
    private float baseSalary;


    public void setBaseSalary(float baseSalary) {
        this.baseSalary = baseSalary;
    }
    public float getBaseSalary() {
        return this.baseSalary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public void setId(String id) {
        this.id = id;
    }
    public String getId() {
        return this.id;
    }

    public Employee() {

    }

    public Employee(String id, String name, String department, float baseSalary) {
        this.id = id;
        this.name = name;
        this.department = department;
        this.baseSalary = baseSalary;
    }

    public void updateBaseSalary() {
        this.setBaseSalary(this.baseSalary * 1.035f);
    }
    public void display() {
        System.out.println("编号" + id + " ,姓名" + name + " ,部门" + department + " ,基本工资" + baseSalary);
    }

    /*public String toString() {
        String info = "编号\t姓名\t部门\t基本工资\n" + id + "\t" + name + "\t" + department + "\t" + + baseSalary;
        return info;
    }*/
    @Override
    public String toString() {
        return "Employee{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", department='" + department + '\'' +
                ", baseSalary=" + baseSalary +
                '}';
    }
}
