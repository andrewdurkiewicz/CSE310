
import java.io.*;

public class solution {
	private static int[][] boolVal = new int[10][4];
	private static int index = 0;
	public static void generateSolution() throws IOException {
		String c;
		FileReader  inputStream = new FileReader("img\\BinaryCorrect.txt");
		BufferedReader br = new BufferedReader(inputStream);
		while((c = br.readLine()) != null)
		{
			System.out.println(c);
			SetText(c);
			
			index++;

		
		}
		// TODO Auto-generated method stub
		br.close();
	}
	private static void SetText(String c) {
		int k;
		for(int i = 0; i< 4; i++)
		{
			k = Integer.parseInt(c.substring(i, i+1).trim());
			boolVal[index][i] =  k;
		}
	}
	

	public static int[] getSolutionRow(int qN) {
		// TODO Auto-generated method stub
		return boolVal[qN];
	}
}
