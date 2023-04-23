package week5.Bank;

public class BankAccount {
    private String accountNo;
    private double balance;

    public String getAccountNo() {
        return accountNo;
    }

    @Override
    public String toString() {
        return "卡号：" + accountNo + "\n余额：" + balance;
    }

    public void setAccountNo(String accountNo) {
        this.accountNo = accountNo;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public BankAccount(String accountNo, double balance) {
        this.accountNo = accountNo;
        this.balance = balance;
    }
}
