package week9.Copy;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Expression {
    public static int solve(String s) {

        Pattern p = Pattern.compile(    "([a-zA-Z]+)\\(\\s*([-0-9]+)\\s*(,\\s*([-0-9]+)\\s*)*\\s*\\)"       );

        int a1 = 0, a2 = 0;

        Matcher m = p.matcher(s);
        while (m.find()) {

            s = s.replace(m.group(), String.valueOf(calculate(m.group())));

            m = p.matcher(s);

        }

      return Integer.parseInt(s);
    }

    private static int calculate(String s) {
        int res = 0;
        Matcher m = Pattern.compile(    "([a-zA-Z]+)\\(\\s*([-0-9]+)\\s*(,\\s*([-0-9]+)\\s*)*\\s*\\)"       ).matcher(s);
        m.find();
        int a1 = Integer.parseInt(m.group(2)), a2 = 0;


        if(!m.group(1).equals("doubleMe"))
            a2 = Integer.parseInt(m.group(4));

        switch (m.group(1)) {
            case "add":res = a1+a2;break;
            case "sub":res = a1-a2;break;
            case "max":res = a1>a2?a1:a2;break;
            case "min":res = a1<a2?a1:a2;break;
            case "doubleMe":res = 2*a1;break;
            case "muti":res = a1*a2;break;
            case "div":res = a1/a2;break;
            default:break;
        }
        return res;
    }
}
