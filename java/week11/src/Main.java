import JDBC.JDBCUtil;

import java.sql.*;

public class Main {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // 1.加载驱动（Driver.class）
        Class.forName("com.mysql.cj.jdbc.Driver"); // 按类名(全名：包名.包名......类名)将一个类加载到内存中
        // 2.建立连接
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/java" +
                "?useUnicode=true&characterEncoding=utf-8&useSSL=false&serverTimezone=GMT", "root", "huomoe0");
        // 3.创建语句
        String sql = "select gender, count(*) as cnt from `t_student` group by gender";
        PreparedStatement pst = con.prepareStatement(sql);
        // 4.执行语句
//        pst.setString(1, "湖北");
//        pst.setString(2, "男"); // 如果语句中有问号,则执行前需要先对？赋值，按顺序依次为1，2，3......
        ResultSet res = pst.executeQuery();
        // 5.结果处理
        while (res.next()) {
//            String id = res.getString("id");
//            String name = res.getString("name");
            String gender = res.getString("gender");
//            String province = res.getString("province");
//            String birth = res.getString("birth");
            int count = res.getInt("cnt");
            //System.out.println(id + "\t" + name + "\t" + gender + "\t" + province + "\t" + birth);
            System.out.println(gender + "\t" + count);
        }
        // 6.资源释放
        res.close();
        pst.close();
        con.close();

    }
}
