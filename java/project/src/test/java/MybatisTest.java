import com.huomoe.mapper.StudentCourseMapper;
import com.huomoe.mapper.UserMapper;
import com.huomoe.util.Encrypt;
import com.huomoe.util.Util;
import com.huomoe.vo.StudentCourse;
import com.huomoe.vo.User;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.io.IOException;

public class MybatisTest {




    @Test
    public void testAdd() throws IOException {
        SqlSession sqlSession = Util.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        Integer id = 1005;
        String name = "test1";
        String username = "test1";
        String password = "123456";
        String role = "学生";
        User user = new User();
        //user.setId(id);
        user.setName(name);
        user.setUsername(username);
        user.setPassword(password);
        user.setRole(role);

        mapper.add(user);

        System.out.println(user.getId());

        sqlSession.close();
    }
}
