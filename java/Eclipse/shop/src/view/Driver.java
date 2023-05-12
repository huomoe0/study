package view;

import dao.UserDAO;
import vo.User;

import java.sql.SQLException;

public class Driver {
    public static void main(String[] args) throws SQLException {
        User user = login();

        if(user == null) { //登录失败
            System.out.println("很遗憾，您已经到达最大尝试次数，不能登录，程序退出");
        }
        else {
        
        	
        }
    }
    public static User login() throws SQLException {
        User user = null;
        int lastTimes = 3;
        while(lastTimes != 0) {
            lastTimes--;
            String userName = "";
            String password = "";

            User userCondition = new User();
            userCondition.setUserName(userName);
            userCondition.setPassword(password);
            user = UserDAO.get(userCondition);

            if(user != null) {
                break;
            }
            else {
                System.out.println("用户名或密码不正确，你还剩下" + lastTimes + "次机会");
            }
        }
        return user;

    }

}
