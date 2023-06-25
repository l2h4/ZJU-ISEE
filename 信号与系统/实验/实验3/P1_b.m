a=0; N=10; c=0;
M=5; d=M-1; b=N-1;
n=min(a,c):1:max(b,d);

nh=[a:b]; nx=[c:d];

h=[(n-a)==0]+[(n-b)==0];
x=[(n-c)==0]+[(n-d)==0];

y=conv(h,x);
ny=[2*min(a,c):1:2*max(b,d)];

stem(ny,y);