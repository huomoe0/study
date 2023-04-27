package week10.FileCopy;

import java.io.*;
import java.util.Scanner;

public class Copy {
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);

        System.out.println("请输入待拷贝文件完整路径（分隔符采取/）");

        File in = new File(sc.nextLine());
        File out;


        if(in.exists()) {
            System.out.println("请输入目标文件完整路径（分隔符采取/）");

            out = new File(sc.nextLine());

            if(out.exists()) {
                FileInputStream fis = new FileInputStream(in);
                FileOutputStream fos = new FileOutputStream(out);

                System.out.println("目标文件已存在，是否替换y/n");
                String tmp = sc.nextLine();
                if(tmp.equalsIgnoreCase("y")) {


                    byte[] s = new byte[1024];
                    int len;
                    while ((len = fis.read(s)) != -1) {
                        fos.write(s, 0, len);
                    }


                }
                fis.close();
                fos.close();
            }
            else {
                copy(in, out);
            }

        }
        else {
            System.out.println("文件不存在");
        }
    }
    public static void copy(File in, File out) throws IOException {
        FileInputStream fis = new FileInputStream(in);
        FileOutputStream fos = new FileOutputStream(out);
        byte[] s = new byte[1024];
        int len;
        while ((len = fis.read(s)) != -1) {
            fos.write(s, 0, len);
        }
        fis.close();
        fos.close();
    }
}
