#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define N 10000

int qi = 11;
int c;
float s;

//Functions to go from floatings to fixed point and vice versa
int tofixed(float,int);
float tofloat(int, int);

//Pointers to read the "analog" signal saved on the txt file
FILE *fsin, *ffixs;




int main(){

fsin = fopen("sine.txt", "r");
ffixs = fopen("fixed.txt", "w");

//Read the analog signal and save it into t vector
vector<float> t(N,0);
for (int i = 0; i < N; i++){
    fscanf(fsin, "%f", &t[i]);      
}

float r_max = *max_element(t.begin(), t.end());
printf("Sine max number: %f \n", r_max);


vector<int> fp_sin(N,0);
for (int i = 0; i < N; i++){
    fp_sin[i] = tofixed(t[i], qi);
    fprintf(ffixs, "%d\n", fp_sin[i]);
    printf("i:%d\n", i);
    printf("Fixed:%d\n", fp_sin[i]);
}



fclose(fsin);
fclose(ffixs);

system("gnuplot -p plote.gp ");

//End of code
}


//**************************************************************
//Function to convert from floating point to fixed point integer 
//**************************************************************
int tofixed(float f, int e)
{
//Section that goes from floating point to fixed point integer
//Floating number * 2^qi ---> f*2^qi
//halo
float a;
int b;
a = f * pow(2, e);
b = round(a);

//In case of a negative number, obtain the two's complement

if(a < 0)
{
b = abs(b);
b = ~b;
b = b + 1;

}
return b;
}


//*************************************************************
//Function that goes from fixed point integer to floating point
//*************************************************************
float tofloat(int x, int e){
//Section that goes from fixed point integer to floating point
int c, sign;
c = abs(x);
sign = 1;

//Getting back from the two's complement
if(x < 0)
{
c = x - 1;
c = ~c;
sign = -1;  
}

//Converting back to floating point with it respective sign and qi
float f = 0;
f = (1.0 * c)/pow(2, e);
f = f * sign;

return f;

}