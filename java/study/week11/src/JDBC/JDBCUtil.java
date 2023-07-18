package JDBC;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class JDBCUtil {
    // 静态代码块 只会执行一次
    static {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection("jdbc:mysql://localhost:3306/java" +
                "?useUnicode=true&characterEncoding=utf-8&useSSL=false&serverTimezone=GMT", "root", "huomoe0");

    }

    public static void close(Connection con) throws SQLException {
        if(con != null) {
            con.close();
        }
    }
}
