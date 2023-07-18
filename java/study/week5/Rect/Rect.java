package week5.Rect;

public class Rect {
    private double l,h,z;

    public double length() {
        return 2 * (l + h);
    }
    public double area() {
        return l * h;
    }
    public double getL() {
        return l;
    }

    public void setL(double l) {
        this.l = l;
    }

    public double getH() {
        return h;
    }


    public void setH(double h) {
        this.h = h;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    public Rect(double l, double h, double z) {
        if(l <= 0 || h <= 0 || z <= 0) {
            l = 0;
            h = 0;
            z = 0;
        }
        this.l = l;
        this.h = h;
        this.z = z;
    }
}
