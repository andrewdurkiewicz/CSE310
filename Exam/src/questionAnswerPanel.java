import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import javax.swing.JPanel;


public class questionAnswerPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public questionAnswerPanel()
	{
		this.setBackground(new Color(0xa4c5fc));
		this.setLayout(new FlowLayout());
		this.setPreferredSize(new Dimension(500,200));
		this.setVisible(true);
		
		answerPanel answers = new answerPanel();
		questionText qtext = new questionText();
		this.add(qtext);
		this.add(answers);
		
	}
}
