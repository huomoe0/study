package week5.Bank;

public class Customer {
    private String ssn;
    private String name;
    private SavingAccount sa;
    private CheckingAccount ca;

    @Override
    public String toString() {
        String info = "个人信息\n" + "ssn：" + ssn + "\n姓名：" + name;
        if(ca != null) info += "\n" + ca;
        else info += "无信用卡";
        if(sa != null) info += "\n" + sa;
        else info += "无储蓄卡";
        return info;
    }

    public Customer(String ssn, String name) {
        this.ssn = ssn;
        this.name = name;
    }

    public String getSsn() {
        return ssn;
    }

    public void setSsn(String ssn) {
        this.ssn = ssn;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public SavingAccount getSa() {
        return sa;
    }

    public void setSa(SavingAccount sa) {
        this.sa = sa;
    }

    public CheckingAccount getCa() {
        return ca;
    }

    public void setCa(CheckingAccount ca) {
        this.ca = ca;
    }

    public Customer(String ssn, String name, SavingAccount sa, CheckingAccount ca) {
        this.ssn = ssn;
        this.name = name;
        this.sa = sa;
        this.ca = ca;
    }
}
