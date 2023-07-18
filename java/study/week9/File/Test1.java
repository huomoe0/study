package week9.File;

import java.io.*;

public class Test1 {
    public static void main(String[] args) throws IOException {
        File file1 = new File("src\\week9\\File\\data.dat");

        FileReader read = new FileReader(file1);

        BufferedReader buf = new BufferedReader(read);

        String info;

        while ((info = buf.readLine()) != null) {
            //System.out.println(info);
            String[] arr = info.split("\t");

            for(String i : arr) {
                System.out.println(i);
            }
        }

        buf.close();
        read.close();

        File file2 = new File("src//week9//File//test.txt");

        FileWriter writer = new FileWriter(file2);

        PrintWriter pw = new PrintWriter(writer);

        String[] outStr = {"aaa", "bbb", "cccc"};

        for (String i : outStr) {
            pw.println(i);
        }

        pw.close();
        writer.close();
        System.out.println("ok");
    }
}
