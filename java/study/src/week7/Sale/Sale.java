package week7.Sale;

public class Sale {
    private String name;
    private String lsh;
    private double price;
    private int count;
    private double total;

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return lsh + "\t" + name + "\t\t" + count + "\t" + price + "\t" + total;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLsh() {
        return lsh;
    }

    public void setLsh(String lsh) {
        this.lsh = lsh;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public Sale(String name, String lsh, double price, int count, double total) {
        this.name = name;
        this.lsh = lsh;
        this.price = price;
        this.count = count;
        this.total = total;
    }
}
