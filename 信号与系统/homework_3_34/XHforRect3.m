function y=XHforRect3(w, t, T, W)

XH=(abs(w)<W).*(T*sinc(w*T/(2.0*pi))).*exp(-j*w*5*T/2);

y=(XH/(2.0*pi)).*exp(j*w*t);
end