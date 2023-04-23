package week6.Password;

public class Password {
    public String check(String pass) {
        String info = "";
        boolean len = false, upper = false, lower = false, space = false, digit = false;

        if(pass.length() >= 8 && pass.length() <= 15) len = true;

        for(int i = 0;i < pass.length();i++) {
            char c = pass.charAt(i);
            if(c == ' ')  space = true;
            if(c >= 'A' && c <= 'Z')    upper = true;
            if(c >= 'a' && c <= 'z')    lower = true;
            if(c >= '0' && c <= '9')    digit = true;
        }

        if(!len)    info += "长度不合格\n";
        if(!upper)  info += "密码至少有一个大写字母\n";
        if(!lower)  info += "密码至少有一个小写字母\n";
        if(space)   info += "密码不能有空格\n";
        if(!digit)  info += "密码至少有一个数字\n";
        return info;
    }
}
