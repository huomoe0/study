package week3;

public class Student {
    private String name;
    private int phone;
    private int id;

    public Student(String name, int phone, int id) {
        this.name = name;
        this.phone = phone;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPhone() {
        return phone;
    }

    public void setPhone(int phone) {
        this.phone = phone;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void displayStudent() {
        System.out.println("姓名 " + name);
        System.out.println("电话 " + phone);
        System.out.println("学号 " + id);
    }
}
