package week7.Sale;

public class GenerateSequence {
    public static String generate(int last) {
        String newNo = "";
        newNo += (last + 1);
        int len = 4 - newNo.length();
        for(int i = 0;i < len;i++) newNo = "0" + newNo;

        return newNo;
    }
}
