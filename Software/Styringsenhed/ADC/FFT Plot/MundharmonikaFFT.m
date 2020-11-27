data1 = audioread('tone_1.wav');
data2 = audioread('tone_2.wav');
data3 = audioread('tone_3.wav');
data4 = audioread('tone_4.wav');

tone1 = data1(:,1);
tone2 = data2(:,1);
tone3 = data3(:,1);
tone4 = data4(:,1);

N = numel(leftCh)
fs = 10000
N_vek = (0:N - 1);
sampleResolution = fs / N;
bins = [0:N - 1]; % Antal fft_bins
freq = bins * sampleResolution; % Frekvensakse


% Do the FFT !
fftTone1 = abs(fft(tone1));
fftTone2 = abs(fft(tone2));
fftTone3 = abs(fft(tone3));
fftTone4 = abs(fft(tone4));



figure(10)
subplot(4,1,1)
semilogx(freq(1:0.5 * end), fftTone1(1:0.5 * end))
subplot(4,1,2)
semilogx(freq(1:0.5 * end), fftTone2(1:0.5 * end))
subplot(4,1,3)
semilogx(freq(1:0.5 * end), fftTone3(1:0.5 * end))
subplot(4,1,4)
semilogx(freq(1:0.5 * end), fftTone4(1:0.5 * end))
