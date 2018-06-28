import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Image;
import java.rmi.Naming;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class questionAnswerPanel extends JPanel {
	/**
	 * 
	 */
	JPanel qPanel;
	static int qcount;
	private static final long serialVersionUID = 1L;
	
	public questionAnswerPanel(int isPhoto)
	{
		String resources[] = new String[]{"Association.png", "activity.PNG", "State.png"};
		qPanel = new JPanel();
		
		this.setBackground(new Color(0xa4c5fc));
		this.setLayout(new FlowLayout());
		this.setPreferredSize(new Dimension(500,300));
		this.setVisible(true);
		
		answerPanel answers = new answerPanel();
		questionText qtext = new questionText();
		
		this.add(qtext);
		if(isPhoto == 1){
			Image img = new ImageIcon(this.getClass().getResource(resources[qcount])).getImage().getScaledInstance(300, 100, 0);
			JLabel test = new JLabel();
			test.setIcon(new ImageIcon(img));
			qPanel.add(test);
			this.add(qPanel);repaint();
		qcount++;	
		};
		this.add(answers);
		
	}
}
