import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;
public class testView {
	public static JLabel gradetxt;
	private static int curGrade = 0;
	static int checkPhoto[] = new int[]{0,1,0,0,1,0,1,0,0,0};
	public static void main(String[] args) throws IOException {
		Questions.generateQuestions();
		Answers.generateAnswers();
		// TODO Auto-generated method stub
		JFrame testFrame = new JFrame();
		JPanel test = new JPanel();
		test.setLayout(new GridLayout(10,1,0,200));
		JPanel grade = new JPanel();
		gradetxt = new JLabel("Grade: " + curGrade);
		grade.add(gradetxt);

		JScrollPane scroll = new JScrollPane(test);
		for(int i = 0; i < 10; i++)
		{
			test.add(new questionAnswerPanel(checkPhoto[i]));

		}

		testFrame.setLayout(new BorderLayout());
		testFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		testFrame.setTitle("EXAM");
		testFrame.setSize(1000, 800);
		scroll.setSize(new Dimension(200,400));
		scroll.setWheelScrollingEnabled(true);
		scroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
		scroll.setVisible(true);
		scroll.getVerticalScrollBar().setUnitIncrement(16);
		test.setBackground(new Color(0xa4c5fc));

		testFrame.add(scroll,BorderLayout.CENTER);
		testFrame.add(grade,BorderLayout.SOUTH);
		testFrame.setResizable(false);
		testFrame.setVisible(true);
		

		

	
	}
	 public static void updateGrade(int answerState) {
		// TODO Auto-generated method stub
		curGrade += (10*answerState);
		gradetxt.setText("Grade: " + curGrade );
		

	}
	}
