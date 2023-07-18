package week6.Generate;

public class Generate {
    public static String generate(String cls, String var) {
        String str = "";

        String[] tmp = var.split(",");

        String[][] v = new String[tmp.length][];

        for(int i = 0;i < tmp.length;i++) {
            v[i] = tmp[i].split(" ");
        }

        //构造函数
        str += "public " + cls + "(" + var + ") {\n";
        for(int i = 0;i < v.length;i++) str += "    this." + v[i][1] + " = " + v[i][1] + ";\n";
        str += "}\n";

        //每个变量的setter和getter
        for(int i = 0;i < v.length;i++) {
            str += "public " + v[i][0] + " get" + v[i][1].substring(0,1).toUpperCase() + v[i][1].substring(1) + "() {\n"
                    + "    return " + v[i][1] + ";\n}\n";
            str += "public void set" + v[i][1].substring(0,1).toUpperCase() + v[i][1].substring(1) + "(" + tmp[i] + ") {\n"
                    + "    this." + v[i][1] + " = " + v[i][1] + ";\n}\n";

        }

        return str;
    }
}
