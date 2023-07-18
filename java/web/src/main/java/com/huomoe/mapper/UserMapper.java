package com.huomoe.mapper;

import com.huomoe.pojo.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

public interface UserMapper {

    @Select("select * from User where username=#{username} and password=#{password}")
    User select(@Param("username") String username,@Param("password") String password);

    @Select("select * from user where username=#{username}")
    User selectByUsername(String username);

    @Insert("insert into user values(#{username},#{password})")
    void add(User user);
}
