package week7.Test;

import java.util.ArrayList;
import java.util.Scanner;

// 业务逻辑操作的封装
public class StudentDAO {
    public static ArrayList<Student> input() {
        ArrayList<Student> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入学生基本信息：（每个学生一行，输入格式为“学号，姓名，性别，省份”，如“001，张三，男，湖北”，当输入“end”时结束输入）");
        String s = sc.nextLine();

        while(!s.equals("end")) {
            String[] tmp = s.split("[,，]");
            Student stu = new Student(tmp[0], tmp[1], tmp[2], tmp[3]);
            list.add(stu);

            s = sc.nextLine();
        }

        return list;
    }

    public static int total(ArrayList<Student> list) {
        return list.size();
    }

    public static int totalByGender(ArrayList<Student> list, String gender) {
        int count = 0;

        for(Student i : list) {
            if(i.getGender().equals(gender))    count++;
        }

        return count;
    }

    public static ArrayList<Result> totalProvince(ArrayList<Student> list) {
        ArrayList<Result> listResult = new ArrayList<>();

        for (Student stu : list) {
            String province = stu.getProvince();
            String name = stu.getName();

            int pos = findProvince(listResult, province);

            if(pos == -1) {
                Result res = new Result(province, 1, name);
                listResult.add(res);
            }
            else {
                Result oldResult = listResult.get(pos);
                Result newResult = new Result(province, oldResult.getCount()+1, oldResult.getNames()+ "，" + name);
                listResult.set(pos, newResult);
            }

        }

        return listResult;
    }

    private static int findProvince(ArrayList<Result> listResult, String province) {
        for(int i = 0;i < listResult.size();i++) {
            if(listResult.get(i).getProvince().equals(province))    return i;
        }
        return -1;
    }
}
