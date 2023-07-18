
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;


public class Main {
    public static void main(String[] args) throws InvocationTargetException, IllegalAccessException, NoSuchMethodException, InstantiationException, ClassNotFoundException, NoSuchFieldException {

        Class<?> cls = Class.forName("A");
        Object o = cls.newInstance();
        Field a = cls.getField("a");
        Field b = cls.getDeclaredField("b");
        System.out.println(a.get(o));
        b.setAccessible(true);
        System.out.println(b.get(o));

    }
}

class A {
    public String s = "hi";
    public int a = 1;
    private int b = 2;


    public static void hi() {
        //System.out.println(s);
    }
}


