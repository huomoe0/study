package week6.Expression;

public class Express {
    public static double cal(String str) {
        double result = 0;

        String op = str.substring(0, str.indexOf('('));
        String num1Str, num2Str;
        double num1, num2 = 0;
        if(op.equals("doubleMe")) {
            num1Str = str.substring(str.indexOf('(') + 1, str.indexOf(')'));
            num1 = Double.parseDouble(num1Str);


        }
        else {
            num1Str = str.substring(str.indexOf('(') + 1, str.indexOf(','));
            num2Str = str.substring(str.indexOf(',') + 1, str.indexOf(')'));
            num1 = Double.parseDouble(num1Str);
            num2 = Double.parseDouble(num2Str);

        }
        switch (op) {
            case "add": result = num1 + num2; break;
            case "sub": result = num1 - num2;break;
            case "max": result = num1 > num2 ? num1 : num2;break;
            case "min": result = num1 < num2 ? num1 : num2;break;
            case "doubleMe": result = 2*num1; break;
            default:
                System.out.println("该操作暂不支持");
                break;
        }

        return result;
    }
}
