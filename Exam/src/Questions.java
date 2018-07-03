import java.io.*;

public class Questions {
	private static String[] qtext = new String[10];;
	static int index = 0;
	public static void generateQuestions() throws IOException
	{
		String c;

		try {
			 FileReader  inputStream = new FileReader("img\\ExamQuestions.txt");
			BufferedReader br = new BufferedReader(inputStream);

			while((c = br.readLine()) != null)
			{
				setText(c);
			}
		
			} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();

		}
	}
	public static String getQuestion(int row)
	{
		return qtext[row];
	}
	public static void setText(String thisrow)
	{
		qtext[index] = thisrow;
		index = index+1;
	}
	
	
	
	
}
