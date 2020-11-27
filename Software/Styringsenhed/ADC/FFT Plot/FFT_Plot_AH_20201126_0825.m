clear all;
fs = 10000
N = 128


calculatedCoeffs = load('log0825coeffs.txt');

magnitudeCoeffs = calculatedCoeffs(:,3);
N_vek = (0:N - 1);
t_vek = N_vek ./ fs;

sampleResolution = fs/N;
bins = [0:N - 1]; % Antal fft_bins
freq = bins * sampleResolution; % Frekvensakse



% figure(1);clf;
% plot(t_vek*10e6, InputArray)
% xlabel('Tid [µs]');



% mean(InputArray)
% InputArray = InputArray - mean(InputArray);

% fftResultMatlab = fft(InputArray, N);
% aCoeffMatlabResult = abs(fftResultMatlab);

figure(4);clf;

semilogx(freq(1:0.5 * end), magnitudeCoeffs, 'marker', 'o','DisplayName','Udregnet i C');
% hold on
% semilogx(freq(1:0.5 * end), aCoeffMatlabResult(1:0.5 * end),'-.','marker','o', 'DisplayName', 'Udregnet i Matlab');
% hold off 
legend('location','best');
grid
xlabel('Frekvens [Hz]')
title([{'Behandling af DMA-overført data.'},...
{['Samplerate:', num2str(fs)]},...
{['Samples:', num2str(N)]}])

