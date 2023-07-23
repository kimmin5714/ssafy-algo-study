import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int money = Integer.parseInt(br.readLine()); // 현금
		
		int[] stock = new int[14]; // 주식
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<stock.length; i++) stock[i] = Integer.parseInt(st.nextToken());
		
		int jm = money; // 준현 현금
		int jStock = 0; // 준현 보유 주식
		for(int i=0; i<stock.length; i++) {
			if(jm >= stock[i]) { 
				jStock = jm / stock[i];
				jm = jm % stock[i];
			}
		}
		jm = jm + (jStock * stock[13]);
		
		int sm = money; // 성민 현금
		int sStock = 0;
		int buyCnt = 0;
		int butCnt2 = 0;
		int sellCnt = 0;
		
		for(int i=0; i<stock.length; i++) {
			if(i != 0 && stock[i] < stock[i-1]) buyCnt++;
			else buyCnt = 0;
			
			if(i != 0 && stock[i] > stock[i-1]) sellCnt++;
			else sellCnt = 0;
			
			if(buyCnt >= 3) {
				sStock = sStock + (sm / stock[i]);
				sm = sm % stock[i];
			}
			
			if(sellCnt >= 3) {
				sm = sm + (stock[i] * sStock);
				sStock = 0;
			}
		}
		
		sm = sm + (sStock * stock[13]);
		
		if(jm > sm) System.out.println("BNP");
		else if(jm < sm) System.out.println("TIMING");
		else System.out.println("SAMESAME");
	}
}
