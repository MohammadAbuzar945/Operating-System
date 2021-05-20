/*Mohammad Abuzar   
	SP19-BCS-089   */


import java.io.File;
import java.util.Scanner;
import java.io.IOException;


public class Multiplication {

    public static void main(String[] args) {

        int[][] input;
        int[][] output;

        try {
            Scanner Fileinput = new Scanner(new File(args[0]));
            int LENGTH = Fileinput.nextInt();
            input = new int[LENGTH][LENGTH];
	     int row=0;
	  
	  do
	 	{
	 	
               for (int column = 0; column < LENGTH; column++)
                    input[row][column] = Fileinput.nextInt();
  
                  row++;  

		}while (row<LENGTH);
		
		
      	     }catch (Exception exp) {
             System.out.println("Error");
            return;
        }

        try {
            Matrix[] mat_Row = new Matrix[input.length]; 
		int row=0;
          
           do{
                mat_Row[row] = new Matrix(input[row], input);
                row++;
		}while(row<mat_Row.length);
		
		
            for (Matrix matrixRow : mat_Row)
                matrixRow.join();

            output = new int[input.length][input.length];

         for (row = 0; row < mat_Row.length; row++)
           output[row] = mat_Row[row].output;
        
        } catch (Exception exp) {
            System.out.println("Error");
            return;
        }
        
        
        
        System.out.println("INPUT ");
        for (int row = 0; row < input.length; row++) {
        	int column=0;
        	while(column<input[0].length)
        	 {
          
                System.out.print(input[row][column] + " ");
                column++;
                }
            System.out.println();
        }
        
        System.out.println();
        
        System.out.println("OUTPUT");
        for (int row = 0; row < output.length; row++) {
        int column=0;
           while(column<output[0].length)
           {
          
                System.out.print(output[row][column] + " ");
            column++;
            }
            System.out.println();
        }

    }
}

class Matrix extends Thread{

    private  int[] row;
    int[] output;
    private  int[][] cols;
    public Matrix(int[] row, int[][] mat) {
        
        this.output = new int[mat[0].length];
        
        this.row = row;
        
        this.cols = mat;

         
      
        Thread thread1= new Thread(this);
        
        thread1.start(); 
        
        
    }

   
    public void run() {
    int ro=0;
      while(ro<output.length)

       {
           for(int column=0; column<output.length; column++)
               output[ro] += row[column] * cols[column][ro];
             ro++;  
               }
    }
}
