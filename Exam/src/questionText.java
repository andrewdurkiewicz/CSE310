import javax.swing.JTextArea;

import java.awt.Color;
import java.awt.ComponentOrientation;
import java.awt.Dimension;
import java.awt.Font;

import javax.swing.JPanel;

public class questionText extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public static int N = 0;
	public questionText(){
		N = N + 1;
		JTextArea question = new JTextArea();
		question.setText("Question #" + N + ": " + Questions.getQuestion(N-1));
		question.setFont(new Font("SansSerif", Font.ITALIC + Font.BOLD, 12));
		question.setWrapStyleWord(true);
        question.setForeground(Color.BLACK);

		question.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		question.setPreferredSize(new Dimension(800,50));
		question.setEditable(false);
		question.setOpaque(false);
		this.setOpaque(false);

		this.add(question);
	}

}
