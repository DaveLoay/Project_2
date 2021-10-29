set output  "Dos_gráficas.eps"

set autoscale
set multiplot layout 2,1 rowsfirst
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

set title "Fixed Point Signal"
# unset label
set xlabel   "Muestras"
set ylabel   "x(n)"
plot  "fixed.txt"
unset xlabel
unset ylabel
unset title

unset multiplot