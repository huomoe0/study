import java.sql.*;

public class Test {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        // 1.加载驱动（Driver.class）
        Class.forName("com.mysql.cj.jdbc.Driver"); // 按类名(全名：包名.包名......类名)将一个类加载到内存中
        // 2.建立连接
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/java" +
                "?useUnicode=true&characterEncoding=utf-8&useSSL=false&serverTimezone=GMT", "root", "huomoe0");
        // 3.创建语句
        String sql = "update t_student set gender='女' where id=?";
        PreparedStatement pst = con.prepareStatement(sql);
        // 4.执行语句
        pst.setString(1, "1007");
//        pst.setString(2, "张山");
//        pst.setString(3, "男");
//        pst.setString(4, "上海");
//        pst.setString(5, "2001-4-5 23:");
        int res = pst.executeUpdate(); // 如果是selete，update，insert 返回受影响的条数

        if(res > 0) {
            System.out.println("增加成功");
        }
    }
}
