package br.com.srmourasilva.beads;

import net.beadsproject.beads.core.AudioContext;
import net.beadsproject.beads.ugens.Gain;
import net.beadsproject.beads.ugens.Noise;

public class Main {
	public static void main(String[] args) {
		AudioContext audioContext = new AudioContext();

		Noise noise = new Noise(audioContext);
		Gain gain = new Gain(audioContext, 1, 0.1f);

		//Envelope freqEnv = new Envelope(audioContext, 1000);
		//WavePlayer wp = new WavePlayer(audioContext, freqEnv, Buffer.SINE);
		//audioContext.out.addInput(wp);
		//gain.addInput(wp);
		
		Pipe in = new Pipe(audioContext);
		in.outsIn(noise)
		  .outsIn(gain)
		  .outsIn(audioContext).start();
		
		/*
		noise.outIn(gain).outIn(audioContext)

		noise.outsOn(gain).outsOn(audioContext)

		noise.output().connectOn(gain.input())
			 .output().connectOn(audioContext.output());

		noise.connectWith(gain.input()).connectWith(audioContext.input());
		*/
	}
}
