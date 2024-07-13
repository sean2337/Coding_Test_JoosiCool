import java.math.BigInteger;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();
        
        Vector<BigInteger> vec = new Vector<>();
        
        while(N-- > 0) {
            String str = scanner.nextLine();
            String sumStr = "";
            for(char c : str.toCharArray()) {
                if(c >= '0' && c <= '9') {
                    sumStr += c;
                } else {
                    if(sumStr.length() > 0) {
                    	BigInteger pushNum = new BigInteger(sumStr);
                        vec.add(pushNum);
                        sumStr = "";
                    }
                }
            }
            if(sumStr.length() > 0) {
            	BigInteger pushNum = new BigInteger(sumStr);
                vec.add(pushNum);
            }
        }
        Collections.sort(vec);
        for(BigInteger i : vec) {
            System.out.println(i);
        }
        
        scanner.close();
    }
}