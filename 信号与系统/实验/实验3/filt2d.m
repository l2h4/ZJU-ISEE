function y=filt2d(b, a, d, x)
    
    [m,n]=size(x);

    y=zeros(m,n);

    for i=1:n
        w=filter(b,a,[x(:,i);zeros(d,1)]);
        y(:,i)=w(d:end-1);
    end

end