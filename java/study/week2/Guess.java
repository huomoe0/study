package week2;

import java.util.Scanner;
public class Guess {
    public static void main(String[] args)
    {
        final int MAX_TIMES = 10;
        String again;

        do {
            int myGuessNumber;
            int randomNumber = (int)(Math.random()*1000) + 1;
            boolean success = false;
            int times;

            Scanner input  = new Scanner(System.in);

            //System.out.println(randomNumber);

            System.out.println("I have a number between 1 and 1000.\nCan you guess my number?\n" +
                    "Please type your first guess.");


            for(times = 1; times <= MAX_TIMES; times++) {
                myGuessNumber = input.nextInt();

                if(myGuessNumber < randomNumber) System.out.println("Too Low. Try Again.");
                else if(myGuessNumber > randomNumber) System.out.println("Too High. Try Again");
                else {
                    success = true;
                    System.out.println("Excellent! You guessed the number");
                    break;
                }

                System.out.println("You have " + (MAX_TIMES - times) + " times");
            }

            if(success) System.out.println("success.you cost " + times + " times");
            else System.out.println("sorry. you fail. the number is " + randomNumber);

            System.out.println("是否继续游戏(y or n): ");
            again = input.next();

        } while(again.equalsIgnoreCase("y")); // ==比较两个对象的值

        System.out.println("game over.");

    }

}
