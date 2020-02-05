#!/usr/bin/octave -qf
1;
# define plot

function plot_wav(fileName)
	
	ch_map = [1,3,2,0]
	[y,fs] = audioread(fileName);
	t = linspace(0,length(y)/fs,length(y));

	figure(1,'position',[0,0,1600,900],'name',fileName);

	channels = size(y,2)

	for i = 1:channels
		ch = ch_map(i)
		subplot(channels,1,i)
		plot(t,y(:,ch))
		#axis([0,.2,-1,1])
	end

	figure(2,'position',[0,0,1600,900],'name','freq');

		for i = 1:channels
		ch = ch_map(i)
		subplot(channels,1,i)
		plot(t,y(:,ch))
		#axis([0,.2,-1,1])
	end


endfunction

function fft_plot(fileName)

	ch_map = [1,2,3,4]

  [y, fs] = audioread(fileName);

	figure(1,'position',[0,0,1600,900],'name',fileName);
	
	channels = size(y,2)
  Ts  = 1 ./ fs;
  fN = fs ./ 2;
  m = length(y(:,2));
  Tr = m .* Ts;
  fr = 1 ./ Tr;
  freqs = [0, fr:fr:fN, (-fN + fr):fr:(-fr)]';
  qm = m ./ 4;
  hm = m ./ 2;
  t = ((-qm + 1) .* Ts):Ts:((hm + qm) .* Ts);
	idx =1;
	for i = 1:channels
		ch = ch_map(i)
		Sy = fft(y(:,ch));
		Syy = Sy .* conj(Sy);
		idx = (ch *2) -1;
		subplot(channels, 2, idx+1)
		plot(freqs(2:floor(m ./ 2)), Syy(2:floor(m ./ 2)));
		title('Power spectrum')
		xlabel(' Frequency (Hz)')
		subplot(channels, 2, idx )
		plot(t, y(:,ch))
		xlabel('Time (s)')
	end
  
endfunction

arg_list=argv();
file = arg_list{1};
fft_plot(file);
pause();
