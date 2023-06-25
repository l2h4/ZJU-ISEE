%(1)
x=[1, 1, 1, 1, 0, 0];
N=6;
k=0:1:3*N-1;

ak=IDFS_3N(N, x);

figure(1);
subplot(2,1,1);
stem(k,abs(ak));
title('ak的模');
xlabel('k');
ylabel('|a_k|');

subplot(2,1,2);
stem(k,angle(ak));
title('ak的相位');
xlabel('k');
ylabel('相频响应');

%(3)
x2=[2, 4, 0, 0];
N2=4;
k2=0:1:3*N2-1;

ak2=IDFS_3N(N2, x2);

figure(2);
subplot(2,1,1);
stem(k2,abs(ak2));
title('ak2的模');
xlabel('k');
ylabel('|a_k|');

subplot(2,1,2);
stem(k2,angle(ak2));
title('ak2的相位');
xlabel('k');
ylabel('相频响应');