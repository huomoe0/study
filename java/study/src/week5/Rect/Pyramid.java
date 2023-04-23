package week5.Rect;

public class Pyramid extends Rect{ //四棱锥
    public Pyramid(double l, double h, double z) {
        super(l, h, z);
    }

    @Override
    public double area() {
        double h1 = Math.sqrt(getZ()*getZ() + getH()*getH() / 4), h2 = Math.sqrt(getZ()*getZ() + getL()*getL() / 4);
        return h2 * getH() + h1 * getL() + super.area();
    }
    public double volume() {
        return super.area() * getZ() / 3;
    }

}
