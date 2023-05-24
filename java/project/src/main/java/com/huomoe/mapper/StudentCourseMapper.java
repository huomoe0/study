package com.huomoe.mapper;

import com.huomoe.vo.StudentCourse;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;

import java.util.List;

public interface StudentCourseMapper {

    StudentCourse selectById(@Param("uid")Integer uid, @Param("cid")Integer cid);

    List<StudentCourse> selectByCondition(StudentCourse sc);


    void add(StudentCourse sc);

    void add(@Param("uid")Integer uid, @Param("cid")Integer cid, @Param("grade")Double grade);

    void deleteById(@Param("uid")Integer uid, @Param("cid")Integer cid);

    @Update("update tb_studentcourse set grade = #{grade} where uid = #{uid} and cid = #{cid};")
    void update(@Param("uid")Integer uid, @Param("cid")Integer cid, @Param("grade")Double grade);

}
