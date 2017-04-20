/* Bismillahir Rahmanir Rahim */

#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

int HC(int N){
	srand(time(NULL));
	int a = 1, b = N, lst = 0;
	while(a < b){
		int g, f;
		int mid = a + (b - a) / 2;
		if(a == lst) g = Guess(b), f = 1, lst = b;
		else if(b == lst) g = Guess(a), f = -1, lst = a;
		else if(rand() % 2){
			g = Guess(a), g = Guess(b);
			f = +1, lst = b;
		}
		else{
			g = Guess(b), g = Guess(a);
			f = -1, lst = a;
		}

		if(g == 0) return (a + b) / 2;
		if(f == -1) g *= -1;

		if(g == +1) a = mid + 1;
		if(g == -1) b = (a + b - 1) / 2;
	}
	return a;
}
