package com.huomoe.mapper;

import com.huomoe.vo.Course;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface CourseMapper {

    List<Course> selectAll();

    Course selectById(Integer id);

    List<Course> selectByCondition(@Param("id") Integer id, @Param("name") String name, @Param("teacher") Integer teacher);
    List<Course> selectByCondition(Course course);

    void add(Course c);

    void deleteById(Integer id);

}
