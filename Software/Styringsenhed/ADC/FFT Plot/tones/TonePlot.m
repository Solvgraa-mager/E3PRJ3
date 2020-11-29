clear; clc;

N = 512
realFs = 44.1e3%% Det var ikke muligt at gøre andet.
fs = 10e3%% Ønsket samplefrekvens.
fnyquist = fs / 2%% Nyquist

SampleOffset = 0 * fs%% Avoid transients..
fsFactor = floor(realFs / fs)
tempN = N * fsFactor%% Antal samples vi kigger på
% Load tone 1
data1_1 = audioread('Tone1_1.wav', [1 + SampleOffset, tempN + SampleOffset]);
data1_2 = audioread('Tone1_2.wav', [1 + SampleOffset, tempN + SampleOffset]);
data1_3 = audioread('Tone1_3.wav', [1 + SampleOffset, tempN + SampleOffset]);
% Load tone 2
data2_1 = audioread('Tone2_1.wav', [1 + SampleOffset, tempN + SampleOffset]);
data2_2 = audioread('Tone2_2.wav', [1 + SampleOffset, tempN + SampleOffset]);
data2_3 = audioread('Tone2_3.wav', [1 + SampleOffset, tempN + SampleOffset]);
% Load tone 3
data3_1 = audioread('Tone3_1.wav', [1 + SampleOffset, tempN + SampleOffset]);
data3_2 = audioread('Tone3_2.wav', [1 + SampleOffset, tempN + SampleOffset]);
data3_3 = audioread('Tone3_3.wav', [1 + SampleOffset, tempN + SampleOffset]);
% Load tone 4
data4_1 = audioread('Tone4_1.wav', [1 + SampleOffset, tempN + SampleOffset]);
data4_2 = audioread('Tone4_2.wav', [1 + SampleOffset, tempN + SampleOffset]);
data4_3 = audioread('Tone4_3.wav', [1 + SampleOffset, tempN + SampleOffset]);

%% Pseudo 10 khz samplingrate
data1_1 = data1_1(1:fsFactor:end) .* hann(N);
data1_2 = data1_2(1:fsFactor:end) .* hann(N);
data1_3 = data1_3(1:fsFactor:end) .* hann(N);

data2_1 = data2_1(1:fsFactor:end) .* hann(N);
data2_2 = data2_2(1:fsFactor:end) .* hann(N);
data2_3 = data2_3(1:fsFactor:end) .* hann(N);

data3_1 = data3_1(1:fsFactor:end) .* hann(N);
data3_2 = data3_2(1:fsFactor:end) .* hann(N);
data3_3 = data3_3(1:fsFactor:end) .* hann(N);

data4_1 = data4_1(1:fsFactor:end) .* hann(N);
data4_2 = data4_2(1:fsFactor:end) .* hann(N);
data4_3 = data4_3(1:fsFactor:end) .* hann(N);

% data1_1 = data1_1 ./ max(data1_1);
% data1_2 = data1_2 ./ max(data1_2);
% data1_3 = data1_3 ./ max(data1_3);

% data2_1 = data2_1 ./ max(data2_1);
% data2_2 = data2_2 ./ max(data2_2);
% data2_3 = data2_3 ./ max(data2_3);

% data3_1 = data3_1 ./ max(data3_1);
% data3_2 = data3_2 ./ max(data3_2);
% data3_3 = data3_3 ./ max(data3_3);

% data4_1 = data4_1 ./ max(data4_1);
% data4_2 = data4_2 ./ max(data4_2);
% data4_3 = data4_3 ./ max(data4_3);

ts = 1 / fs

time_vek = (0 + SampleOffset:N + SampleOffset - 1) / fs;

sampleResolution = fs / N;
%% FFT Settings

% sampleResolution = fs * SampleLength
bins = [0:N - 1]; % Antal fft_bins
freq = bins * sampleResolution; % Frekvensakse

%%
% data1_1_fft = abs(fft(data1_1));
% data1_1_fftdB = 20 * log10((2 / N) * abs(fft(data1_1)));
data1_fft = [20 * log10((2 / N) * abs(fft(data1_1))), ...
            20 * log10((2 / N) * abs(fft(data1_2))), ...
            20 * log10((2 / N) * abs(fft(data1_3)))];
data2_fft = [20 * log10((2 / N) * abs(fft(data2_1))), 20 * log10((2 / N) * abs(fft(data2_2))), 20 * log10((2 / N) * abs(fft(data2_3)))];
data3_fft = [20 * log10((2 / N) * abs(fft(data3_1))), 20 * log10((2 / N) * abs(fft(data3_2))), 20 * log10((2 / N) * abs(fft(data3_3)))];
data4_fft = [20 * log10((2 / N) * abs(fft(data4_1))), 20 * log10((2 / N) * abs(fft(data4_2))), 20 * log10((2 / N) * abs(fft(data4_3)))];

data_fft = [data1_fft, data2_fft, data3_fft, data4_fft];

