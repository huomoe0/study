package week9.Random;

import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class Exp {

    public static void main(String[] args) throws IOException {
        File question = new File("src//week9//Random//question.txt");
        File answer = new File("src//week9//Random//answer.txt");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        generate(question, n);

        solve(question, answer);


    }

    private static void generate(File file, int n) throws IOException {
        String[] operator = {"add", "sub", "muti", "div", "max", "min", "doubleMe"};
        FileWriter writer = new FileWriter(file);
        PrintWriter pw = new PrintWriter(writer);
        Random random = new Random();

        while (n != 0) {
            int op = random.nextInt(operator.length), n1 = random.nextInt(1001), n2 = random.nextInt(1001);

            if(operator[op].equals("div") && n2 == 0)   continue;

            String s = operator[op];

            if(s.equals("doubleMe"))    s += "(" + n1 + ")";
            else s += "(" + n1 + "," + n2 + ")";

            pw.println(s);
            n--;
        }

        pw.close();
        writer.close();
    }

    private static void solve(File question, File answer) throws IOException {
        answer.createNewFile();
        FileReader reader = new FileReader(question);
        FileWriter writer = new FileWriter(answer);
        BufferedReader bufferedReader = new BufferedReader(reader);
        PrintWriter printWriter = new PrintWriter(writer);
        String s;

        while ((s = bufferedReader.readLine()) != null) {
            printWriter.println(s + "=" + Expression.solve(s));
        }



        bufferedReader.close();
        reader.close();
        printWriter.close();
        writer.close();
    }
}
