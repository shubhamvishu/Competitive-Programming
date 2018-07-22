//MIN-COST PATH (WITH RIGHT AND DOWN MOVEMENT)

package mat;

import java.util.Scanner;

public class mat {

	static int m,n;
	static int memo[][];

	static int mincost(int [][]a,int i,int j)
	{

		if(i>=m || j>=n)
			return 0;

		if(memo[i][j]==0)
	  {
	     int sum=a[i][j];

		if((i+1)<m && (j+1)>=n)
        {
			sum+=mincost(a,i+1,j);

        }
		else if((i+1)>=m && (j+1)<n)
        {
			sum+=mincost(a,i,j+1);
        }
		else if((i+1)<m && (j+1)<n)
		{

			int min;
			int x=mincost(a,i+1,j);
			int y=mincost(a,i,j+1);
			min=(x<=y)?x:y;
			sum+=min;
		}

		memo[i][j]=sum;
		return memo[i][j];
	  }

		else {

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

				a[i][j]=in.nextInt();
				memo[i][j]=0;
			}
		}
		mcost=mincost(a,0,0);

		System.out.println("Minimum-cost="+mcost);

	}

}
