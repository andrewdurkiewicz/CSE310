import java.awt.Dimension;
import java.awt.GridLayout;
import javax.swing.JPanel;

public class answerPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public answerPanel()
	{	
		this.setLayout(new GridLayout(1,4, 10, 0));
		//this.setBackground(Color.BLACK);
		this.setOpaque(false);
		this.setVisible(true);
		this.setSize(new Dimension(500,400));
		questionBox q1 = new questionBox(0, 1);
		questionBox q2 = new questionBox(1, 2);
		questionBox q3 = new questionBox(0,3);
		questionBox q4 = new questionBox(1,4);
		this.add(q1);
		this.add(q2);
		this.add(q3);
		this.add(q4);
		

	}
}
