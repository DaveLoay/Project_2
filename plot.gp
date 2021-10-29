set output  "Dos_gráficas.eps"

set autoscale
set multiplot layout 3,1 rowsfirst
set grid
set style data lines

#------------- Graf 1 ----------------
set title "Original"
#unset label
set xlabel   "muestras"
set ylabel   "x(n)"
plot  "sine.txt"
unset xlabel
unset ylabel
unset title

set title "Ruido"
# unset label
set xlabel   "Muestras"
set ylabel   "x(n)"
plot  "noise.txt"
unset xlabel
unset ylabel
unset title



#------------- Graf 2 ----------------
set title "Senal con ruido"
# unset label
set xlabel   "Muestras"
set ylabel   "x(n)"
plot  "dirt.txt"
unset xlabel
unset ylabel
unset title
#pause(3)
unset multiplot





#pause -1 
#
