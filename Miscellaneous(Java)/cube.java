//https://practice.geeksforgeeks.org/problems/rubiks-cube/0

import java.util.Scanner;

public class cube {

    static char[][][] rotateclk(char arr[][][],int index)
    {

        for(int i=0;i<2;i++)
        {
            char temp=arr[index][i][2];
            arr[index][i][2]=arr[index][0][i];
            arr[index][0][i]=arr[index][2-i][0];
            arr[index][2-i][0]=arr[index][2][2-i];
            arr[index][2][2-i]=temp;
        }
        return arr;

    }
   static char[][][] rotateant(char arr[][][],int index)
    {

        for(int i=0;i<2;i++)
        {
            char temp=arr[index][0][i];
            arr[index][0][i]=arr[index][i][2];
            arr[index][i][2]=arr[index][2][2-i];
            arr[index][2][2-i]=arr[index][2-i][0];
            arr[index][2-i][0]=temp;
        }
        return arr;

    }

    static char[][][] sideclk(char arr[][][],boolean a[],boolean b[],int c[],int d[])
    {
        char [][]p=new char[4][3];

        for(int i=0;i<4;i++)
        {
            if(b[i])
            {
                for(int j=0;j<3;j++)
                {
                    p[i][j]=arr[c[i]][d[i]][j];
                }
            }
            else {
                for(int j=0;j<3;j++)
                {
                    p[i][j]=arr[c[i]][j][d[i]];
                }
            }

        }

        boolean check=true;
        for(int i=1;i<=4 && check;i++)
        {
            if(i==4)
             check=false;
            if(b[i%4])
            {
                if(a[i%4])
                {
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][d[i%4]][j]=p[i-1][j];
                    }
                }
                else{
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][d[i%4]][j]=p[i-1][2-j];
                    }
                }
            }
            else {
                if(a[i%4])
                {
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][j][d[i%4]]=p[i-1][j];
                    }
                }
                else{
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][j][d[i%4]]=p[i-1][2-j];
                    }
                }
            }

        }
        return arr;
    }

    static char[][][] sideant(char arr[][][],boolean a[],boolean b[],int c[],int d[])
    {
        char [][]p=new char[4][3];

        for(int i=0;i<4;i++)
        {
            if(b[i])
            {
                for(int j=0;j<3;j++)
                {
                    p[i][j]=arr[c[i]][d[i]][j];
                }
            }
            else {
                for(int j=0;j<3;j++)
                {
                    p[i][j]=arr[c[i]][j][d[i]];
                }
            }

        }
        boolean check=true;
        for(int i=0;i<4 && check;i++)
        {
            if(i==4)
                check=false;
            if(b[i%4])
            {
                if(a[i%4])
                {
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][d[i%4]][j]=p[(i+1)%4][j];
                    }
                }
                else{
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][d[i%4]][j]=p[(i+1)%4][2-j];
                    }
                }
            }
            else {
                if(a[i%4])
                {
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][j][d[i%4]]=p[(i+1)%4][j];
                    }
                }
                else{
                    for(int j=0;j<3;j++)
                    {
                        arr[c[i%4]][j][d[i%4]]=p[(i+1)%4][2-j];
                    }
                }
            }

        }
        return arr;
    }
    public static void main(String[] args)
    {
        int n,n1=6,n2,j=0;
        char [][][] arr=new char[6][3][3];
        String s,str="";
        Scanner in=new Scanner(System.in);

           while (n1>0) {
               s = in.nextLine();
               int row = 0, col = 0;
               switch (s) {

                   case "UP":
                       str = in.nextLine();
                       break;          //0
                   case "FRONT":
                       str = in.nextLine();
                       break;       //1
                   case "LEFT":
                       str = in.nextLine();
                       break;        //2
                   case "RIGHT":
                       str = in.nextLine();
                       break;       //3
                   case "BACK":
                       str = in.nextLine();
                       break;        //4
                   case "DOWN":
                       str = in.nextLine();
                       break;        //5


               }
               for (int i = 0; i < str.length(); i++) {
                   if (col >= 3) {
                       row++;
                       col = 0;
                   }
                   arr[j][row][col] = str.charAt(i);
                   col++;


               }
               n1--;
               j++;
           }


                n2=in.nextInt();
                while (n2>0)
                {
                    String s1;
                    s1=in.next();
                    boolean[] a,b=new boolean[4];
                    int[] c=new int[4],d=new int[4];
                    switch(s1)
                    {
                        case "R":a=new boolean[]{true,false,false,true};
                                 b=new boolean[]{false,false,false,false};
                                 c= new int[]{0, 4, 5, 1};
                                 d=new int[]{2,0,2,2};
                                 arr=rotateclk(arr,3);
                                 arr=sideclk(arr,a,b,c,d);
                                  break;
                        case "Ri":a=new boolean[]{false,false,true,true};
                                  b=new boolean[]{false,false,false,false};
                                  c= new int[]{0, 4, 5, 1};
                                  d=new int[]{2,0,2,2};
                                  arr=rotateant(arr,3);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                        case "L":a=new boolean[]{false,true,true,false};
                                 b=new boolean[]{false,false,false,false};
                                 c=new int[]{0,1,5,4};
                                 d=new int[]{0,0,0,2};
                                 arr=rotateclk(arr,2);
                                 arr=sideclk(arr,a,b,c,d);
                                 break;
                        case "Li":a=new boolean[]{true,true,false,false};
                                  b=new boolean[]{false,false,false,false};
                                  c=new int[]{0,1,5,4};
                                  d=new int[]{0,0,0,2};
                                  arr=rotateant(arr,2);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                        case "B":a=new boolean[]{true,false,true,false};
                                 b=new boolean[]{true,false,true,false};
                                 c=new int[]{0,2,5,3};
                                 d=new int[]{0,0,2,2};
                                 arr=rotateclk(arr,4);
                                 arr=sideclk(arr,a,b,c,d);
                                 break;
                        case "Bi":a=new boolean[]{false,true,false,true};
                                  b=new boolean[]{true,false,true,false};
                                  c=new int[]{0,2,5,3};
                                  d=new int[]{0,0,2,2};
                                  arr=rotateant(arr,4);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                        case "D":a=new boolean[]{true,true,true,true};
                                 b=new boolean[]{true,true,true,true};
                                 c=new int[]{1,3,4,2};
                                 d=new int[]{2,2,2,2};
                                 arr=rotateclk(arr,5);
                                 arr=sideclk(arr,a,b,c,d);
                                 break;
                        case "Di":a=new boolean[]{true,true,true,true};
                                  b=new boolean[]{true,true,true,true};
                                  c=new int[]{1,3,4,2};
                                  d=new int[]{2,2,2,2};
                                  arr=rotateant(arr,5);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                        case "F":a=new boolean[]{false,true,false,true};
                                 b=new boolean[]{true,false,true,false};
                                 c=new int[]{0,3,5,2};
                                 d=new int[]{2,0,0,2};
                                 arr=rotateclk(arr,1);
                                 arr=sideclk(arr,a,b,c,d);
                                 break;
                        case "Fi":a=new boolean[]{true,false,true,false};
                                  b=new boolean[]{true,false,true,false};
                                  c=new int[]{0,3,5,2};
                                  d=new int[]{2,0,0,2};
                                  arr=rotateant(arr,1);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                        case "U":a=new boolean[]{true,true,true,true};
                                 b=new boolean[]{true,true,true,true};
                                 c=new int[]{4,3,1,2};
                                 d=new int[]{0,0,0,0};
                                 arr=rotateclk(arr,0);
                                 arr=sideclk(arr,a,b,c,d);
                                 break;
                        case "Ui":a=new boolean[]{true,true,true,true};
                                  b=new boolean[]{true,true,true,true};
                                  c=new int[]{4,3,1,2};
                                  d=new int[]{0,0,0,0};
                                  arr=rotateant(arr,0);
                                  arr=sideant(arr,a,b,c,d);
                                  break;
                    }
                    n2--;
                }


            for(int i=0;i<arr.length;i++)
            {
                switch (i)
                {
                    case 0:System.out.println("UP");break;
                    case 1:System.out.println("FRONT");break;
                    case 2:System.out.println("LEFT");break;
                    case 3:System.out.println("RIGHT");break;
                    case 4:System.out.println("BACK");break;
                    case 5:System.out.println("DOWN");break;
                }
                for(j=0;j<arr[0].length;j++)
                {
                    for(int k=0;k<arr[0][0].length;k++)
                    {
                        System.out.print(arr[i][j][k]+" ");
                    }
                }
                System.out.println();
            }


    }
}
