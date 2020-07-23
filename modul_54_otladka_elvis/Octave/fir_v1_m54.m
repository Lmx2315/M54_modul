pkg load signal;

N =256;  %порядок фильтра
fp=0.4; %частота среза
B=16;

 H = fir1(N,fp,kaiser(N+1));
%H = fir1(N,fp);

f=[0, 0.42,  0.49,    1];
m=[1,    1,     0,    0];

H = fir2(N,f,m);

%H = zeros(1,N);
H = H/max(H); %% Floating point coefficients
Hnorm = round(H*power(2,B-1)-1); %% Fixed point coefficients

S=sum(Hnorm);

  fid = fopen ('fir_coe_m54.dat', 'w');
  for i = 1:ceil(N/2)
    fprintf(fid, '%d\r\n', Hnorm(i));
  end
  fclose(fid);
  
    fid = fopen ('fir_code_m54.dat', 'w');
  for i = 1:(N+1)
    fprintf(fid, 'dsp->RX1_CF_DFIR1[');
    fprintf(fid, '%d',i-1);
    fprintf(fid, ']  =');
    if (rem(i,2)!=0) fprintf(fid, '%d', Hnorm(ceil(i/2)));
      else fprintf(fid, '%X', 0);
    endif
    fprintf(fid, ';\r\n');
  end
  
   fprintf(fid, '\r\n\n\r\r');
  
   for i = 1:(N+1)
    fprintf(fid, 'dsp->RX1_CF_DFIR2[');
    fprintf(fid, '%d',i-1);
    fprintf(fid, ']  =');
    if (rem(i,2)!=0) fprintf(fid, '%d', Hnorm(ceil(i/2)));
      else fprintf(fid, '%X', 0);
    endif
    fprintf(fid, ';\r\n');
  end 
  
  fclose(fid);

  figure('name','CIC/FIR Frequency Response', 'Numbertitle', 'off')
  
  freqz(Hnorm);
  
  