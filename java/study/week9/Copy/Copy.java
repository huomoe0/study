package week9.Copy;

import java.io.*;

public class Copy {
    public static void main(String[] args) throws IOException {

        System.out.println(System.getProperty("user.dir"));

        File in = new File("src//week9//Copy//question.txt");
        FileReader reader = new FileReader(in);
        BufferedReader bufferedReader = new BufferedReader(reader);

        File out = new File("src//week9//Copy//answer.txt");
        FileWriter writer = new FileWriter(out);
        PrintWriter printWriter = new PrintWriter(writer);

        String s;

        while ((s = bufferedReader.readLine()) != null) {
            printWriter.println(s + " = " + Expression.solve(s));
        }

        bufferedReader.close();
        reader.close();
        printWriter.close();
        writer.close();

    }
}
