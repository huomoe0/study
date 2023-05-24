package com.huomoe.vo;

public class StudentCourse {
    private Integer uid;
    private Integer cid;
    private Double grade;
    public Integer getUid() {
        return uid;
    }
    public void setUid(Integer uid) {
        this.uid = uid;
    }
    public Integer getCid() {
        return cid;
    }
    public void setCid(Integer cid) {
        this.cid = cid;
    }
    public Double getGrade() {
        return grade;
    }
    public void setGrade(Double grade) {
        this.grade = grade;
    }
    public StudentCourse(Integer uid, Integer cid, Double grade) {
        this.uid = uid;
        this.cid = cid;
        this.grade = grade;
    }
}
