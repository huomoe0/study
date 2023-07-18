package week5.Bank;

import java.util.Scanner;

public class BankDriver {
    private static Customer customer;

    public static void main(String[] args) {
        int c;
        do {
            c = menuMain();

            switch (c) {
                case 1: create();break;
                case 2: save();break;
                case 3: withdraw();break;
                case 4: consume();break;
                case 5: repay();break;
                case 6: settle();break;
                case 7: balance();break;
                case 8: break;
                default:
                    System.out.println("请重新输入:");
            }
        } while(c != 8);

    }

    public static void balance() {
        if(customer == null) {
            System.out.println("至少先开通一种卡");
            return;
        }
        System.out.println(customer);

    }
    public static void settle() {
        if(customer == null) {
            System.out.println("至少先开通一种卡");
            return;
        }
        if(customer.getCa() != null) {
            customer.getCa().setBalance(customer.getCa().getBalance() - customer.getCa().getServiceFee());
            System.out.println("信用卡服务费结算，当前余额" + customer.getCa().getBalance());
        }
        if(customer.getSa() != null) {
            customer.getSa().setBalance(customer.getSa().getBalance() * (1 + customer.getSa().getInterestRate()));
            System.out.println("储蓄卡利率结算，当前余额" + customer.getSa().getBalance());
        }
    }
    public static void repay() {
        if(customer == null || customer.getCa() == null) {
            System.out.println("请先开通信用卡");
            return;
        }

        System.out.println("应还" + Math.abs(customer.getCa().getBalance()));
        System.out.println("请输入还款金额：");
        Scanner sc = new Scanner(System.in);
        double money = sc.nextDouble();
        if(money <= 0) {
            System.out.println("还款金额应为正数");
            return;
        }
        customer.getCa().setBalance(customer.getCa().getBalance() + money);
        System.out.println("还款成功，当前余额 " + customer.getCa().getBalance());
    }

    public static void consume() {
        if(customer == null || customer.getCa() == null) {
            System.out.println("请先开通信用卡");
            return;
        }
        System.out.println("请输入消费金额：");
        Scanner sc = new Scanner(System.in);
        double money = sc.nextDouble();
        if(money <= 0) {
            System.out.println("消费金额应为正数");
            return;
        }
        customer.getCa().setBalance(customer.getCa().getBalance() - money);
        System.out.println("消费成功，当前余额 " + customer.getCa().getBalance());
    }
    public static void withdraw() {
        if(customer == null || customer.getSa() == null) {
            System.out.println("请先开通储蓄卡");
            return;
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入取款金额：");
        double money = sc.nextDouble();
        if(money <= 0)  System.out.println("取款金额应为正数");
        else if(customer.getSa().getBalance() <= money) System.out.println("余额不足");
        else {
            customer.getSa().setBalance(customer.getSa().getBalance() - money);
            System.out.println("取款成功，当前余额 " + customer.getSa().getBalance());
        }

    }

    public static void save() {
        if(customer == null || customer.getSa() == null) {
            System.out.println("请先开通储蓄卡");
            return;
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入存款金额：");
        double balance = sc.nextDouble();
        if (balance <= 0) {
            System.out.println("存款金额应为正数");
            return;
        }
        customer.getSa().setBalance(customer.getSa().getBalance() + balance);
        System.out.println("存款成功，当前余额 " + customer.getSa().getBalance());
    }

    public static void create() {
        int c;
        do {
            c = menuCreate();

            switch (c) {
                case 1:createCheckingAccount();break;
                case 2:createSavingAccount();break;
                case 3:break;
                default:
                    System.out.println("请重新输入:");
            }
        }while (c != 3) ;
    }
    public static void createCheckingAccount() {
        if(customer != null &&  customer.getCa() != null) {
            System.out.println("无需重复开信用卡");
            return;
        }
        Scanner sc = new Scanner(System.in);

        if(customer == null) {
            System.out.println("请输入ssn：");
            String ssn = sc.next();
            System.out.println("请输入姓名：");
            String name = sc.next();
            customer = new Customer(ssn, name);
        }

        System.out.println("请输入卡号：");
        String card = sc.next();
        System.out.println("请输入服务费：");
        double fee = sc.nextDouble();


        customer.setCa(new CheckingAccount(card, 0, fee));

        System.out.println("恭喜你，信用卡开设成功");
        System.out.println("信息如下:");
        System.out.println(customer.getCa());
    }
    public static void createSavingAccount() {
        if(customer != null &&  customer.getSa() != null) {
            System.out.println("无需重复开储蓄卡");
            return;
        }
        Scanner sc = new Scanner(System.in);

        if(customer == null) {
            System.out.println("请输入ssn：");
            String ssn = sc.next();
            System.out.println("请输入姓名：");
            String name = sc.next();
            customer = new Customer(ssn, name);
        }

        System.out.println("请输入卡号：");
        String card = sc.next();
        System.out.println("请输入利率：");
        double rate = sc.nextDouble();


        customer.setSa(new SavingAccount(card, 0, rate));

        System.out.println("恭喜你，储蓄卡开设成功");
        System.out.println("信息如下:");
        System.out.println(customer.getSa());
    }

    public static int menuCreate() {
        System.out.println("请选择开卡类型\n1.信用卡\n2.储蓄卡\n3.返回\n请选择（1-3）：");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static int menuMain() {
        System.out.println("欢迎使用银行系统 \n1.开户\n2.存款\n3.取款\n4.消费\n5.还款\n" +
                "6.银行结算\n7.查询余额\n8.退出\n请选择(1-8): ");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }


}
