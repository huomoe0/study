package week4.Project;

public class ProjectDriver {
    public static void main(String[] args) {
        Employee emp1 = new Employee("1001", "tom", "技术部", 20000);

        Employee emp2 = new Employee("1002", "bill", "市场部", 30000);
        Project project = new Project("嫦娥奔月", 2300000, emp1, emp2);
        System.out.println("项目经费" + project.getBudget());
        project.updateSalary();
        System.out.println("提高后的项目经费" + project.getBudget());
        System.out.println("项目细节:\n" + project);
    }


}
