//Generate an "analog" sine wave

#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//Constants for the sine wave
#define N 10000
float f = 12;

//file pointer
FILE *fsin, *fnoi, *fdirt;

//constant for the time vector
float buf = 0;
float inicio = 0;
float final = 1;

//noise properties
float noise_amp = 1.4;


int main(){

//Open the files
fsin = fopen("sine.txt", "w");
fnoi = fopen("noise.txt", "w");
fdirt = fopen("dirt.txt", "w");

//Ciclo para crear el vector de tiempo
buf = (final-inicio)/N;
vector<float> t(N,0);
for (int i = 0; i < N; i++){
    t[i] = t[i-1] + buf;      
}

//Ciclo para crear el vector de datos
vector<float> x(N,0);
for (int n = 0; n < N; n++){
    x[n] = sin(2*M_PI*t[n]*f);  
    fprintf(fsin,"%f \n",x[n]);  
}

//Generación del vector de ruido
vector<float> noise(N,0);
for (int m = 0; m < N; m++){
    noise[m] = noise_amp*((float)rand()/(float)RAND_MAX);
    noise[m] = noise[m] - noise_amp/2;
    fprintf(fnoi,"%f \n",noise[m]);
}

float r_max = *max_element(noise.begin(), noise.end());
printf("%f \n",r_max);

//Suma de la señal sinusoidal con la señal de ruido
vector<float> dirt(N,0);
for (int j = 0; j < N; j++){
    dirt[j] = (x[j]+(noise[j]));
    fprintf(fdirt,"%f \n",dirt[j]);
}

//SNR variables
float P_sig = 0;
float P_noise = 0;
float SNR = 0;

//SNR calculation
for (int i = 0; i < N; i++){
    P_sig = P_sig + pow(abs(x[i]),2);
    P_noise = P_noise + pow(abs(noise[i]),2);
}
P_sig = P_sig/(2*N);
P_noise = P_noise/(2*N);
SNR = 10*log10f(P_sig/P_noise);
printf("Sine power: %f \n", P_sig);
printf("Noise power: %f \n", P_noise);
printf("SNR: %f \n", SNR); 



//Close the files
fclose(fsin);
fclose(fnoi);
fclose(fdirt);

 
system("gnuplot -p plot.gp ");
//End of file.
}