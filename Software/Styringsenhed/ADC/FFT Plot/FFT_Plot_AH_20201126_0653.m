clear;
fs = 10000
InputArray = load('log0646input.txt');
N = numel(InputArray)


calculatedCoeffs = load('Log0646Coeffs.txt');

magnitudeCoeffs = calculatedCoeffs(:,3);
N_vek = (0:N - 1);
t_vek = N_vek ./ fs;

sampleResolution = fs/N;
bins = [0:N - 1]; % Antal fft_bins
freq = bins * sampleResolution; % Frekvensakse

mean(InputArray)
InputArray = InputArray - mean(InputArray);


figure(1);clf;
plot(t_vek*10e6, InputArray')
xlabel('Tid [µs]');




fftResult = fft(InputArray, N);
aCoeffMatResult = abs(fftResult/N);

figure(4);clf;
subplot(2,1,1)
title('C udregnet')
semilogx(freq(1:0.5 * end), abs(magnitudeCoeffs)/N, 'marker', 'o');
xlabel('Frekvens [Hz]')
subplot(2,1,2)
title('Matlab udregnet')
semilogx(freq(1:0.5 * end), aCoeffMatResult(1:0.5 * end), 'marker', 'o');
xlabel('Frekvens [Hz]')

