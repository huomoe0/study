package week7.Test;

import java.util.ArrayList;


public class StudentDriver {
    public static void main(String[] args) {
        ArrayList<Student> list = StudentDAO.input();

        int count = StudentDAO.total(list);
        int maleCount = StudentDAO.totalByGender(list, "男");
        int femaleCount = StudentDAO.totalByGender(list, "女");
        ArrayList<Result> listResult = StudentDAO.totalProvince(list);

        System.out.println("总人数：" + count + "人");
        System.out.println("其中男：" + maleCount + "人，" + (maleCount * 100.0/ count) + "%，女：" + femaleCount + "人，" + (femaleCount * 100.0/ count));
        System.out.println("学生来自于以下省份：");
        for (Result result : listResult) {
            System.out.println(result);
        }
    }
}
