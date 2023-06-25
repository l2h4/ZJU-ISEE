function y=XHforRect2(w, t, T, W)

XH=-(abs(w)<W).*(T*sinc(w*T/(2.0*pi))).*exp(-j*w*3*T/2);

y=(XH/(2.0*pi)).*exp(j*w*t);
end