import java.util.Scanner;

public class homework02 {
    public static void main(String[] args) {
        float length;//长度
        float width;//宽度
        boolean type;//true.regular false.fancy
        String color;//颜色
        int crownNumber;//标签数
        float cost= 0f;

        System.out.println("输入边框的长度和宽度： ");
        Scanner sc=new Scanner(System.in);
        length=sc.nextFloat();
        width=sc.nextFloat();
        System.out.println("输入边框类别(true or false)：true:regular false:fancy");
        type=sc.nextBoolean();

        System.out.print("输入边框颜色：");
        color=sc.nextLine();
        System.out.print("输入标签的个数：");
        crownNumber=sc.nextInt();
        if(type)  cost+=2*(length+width)*0.15;
        else cost+=2*(length+width)*0.25;

        if(color!="white")
        {
            cost+=2*(length+width)*0.1;
        }
        cost+=length*width*(0.01+0.07);//cardboard paper +glass
        cost+=crownNumber*0.35;

        System.out.println("The cost of picture is:"+cost+'$');


    }
}
