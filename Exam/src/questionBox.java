import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.OverlayLayout;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class questionBox extends JPanel{
	/**
	 * 
	 */

	private static final long serialVersionUID = 1L;
	JPanel bluescreen;
	JPanel picturePanel;
	String[] possiblePhotos = new String[]{"wrong.png","correct.png"};
	int answerState;
	int answerNumber;
	JTextArea QuestionLabel;
	static int rowValue = 0;
	static int columnValue = 0;

	public questionBox(int as, int an)
	{
		this.answerState = as;
		picturePanel = new JPanel();
		picturePanel.setVisible(false);
		picturePanel.setPreferredSize(new Dimension(200,100));
		
		bluescreen = new JPanel();
		bluescreen.setVisible(true);
		bluescreen.setPreferredSize(new Dimension(200,100));
		
		QuestionLabel = new JTextArea();
		QuestionLabel.setText(Answers.getAnswer(rowValue, columnValue));
		if(columnValue == 3)
		{
			columnValue = 0;
			rowValue = rowValue + 1;
		}
		else if(rowValue < 10)
		{
			columnValue = columnValue + 1;
		}
		QuestionLabel.setForeground(Color.WHITE);
		QuestionLabel.setOpaque(false);
		bluescreen.add(QuestionLabel);
		this.setLayout(new OverlayLayout(this));
		
		
		Image img = new ImageIcon(this.getClass().getResource(possiblePhotos[answerState])).getImage().getScaledInstance(200, 100, 0);
		JLabel answerResult = new JLabel();
		answerResult.setIcon(new ImageIcon(img));
		picturePanel.add(answerResult);
		this.add(picturePanel);
		
		


		
		this.add(bluescreen);
		
		bluescreen.setBackground(Color.BLUE);
		this.setPreferredSize(new Dimension(200,100));
		this.setVisible(true);
		this.setBorder(BorderFactory.createLineBorder(Color.black));
		this.addMouseListener(new MouseAdapter() { 
	          public void mousePressed(MouseEvent e) {
	        	  makeClear();
	          }});
	}
	private void makeClear()
	{
		bluescreen.setVisible(false);
		picturePanel.setVisible(true);
		testView.updateGrade(this.answerState);
	}

}
