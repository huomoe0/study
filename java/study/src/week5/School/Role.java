package week5.School;

public class Role {
    private String name;
    private int age;

    public Role(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Role() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "我是" + name + ", 年龄" + age + "岁。 ";
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
