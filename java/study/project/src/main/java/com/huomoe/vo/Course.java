package com.huomoe.vo;

public class Course {
    private Integer id;
    private String name;
    private Integer size;
    private Integer teacher;


    public Course() {}
    @Override
    public String toString() {
        return id + "\t" + name + "\t" + size + "\t" + teacher;
    }
    public Course(Integer id, String name,Integer size,Integer teacher) {
        this.id = id;
        this.name = name;
        this.teacher = teacher;
        this.size = size;
    }

    public Integer getSize() {
        return size;
    }

    public void setSize(Integer size) {
        this.size = size;
    }

    public Integer getTeacher() {
        return teacher;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }



    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setTeacher(Integer teacher) {
        this.teacher = teacher;
    }


}
