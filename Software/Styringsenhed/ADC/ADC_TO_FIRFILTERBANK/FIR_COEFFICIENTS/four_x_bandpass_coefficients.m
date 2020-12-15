%% FIR FILTER KOEFFICIENTER
fs=10000;
f_min = 20;
f_max = 0.999*(fs/2);
f_akse = logspace(log10(f_min), log10(f_max), 1000);

% HAMMING
fir1_1=fir200_350;
fir1_2=fir350_500;
fir1_3=fir650_800;
fir1_4=fir900_1050;

mag1_1=freqz(fir1_1,f_akse,fs);
mag1_2=freqz(fir1_2,f_akse,fs);
mag1_3=freqz(fir1_3,f_akse,fs);
mag1_4=freqz(fir1_4,f_akse,fs);
figure(101);
semilogx(f_akse, 20*log10(abs(mag1_1)));
hold on;
semilogx(f_akse, 20*log10(abs(mag1_2)));
hold on;
semilogx(f_akse, 20*log10(abs(mag1_3)));
hold on;
semilogx(f_akse, 20*log10(abs(mag1_4)));
hold off;
xlim([0 1250]);
ylim([-60 0]);
ylabel('Mag (dB)');
xlabel('Frekvens');
title('4x båndpas filtre, hamming vindue, 67 koefficienter');

% TUKEY
tuk1_1=tuk200_350;
tuk1_2=tuk350_500;
tuk1_3=tuk650_800;
tuk1_4=tuk900_1050;

mag2_1=freqz(tuk1_1,f_akse,fs);
mag2_2=freqz(tuk1_2,f_akse,fs);
mag2_3=freqz(tuk1_3,f_akse,fs);
mag2_4=freqz(tuk1_4,f_akse,fs);
figure(102);
semilogx(f_akse, 20*log10(abs(mag2_1)));
hold on;
semilogx(f_akse, 20*log10(abs(mag2_2)));
hold on;
semilogx(f_akse, 20*log10(abs(mag2_3)));
hold on;
semilogx(f_akse, 20*log10(abs(mag2_4)));
hold off;
xlim([0 1250]);
ylim([-60 0]);
ylabel('Mag (dB)');
xlabel('Frekvens');
title('4x båndpas filtre, tukey vindue, alpha = 0.1, 134 koefficienter');

%rec
rec1_1=rec200_350;
rec1_2=rec350_500;
rec1_3=rec650_800;
rec1_4=rec900_1050;

mag3_1=freqz(rec1_1,f_akse,fs);
mag3_2=freqz(rec1_2,f_akse,fs);
mag3_3=freqz(rec1_3,f_akse,fs);
mag3_4=freqz(rec1_4,f_akse,fs);
figure(103);
semilogx(f_akse, 20*log10(abs(mag3_1)));
hold on;
semilogx(f_akse, 20*log10(abs(mag3_2)));
hold on;
semilogx(f_akse, 20*log10(abs(mag3_3)));
hold on;
semilogx(f_akse, 20*log10(abs(mag3_4)));
hold off;
xlim([0 1250]);
ylim([-60 0]);
ylabel('Mag (dB)');
xlabel('Frekvens');
title('4x båndpas filtre, rectangular vindue, 67 koefficienter');

%blackman
black1_1=black200_350;
black1_2=black350_500;
black1_3=black650_800;
black1_4=black900_1050;

mag4_1=freqz(black1_1,f_akse,fs);
mag4_2=freqz(black1_2,f_akse,fs);
mag4_3=freqz(black1_3,f_akse,fs);
mag4_4=freqz(black1_4,f_akse,fs);
figure(104);
semilogx(f_akse, 20*log10(abs(mag4_1)));
hold on;
semilogx(f_akse, 20*log10(abs(mag4_2)));
hold on;
semilogx(f_akse, 20*log10(abs(mag4_3)));
hold on;
semilogx(f_akse, 20*log10(abs(mag4_4)));
hold off;
xlim([0 1250]);
ylim([-60 0]);
ylabel('Mag (dB)');
xlabel('Frekvens');
title('4x båndpas filtre, blackman vindue, 134 koefficienter');

%% TRÆK KOEFFICIENTER UD
hamming900_1050_koeff=int16(fir1_1.Numerator*2^15);