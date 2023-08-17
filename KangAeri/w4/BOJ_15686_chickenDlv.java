package com.ssafy.probs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_15686_chickenDlv {
	//private static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		int n=0,m=0,i=0,j=0, ans=0;
		int[][] city;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		n = Integer.parseInt(in[0]);
		m = Integer.parseInt(in[1]);
		
		city = new int[n][n];
		
		for(i=0;i<n;i++) {
			in = br.readLine().split(" ");
			for(j=0;j<n;j++) {
				city[i][j] = Integer.parseInt(in[j]);
			}
		}
		
		
		
		
		
		System.out.println(ans);
		
		
	}
}
