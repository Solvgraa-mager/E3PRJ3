clear;

InputArray = load('log2001inputarray.txt');
calculatedCoeffs = load('log2001aCoeffs.txt');
N_vek = 0:1:numel(InputArray) - 1;
figure(1);clf;
% t = 1:0.1:128;
% x = 34512 + 246076 * sin(2 * pi * 1e3 * t);
plot(N_vek, InputArray')
xlabel('Samples');




fftResult = fft(InputArray, numel(InputArray) / 2);
aCoeffMatResult = abs(fftResult);
figure(4)
semilogx(abs(fftResult));
hold on;
semilogx(calculatedCoeffs);
hold off

