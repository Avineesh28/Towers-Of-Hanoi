#include<stdio.h>
#include<conio.h>
#include<math.h>
int top1=-1;
int top2=-1;
int top3=-1;
void push1(int a[],int data)
{
	top1++;
	a[top1]=data;
}
int pop1(int a[])
{
    int b = 999;
    if (top1 == -1)
        return b;
    else
    {
		b=a[top1];
		top1--;
		return b;
    }
}
void push2(int b[],int data)
{
	top2++;
	b[top2]=data;
}
int pop2(int b[])
{
    int bb = 999;
    if (top2 == -1)
        return bb;
    else
    {
    	bb=b[top2];
    	top2--;
    	return bb;
    }
}
void push3(int c[],int data)
{
	top3++;
	c[top3]=data;
}
int pop3(int c[])
{
    int b = 999;
    if (top3 == -1)
        return b;
    else
    {
    	b=c[top3];
    	top3--;
    	return b;
    }
}
int top_of_stack(int a[],int b[],int c[])
{
    if (top1 != -1 && a[top1]== 1 )
        return 1;
    else if (top2 != -1 && b[top2] == 1)
        return 2;
    else if (top3 != -1 && c[top3] == 1)
		return 3;
}
void display1(int a[])
{
	printf("--------------------------------------\n");
	printf("\n");
    printf("Tower 1->\t");
    for(int i=top1;i>=0;i--)
		printf("%d\t",a[i]);
	printf("\n");
}
void display2(int b[])
{
	printf("\n");
    printf("Tower 2->\t");
    for(int i=top2;i>=0;i--)
		printf("%d\t",b[i]);
	printf("\n");
}
void display3(int c[])
{
printf("\n");
    printf("Tower 3->\t");
    for(int i=top3;i>=0;i--)
		printf("%d\t",c[i]);
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");
}
void toh(int nn,int m[],int n[],int o[])
{
    int i, x, a, b;
    for (i = 0; i < (pow(2,nn)); i++)
    {
    	display1(m);
        display2(n);
        display3(o);
        if(top1==-1 && top2==-1)
        	return;
    	
        x = top_of_stack(m,n,o);
        if (i % 2 == 0)
        {
            if (x == 1)
            {
            	printf("Move the disk from A to C\n");
			    push3(o,pop1(m));
			}
            else if (x == 2)
            {
            	printf("Move the disk from B to A\n");
            	push1(m,pop2(n));
            }
			else if (x == 3)
			{
				printf("Move the disk from C to B\n");
			    push2(n,pop3(o));
			}
			if(top1==-1 && top2==-1 ||top3==-1 && top1==-1)
                return;
        }
        else
        {
            if (x == 1)
            {
            	a = pop2(n);
                b = pop3(o);
                if (a < b && b != 999)
                {
                	printf("Move the disk from B to C\n");
                    push3(o,b);
                    push3(o,a);
                }
                else if (a > b && a != 999)
                {
                	printf("Move the disk from C to B\n");
                    push2(n,a);
                    push2(n,b);
                }
                else if (b == 999)
                {
                	printf("Move the disk from B to C\n");
					push3(o,a);
				}
                else if (a == 999)
                {
                	printf("Move the disk from C to B\n");
                	push2(n,b);
                }
                if(top1==-1 && top2==-1 ||top3==-1 && top1==-1 )
                	return;
            }
            else if (x == 2)
            {
                a = pop1(m);
                b = pop3(o);
                if (a < b && b != 999)
                {
                	printf("Move the disk from A to C\n");
                    push3(o,b);
                    push3(o,a);
                }
                else if (a > b && a != 999)
                {
                	printf("Move the disk from C to A\n");
                    printf("\n");
					push1(m,a);
                    push1(m,b);
                }
                else if (b == 999)
                {
                	printf("Move the disk from A to C\n");
					push3(o,a);
				}
				else if (a == 999)
				{
					printf("Move the disk from C to A\n");
					push1(m,b);
				}
				if(top1==-1 && top2==-1 ||top3==-1 && top1==-1)
                	return;
			}
            else if (x == 3)
            {
            	a = pop1(m);
                b = pop2(n);
                if (a < b && b != 999)
                {
                	printf("Move the disk from A to B\n");
                    push2(n,b);
                    push2(n,a);
	            }
                else if (a > b && a != 999)
                {
                	printf("Move the disk from B to A\n");
                    push1(m,a);
                    push1(m,b);
                }
	            else if (b == 999)
                {
                	printf("Move the disk from A to B\n");
					push2(n,a);
                	
				}
				else if (a == 999)
			    {
			    	printf("Move the disk from B to A\n");
			    	push1(m,b);
				}
				if(top1==-1 && top2==-1 ||top3==-1 && top1==-1)
                	return;
            }
        }
    }
}
int main()
{
    int n, i;
    printf("Enter the number of disks\n");
	scanf("%d",&n);
	int a[n];
	int b[n];
	int c[n];
    for (i = n; i >= 1; i--)
    {
        push1(a,i);
    } 
    toh(n,a,b,c);
    display1(a);
    display2(b);
    display3(c);
    printf("\nProblem Solved!!\nThank You!");
    getch();
}
