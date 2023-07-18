package week5.Bank;

public class CheckingAccount extends BankAccount{
    private double serviceFee;

    public double getServiceFee() {
        return serviceFee;
    }

    public void setServiceFee(double serviceFee) {
        this.serviceFee = serviceFee;
    }

    @Override
    public String toString() {
        return "信用卡\n" + super.toString() + "\n服务费：" + serviceFee;
    }

    public CheckingAccount(String accountNo, double balance, double serviceFee) {
        super(accountNo, balance);
        this.serviceFee = serviceFee;
    }
}
