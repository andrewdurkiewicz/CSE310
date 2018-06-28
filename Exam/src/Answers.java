
import java.io.*;
import java.util.Scanner;

public class Answers {

	private static String[][] answers = new String[10][4];;
	static int rowIterate = 0;
	static int columnIterate = 0;
	public static void generateAnswers() throws IOException
	{
		String c;

		try {
			FileReader  inputStream = new FileReader("img\\Answers.txt");
			BufferedReader br = new BufferedReader(inputStream);
			while((c = br.readLine()) != null)
			{
				setText(c);
			
			}
		
			} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		solution.generateSolution();
	}
	public static String getAnswer(int row, int column)
	{
		return answers[row][column];
	}
	public static void setText(String thisrow)
	{
		answers[rowIterate][columnIterate] = thisrow;
		if(columnIterate == 3)
		{
			columnIterate = 0;
			rowIterate = rowIterate + 1;
		}
		else if(rowIterate < 10)
		{
			columnIterate = columnIterate + 1;
		}
		
		
	}
	
	
	
	
}
