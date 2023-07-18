package week9.Four;

import java.io.*;
import java.util.Random;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Four {
    public static void main(String[] args) throws IOException {
        File question = new File("src//week9//Four//question.txt");
        File answer = new File("src//week9//Four//answer.txt");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        generate(question, n);

        solve(question, answer);
    }
    private static void generate(File file, int n) throws IOException {
        String[] operator = {"+", "-", "*", "/"};
        FileWriter writer = new FileWriter(file);
        PrintWriter pw = new PrintWriter(writer);
        Random random = new Random();

        while (n != 0) {
            int op = random.nextInt(operator.length), n1 = random.nextInt(101), n2 = random.nextInt(101);

            if(operator[op].equals("/") && n2 == 0)   continue;

            pw.println(n1 + operator[op] + n2);
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
            printWriter.println(s + "=" + calculate(s));
        }

        bufferedReader.close();
        reader.close();
        printWriter.close();
        writer.close();
    }

    private static int calculate(String s) {
        int res = 0;
        Matcher matcher = Pattern.compile("(\\d+)([+\\-*/])(\\d+)").matcher(s);

        if(matcher.find()) {
            int n1 = Integer.parseInt(matcher.group(1)), n2 = Integer.parseInt(matcher.group(3));
            String op = matcher.group(2);

            switch(op) {
                case "+":res = n1+n2;break;
                case "-":res = n1-n2;break;
                case "*":res = n1*n2;break;
                case "/":res = n1/n2;break;
            }
        }

        return res;
    }
}
