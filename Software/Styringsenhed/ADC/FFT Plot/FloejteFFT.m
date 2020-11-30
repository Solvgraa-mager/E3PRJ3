clear all;
data1 = audioread('tone_1.wav');
data2 = audioread('tone_2.wav');
data3 = audioread('tone_3.wav');

data4 = audioread('tone_4.wav');
fs = 10000
N = 512
tone1 = data1(:, 1);
tone2 = data2(:, 1);
tone3 = data3(:, 1);
tone4 = data4(:, 1);

N_vek = (0:N - 1);
t_vek = N_vek ./ fs;

figure(2); clf;
subplot(2, 2, 1)
plot(t_vek, tone1(1:N));

subplot(2, 2, 2)
plot(t_vek, tone2(1:N));

subplot(2, 2, 3)
plot(t_vek, tone3(1:N));
subplot(2, 2, 4)
plot(t_vek, tone4(1:N));

sampleResolution = fs / N;
n = N;
bins = [0:n - 1]; % Antal fft_bins
freq = bins * sampleResolution; % Frekvensakse

% Do the FFT !
fftTone1 = 20 * log10(abs(fft(tone1, n) / (max(fft(tone1, n)))));
fftTone2 = 20 * log10(abs(fft(tone2, n) / (max(fft(tone2, n)))));
fftTone3 = 20 * log10(abs(fft(tone3, n) / (max(fft(tone3, n)))));
fftTone4 = 20 * log10(abs(fft(tone4, n) / (max(fft(tone4, n)))));


figure(10); clf;
subplot(4, 1, 1)
semilogx(freq(1:0.5 * n), fftTone1(1:0.5 * n))
xlabel('Frekvens [Hz]')
subplot(4, 1, 2)
semilogx(freq(1:0.5 * n), fftTone2(1:0.5 * n))
xlabel('Frekvens [Hz]')
subplot(4, 1, 3)
semilogx(freq(1:0.5 * n), fftTone3(1:0.5 * n))
xlabel('Frekvens [Hz]')
subplot(4, 1, 4)
semilogx(freq(1:0.5 * n), fftTone4(1:0.5 * n))
xlabel('Frekvens [Hz]')
% printTarget = gcf;
% exportgraphics(printTarget, 'figs/MundharmonikaSample.pdf');

figure(11); clf;
semilogx(freq(1:0.5 * n), fftTone1(1:0.5 * n))
hold on;
semilogx(freq(1:0.5 * n), fftTone2(1:0.5 * n))
semilogx(freq(1:0.5 * n), fftTone3(1:0.5 * n))
semilogx(freq(1:0.5 * n), fftTone4(1:0.5 * n))
legend();
hold off;
% printTarget = gcf;
% exportgraphics(printTarget, 'figs/FFTLogPlot.pdf');

figure(12); clf;
stem(freq(1:0.5 * n), fftTone1(1:0.5 * n))
hold on;
stem(freq(1:0.5 * n), fftTone2(1:0.5 * n))
stem(freq(1:0.5 * n), fftTone3(1:0.5 * n))
stem(freq(1:0.5 * n), fftTone4(1:0.5 * n))
legend();
grid
hold off;
% printTarget = gcf;
% exportgraphics(printTarget, 'figs/LinearStemPlot.pdf');

figure(13); clf;
bar(freq(1:0.5 * n), fftTone1(1:0.5 * n))
hold on;
bar(freq(1:0.5 * n), fftTone2(1:0.5 * n))
bar(freq(1:0.5 * n), fftTone3(1:0.5 * n))
bar(freq(1:0.5 * n), fftTone4(1:0.5 * n))
legend();
grid
hold off;
xlim([0 2000])
