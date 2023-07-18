package week3;

public class RectangleDriver {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle(3, 4);

        System.out.println("r1的面积 " + r1.getArea());
        System.out.println("r1的周长 " + r1.getPerimeter());

        System.out.println("r2的面积 " + r2.getArea());
        System.out.println("r2的周长 " + r2.getPerimeter());
    }
}
