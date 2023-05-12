package dao;

import util.Encrypt;
import util.JDBCUtil;
import vo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

//一般都是CURD
public class UserDAO {
    //查询：返回对象，查询参数存放在User对象中，返回查询结果（最多一个），如果=null，表示没找到
    public static User get(User userCondition) throws SQLException {
    	
        User userResult = null;
        Connection con = JDBCUtil.getConnection();
        String sql = "select * from users where userName=?";
        PreparedStatement pst = con.prepareStatement(sql);

        pst.setString(1, userCondition.getUserName());
        ResultSet res = pst.executeQuery();

        if(res.next()) {
            String password = res.getString("password");
            if(password.equals(Encrypt.MD5(userCondition.getPassword()))) {
                userResult = new User();
                userResult.setUserName(res.getString("userName"));
                userResult.setPassword(userResult.getPassword());
                userResult.setChrName(res.getString("chrName"));
                userResult.setRole(res.getString("role"));
            }
        }
        res.close();
        pst.close();
        con.close();
        return userResult;
    }

    //按条件进行查询，查询结果可能有多条，放在集合中返回
    public static ArrayList<User> query(User userCondition) {
        ArrayList<User> listResult = new ArrayList<>();

        return listResult;
    }
    //修改用户，待修改的信息存放在user对象中
    public static boolean update(User user) {
        boolean ret = false;

        return ret;
    }

    public static boolean insert(User user) {
        boolean ret = false;

        return ret;
    }

    public static boolean delete(String id) {
        boolean ret = false;

        return ret;
    }
}
