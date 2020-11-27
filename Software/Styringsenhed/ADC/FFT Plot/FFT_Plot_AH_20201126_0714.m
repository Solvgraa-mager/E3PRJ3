clear;
fs = 10000
InputArray = load('log0714input.txt');
N = numel(InputArray)


calculatedCoeffs = load('log0714coeffs.txt');

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
aCoeffMatResult = 2*abs(fftResult)/N;

figure(4);clf;

semilogx(freq(1:0.5 * end), abs(magnitudeCoeffs)/N, 'marker', 'o','DisplayName','Udregnet i C');
hold on
semilogx(freq(1:0.5 * end), aCoeffMatResult(1:0.5 * end),'-.','marker','o', 'DisplayName', 'Udregnet i Matlab');
hold off 
legend('location','best');
xlabel('Frekvens [Hz]')
title([{'Behandling af DMA-overført data.'},...
{['Samplerate:', num2str(fs)]},...
{['Samples:', num2str(N)]}])

