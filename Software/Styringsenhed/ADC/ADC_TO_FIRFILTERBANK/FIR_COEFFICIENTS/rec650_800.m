function Hd = rec650_800
%REC650_800 Returns a discrete-time filter object.

% MATLAB Code
% Generated by MATLAB(R) 9.8 and Signal Processing Toolbox 8.4.
% Generated on: 11-Dec-2020 21:43:14

% FIR Window Bandpass filter designed using the FIR1 function.

% All frequency values are in Hz.
Fs = 10000;  % Sampling Frequency

N    = 134;       % Order
Fc1  = 650;      % First Cutoff Frequency
Fc2  = 800;      % Second Cutoff Frequency
flag = 'scale';  % Sampling Flag
% Create the window vector for the design algorithm.
win = rectwin(N+1);

% Calculate the coefficients using the FIR1 function.
b  = fir1(N, [Fc1 Fc2]/(Fs/2), 'bandpass', win, flag);
Hd = dfilt.dffir(b);

% [EOF]
