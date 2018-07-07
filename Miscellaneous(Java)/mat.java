package mat;

import java.util.Scanner;

public class mat {
	
	static int m,n;
	static int memo[][];
	
	static int mincost(int [][]a,int i,int j)//,int cost)
	{
		//System.out.println("yoyo"+i+" "+j+" "+m+" "+n);
		if(i>=m || j>=n)
			return 0;
		//System.out.println("xoxo"+" "+memo[i][j]);
		if(memo[i][j]==0)
	  {  //System.out.println("B"+" "+i+" "+j+" "+m+" "+n);
			
	     int sum=a[i][j];
	     
		if((i+1)<m && (j+1)>=n)
			{//System.out.println("P");
			sum+=mincost(a,i+1,j);
			
			}
		else if((i+1)>=m && (j+1)<n)
			{//System.out.println("Q");
			sum+=mincost(a,i,j+1);
			}
		else if((i+1)<m && (j+1)<n)
		{
			//System.out.println("R");
			int min;
			int x=mincost(a,i+1,j);
			int y=mincost(a,i,j+1);
			min=(x<=y)?x:y;
			sum+=min;	
		}
		//System.out.println("shubh");
		memo[i][j]=sum;
		return memo[i][j];
	  }
		else {
			//System.out.println("C");
			return memo[i][j];
		
		}
		
		
	}
	
	public static void main(String[]args)
	{
		int mcost;
		Scanner in=new Scanner(System.in);
		m=in.nextInt();
		n=in.nextInt();
		memo=new int[m][n];
		int a[][]=new int[m][n];
		for(int i=0;i<a.length;i++)
		{
			for(int j=0;j<a[0].length;j++)
			{
				//System.out.println("A");
				a[i][j]=in.nextInt();
				memo[i][j]=0;
			}
		}
		mcost=mincost(a,0,0);
		//System.out.println();
		System.out.println("mincost="+mcost);
		
	}

}
