package com.huomoe.mapper;

import com.huomoe.vo.User;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

public interface UserMapper {

    List<User> selectAll();


    @Select("select * from tb_user where id = #{id}")
    User selectById(Integer id);

    User checkAccount(@Param("id") Integer id, @Param("password") String password);

    @Update("update tb_user set password = #{password} where id = #{id}")
    void update(@Param("id")Integer id, @Param("password")String password);

    void add(User user);

    void deleteById(Integer id);
}
