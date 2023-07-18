package week5.Bank;

public class SavingAccount extends BankAccount{
    private double interestRate;

    @Override
    public String toString() {
        return "储蓄卡\n" + super.toString() + "\n利率：" + interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    public SavingAccount(String accountNo, double balance, double interestRate) {
        super(accountNo, balance);
        this.interestRate = interestRate;
    }
}
