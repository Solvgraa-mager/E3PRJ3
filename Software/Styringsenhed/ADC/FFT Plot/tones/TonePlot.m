clear all;
N=512;

% Load tone 1
data1_1 = audioread('Tone1_1.wav', [1,N]);
data1_2 = audioread('Tone1_2.wav', [1,N]);
data1_3 = audioread('Tone1_3.wav', [1,N]);
% Load tone 1
data2_1 = audioread('Tone2_1.wav', [1,N]);
data2_2 = audioread('Tone2_2.wav', [1,N]);
data2_3 = audioread('Tone2_3.wav', [1,N]);
% Load tone 1
data3_1 = audioread('Tone3_1.wav', [1,N]);
data3_2 = audioread('Tone3_2.wav', [1,N]);
data3_3 = audioread('Tone3_3.wav', [1,N]);
% Load tone 1
data4_1 = audioread('Tone4_1.wav', [1,N]);
data4_2 = audioread('Tone4_2.wav', [1,N]);
data4_3 = audioread('Tone4_3.wav', [1,N]);


figure(1);clf;
plot([data1_1,data1_2,data1_3])
