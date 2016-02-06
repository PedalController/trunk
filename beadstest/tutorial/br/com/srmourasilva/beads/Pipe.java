package br.com.srmourasilva.beads;

import net.beadsproject.beads.core.AudioContext;
import net.beadsproject.beads.core.UGen;

public class Pipe {
	private AudioContext context;
	private UGen gen;

	private Pipe(AudioContext context, UGen gen) {
		this(context);
		this.gen = gen;
	}

	public Pipe(AudioContext context) {
		this.context = context;
	}

	public Pipe outsIn(UGen gen) {
		if (this.gen != null)
			gen.addInput(this.gen);

		return new Pipe(context, gen);
	}

	public AudioContext outsIn(AudioContext audioContext) {
		audioContext.out.addInput(this.gen);
		
		return audioContext;
	}
}
