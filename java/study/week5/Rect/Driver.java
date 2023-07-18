package week5.Rect;

import java.util.Scanner;
public class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double l, h, z;
        int n;
        n = sc.nextInt();

        while (n-- != 0) {
            l = sc.nextDouble();
            h = sc.nextDouble();
            z = sc.nextDouble();

            Cubic cubic = new Cubic(l, h, z);
            Pyramid pyramid = new Pyramid(l, h, z);

            System.out.println(String.format("%.2f", cubic.area()) + " " + String.format("%.2f", cubic.volume()) + " " +
                    String.format("%.2f", pyramid.area()) + " " + String.format("%.2f", pyramid.volume()));
        }

    }
}