% data1_fft = data1_fft(1,:);
figure(1); clf;
subplot(2, 2, 1)
plot(time_vek, [data1_1, data1_2, data1_3])
title('Tone 1')
xlabel('Tid [s]')
axis tight
subplot(2, 2, 2)
plot(time_vek, [data2_1, data2_2, data2_3])
title('Tone 2')
xlabel('Tid [s]')
axis tight
subplot(2, 2, 3)
plot(time_vek, [data3_1, data3_2, data3_3])
title('Tone 3')
xlabel('Tid [s]')
axis tight
subplot(2, 2, 4)
plot(time_vek, [data4_1, data4_2, data4_3])
title('Tone 4')
xlabel('Tid [s]')
axis tight
sgtitle('Mundharmonika toner med Hann vindue tilføjet')
printTarget = gcf;
saveas(printTarget, ['figs/TimePlot_N_' num2str(N)], 'epsc')
saveas(printTarget, ['figs/TimePlot_N_' num2str(N)], 'png')

%% FFT af Tone 1
figure(2); clf;
subplot(2, 2, 1)
hold on

for idx = 1:size(data1_fft, 2)
    semilogx(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx));
    xlim([0 fnyquist])
    % stem(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx),'BaseValue',-200,'Marker','.');
    % bar(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx),'BaseValue',-200);
    grid on
    % ylim([-100 0])
end

hold off
title('Frekvensspektrum for Tone 1');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')

subplot(2, 2, 2)
hold on

for idx = 1:size(data2_fft, 2)
    semilogx(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx));
    xlim([0 fnyquist])
    % stem(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx),'BaseValue',-200,'Marker','.');
    % bar(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx),'BaseValue',-200);
    grid on
    % ylim([-100 0])
end

hold off
title('Frekvensspektrum for Tone 2');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')

subplot(2, 2, 3)
hold on

for idx = 1:size(data3_fft, 2)
    semilogx(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx));
    xlim([0 fnyquist])
    % stem(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx),'BaseValue',-200,'Marker','.');
    % bar(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx),'BaseValue',-200);
    grid on
    % ylim([-100 0])
end

hold off
title('Frekvensspektrum for Tone 3');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')

subplot(2, 2, 4)
hold on

for idx = 1:size(data4_fft, 2)
    semilogx(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx));
    xlim([0 fnyquist])
    % stem(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx),'BaseValue',-200,'Marker','.');
    % bar(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx),'BaseValue',-200);
    grid on
    % ylim([-100 0])
end

hold off
title('Frekvensspektrum for Tone 4');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')
sgtitle([num2str(N / 2), ' bins FFT toner genereret af mundharmonika.'])
printTarget = gcf;
saveas(printTarget, ['figs/FFT_N_' num2str(N)], 'epsc')
saveas(printTarget, ['figs/FFT_N_' num2str(N)], 'png')

figure(3); clf
subplot(2, 1, 1)
hold on

for idx = 1:size(data4_fft, 2)
    semilogx(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx), 'r', 'DisplayName', 'Tone 1');
    semilogx(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx), 'b', 'DisplayName', 'Tone 2');
    semilogx(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx), 'g', 'DisplayName', 'Tone 3');
    semilogx(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx), 'k', 'DisplayName', 'Tone 4');
end

grid on
xlim([0 3e3])
ylim([-100 0])
legend('Tone 1', 'Tone 2', 'Tone 3', 'Tone 4', 'location', 'southwest');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')
hold off

subplot(2, 1, 2)
hold on

for idx = 1:size(data4_fft, 2)
    semilogx(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx), '-or', 'DisplayName', 'Tone 1');
    semilogx(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx), '-ob', 'DisplayName', 'Tone 2');
    semilogx(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx), '-og', 'DisplayName', 'Tone 3');
    semilogx(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx), '-ok', 'DisplayName', 'Tone 4');
end

xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')
grid on
xlim([0 1.2e3])
ylim([-100 0])
hold off
legend('Tone 1', 'Tone 2', 'Tone 3', 'Tone 4', 'location', 'southwest');
printTarget = gcf;
saveas(printTarget, ['figs/FFT_Close_N_' num2str(N)], 'epsc')
saveas(printTarget, ['figs/FFT_Close_N_' num2str(N)], 'png')

figure(4); clf
subplot(2, 1, 1)
hold on

for idx = 1:size(data4_fft, 2)
    bar(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx), 'BaseValue', -150);
end

grid on
xlim([0 3e3])
ylim([-100 0])
% legend('Tone 1','Tone 2','Tone 3','Tone 4');
xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')
hold off

subplot(2, 1, 2)
hold on

for idx = 1:size(data4_fft, 2)
    bar(freq(1:0.5 * end), data1_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data2_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data3_fft(1:0.5 * end, idx), 'BaseValue', -150);
    bar(freq(1:0.5 * end), data4_fft(1:0.5 * end, idx), 'BaseValue', -150);
end

xlabel('Frekvens [Hz]')
ylabel('Amplitude [dB]')
grid on
xlim([0 1.2e3])
ylim([-100 0])
hold off
printTarget = gcf;
saveas(printTarget, ['figs/FFT_Bar_N_' num2str(N), '_Bins_', num2str(N / 2)], 'epsc')
saveas(printTarget, ['figs/FFT_Bar_N_' num2str(N), '_Bins_', num2str(N / 2)], 'png')
% legend('Tone 1','Tone 2','Tone 3','Tone 4','location','northwest');
