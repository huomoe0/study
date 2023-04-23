package week5.Rect;

public class Cubic extends Rect{ //长方形
    public Cubic(double l, double h, double z) {
        super(l, h, z);
    }
    @Override
    public double area() {
        return 2 * (getL()*getH() + getL()*getZ() + getH()*getZ());
    }
    public double volume() {
        return getL()*getZ()*getH();
    }

}
