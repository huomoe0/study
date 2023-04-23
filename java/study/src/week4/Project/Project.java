package week4.Project;

public class Project {
    private String projectName;
    private double budget;
    private Employee emp1;
    private Employee emp2;

    @Override
    public String toString() {
        return "项目名称 " + projectName + "\n"
        + "预算 " + budget + "\n"
                + "项目成员\n"
                + "员工号\t姓名\t部门\t薪水\n" + emp1.toString() + "\n" + emp2.toString();
    }

    public void updateSalary() {
        this.budget *= 1.2;
    }

    public Project(String projectName, double budget, Employee emp1, Employee emp2) {
        this.projectName = projectName;
        this.budget = budget;
        this.emp1 = emp1;
        this.emp2 = emp2;
    }

    public String getProjectName() {
        return projectName;
    }

    public void setProjectName(String projectName) {
        this.projectName = projectName;
    }

    public double getBudget() {
        return budget;
    }

    public void setBudget(double budget) {
        this.budget = budget;
    }

    public Employee getEmp1() {
        return emp1;
    }

    public void setEmp1(Employee emp1) {
        this.emp1 = emp1;
    }

    public Employee getEmp2() {
        return emp2;
    }

    public void setEmp2(Employee emp2) {
        this.emp2 = emp2;
    }

    public Project() {
    }
}
