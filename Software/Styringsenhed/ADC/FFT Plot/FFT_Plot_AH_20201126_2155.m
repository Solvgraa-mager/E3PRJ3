clear;
fs = 10000
InputArray = load('log2155input.txt');
N = numel(InputArray)
calculatedCoeffs = load('Log2155Coeff.txt');
calculatedCoeffs = calculatedCoeffs;
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
hold
semilogx(freq(1:0.5 * end), abs(calculatedCoeffs), 'marker', 'o');
semilogx(freq(1:0.5 * end), aCoeffMatResult(1:0.5 * end), 'marker', 'o');
xlabel('Frekvens [Hz]')

