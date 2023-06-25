function ak=IDFS_3N(N, x) %输入周期N和从0到N-1的x值

k=0:1:3*N-1;
n=0:1:N-1;

ak=x*exp((-1i*2*pi/N).*(n'*k))/N;

end


