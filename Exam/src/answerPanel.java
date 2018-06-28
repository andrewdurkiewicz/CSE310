import java.awt.Dimension;
import java.awt.GridLayout;
import javax.swing.JPanel;

public class answerPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static int qN = 0; //question number
	public answerPanel()
	{	
		this.setLayout(new GridLayout(1,4, 10, 0));
		//this.setBackground(Color.BLACK);
		this.setOpaque(false);
		this.setVisible(true);
		this.setSize(new Dimension(500,400));
		int[] solnrange = solution.getSolutionRow(qN);
		questionBox q1 = new questionBox(solnrange[0], 1);
		questionBox q2 = new questionBox(solnrange[1], 2);
		questionBox q3 = new questionBox(solnrange[2],3);
		questionBox q4 = new questionBox(solnrange[3],4);
		qN++;
		this.add(q1);
		this.add(q2);
		this.add(q3);
		this.add(q4);
		

	}
}
