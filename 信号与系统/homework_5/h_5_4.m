function y=h_5_4(t, T)
    u1=heaviside(t+T)-heaviside(t);
    u2=heaviside(t)-heaviside(t-T);

    y=(1/T*t+1).*u1+(-1/T*t+1).*u2;
end