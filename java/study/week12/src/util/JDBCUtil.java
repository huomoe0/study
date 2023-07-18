package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class JDBCUtil {
    public static String driverName="";
    public static String url = "";
    public static String user = "";
    public static String password = "";
    // 静态代码块 只会执行一次
    static {
        try {

            Class.forName(driverName);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);

    }

    public static void close(Connection con) throws SQLException {
        if(con != null) {
            con.close();
        }
    }
}
