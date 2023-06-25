function y=problem_1(k)
N=0:1:9;
w=2*pi*k/5;
y=sin(w*N);
stem(N,y);