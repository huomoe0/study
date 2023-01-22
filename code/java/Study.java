/**
 * @author lmd
 * @version 1.0
 */

import java.util.Scanner;


public class Study
{
	String s;

	Study() {this("");}
	Study(String s)
	{
		this.s = s;
	}
	public static void main(String[] args)
	{
		
		
	}


}



class Add
{
	public int sum(int ... nums) //可变参数
	{
		int res = 0;
		for(int i = 0;i < nums.length;i++)
		{
			res += nums[i];
		}
		return res;
	}
	public double sum(String x, double ... nums) //可变参数只能有一个，且在参数列表最右边
	{
		double res = 0;
		for(int i = 0;i < nums.length;i++)
		{
			res += nums[i];
		}
		return res;
	}
}









// class Convert10to16 
// {
// 	public static void main(String[] args)
// 	{
// 		int a = 237;
// 		String s = "";
// 		while (a != 0)
// 		{
// 			int t = a % 16;

// 			if(t < 10)	s = (char)('0' + t) + s;
// 			else s = (char)('A' + t - 10) + s;

// 			a /= 16;

// 		}
// 		System.out.println(s);
// 		System.out.println(-10.5 % 3.0);
// 	}
// }

// class Input 
// {
// 	public static void main(String[] args)
// 	{
// 		Scanner input = new Scanner(System.in);

// 		String name = input.next();
// 		int age = input.nextInt();
// 		String gender = input.next();
// 		char c = input.next().charAt(0);
// 		System.out.println("姓名\t年龄\t性别\n" + name + "\t" + age + "\t" + gender);

// 	}
// }

// class Comment 
// {
// 	/*
// 		注释
// 	*/

// 	// 注释
// 	public static void main(String[] args)
// 	{
// 		System.out.println("书名\t\t作者  \t\t价格\t\t销量\n");
// 		System.out.println("三国\t\t罗贯中\t\t120\t\t1000\n");

// 	}
// }

// class Stars
// {
// 	public static void main(String[] args)
// 	{
// 		Scanner input = new Scanner(System.in);
// 		int n = input.nextInt();

// 		for(int i = 0;i < n;i++)
// 		{
// 			for(int j = n-i; j >= 1;j--)	System.out.print(" ");
// 			for(int j = 1;j <= i*2+1;j++)
// 			{
// 				if(j == 1 || j == i*2+1)	System.out.print("*");
// 				else System.out.print(" ");
// 			}
// 			System.out.println();
// 		}
// 		for(int i = n-2;i >= 0;i--)
// 		{
// 			for(int j = n-i; j >= 1;j--)	System.out.print(" ");
// 			for(int j = 1;j <= i*2+1;j++)
// 			{
// 				if(j == 1 || j == i*2+1)	System.out.print("*");
// 				else System.out.print(" ");
// 			}
// 			System.out.println();
// 		}
// 	}
// }

// class Num 
// {
// 	public static void main(String[] args) 
// 	{
// 		byte a = (short)11;
// 		float b = 1.1f;
// 		int a1 = Integer.parseInt("123");



// 		System.out.println(a);
// 		System.out.println(a1);
// 		System.out.println(b);

// 		System.out.println(" " + 123 + "a");

// 		int x = 1;
// 		System.out.println(x++);

// 		System.out.println(true);
// 		System.out.println(!true);
// 		System.out.println(1 ^ 3);


// 	}
// }