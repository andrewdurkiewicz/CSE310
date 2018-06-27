import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;

public class testView {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame testFrame = new JFrame();
		JPanel test = new JPanel();
		test.setLayout(new GridLayout(10,1));

		JScrollPane scroll = new JScrollPane(test);
		for(int i = 0; i < 10; i++)
		{
			test.add(new questionAnswerPanel());

		}

		testFrame.setLayout(new GridLayout(1,1));
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

		testFrame.add(scroll);
		testFrame.setResizable(false);
		testFrame.setVisible(true);
		

		

	}

}
