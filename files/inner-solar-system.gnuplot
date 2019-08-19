set datafile separator ','
set autoscale xy

set terminal png size 2000,2000
img_output = sprintf("%s.png", ARG1)
set output img_output

graph_title=sprintf("Simulation of 300 years with {/Symbol D}t = %ss", ARG2)
set title font "Arial,24"
set title graph_title

set label 1 'Mercury' at 0,7.00e10 textcolor linestyle 1 font "Arial,18"
set label 2 'Venus'   at 0,1.03e11 textcolor linestyle 2 font "Arial,18"
set label 3 'Earth'   at 0,1.42e11 textcolor linestyle 3 font "Arial,18"
set label 4 'Mars'    at 0,2.30e11 textcolor linestyle 4 font "Arial,18"

plot ARG1 \
       using  ($8-$2): ($9-$3) with dots notitle, \
    '' using ($14-$2):($15-$3) with dots notitle, \
    '' using ($20-$2):($21-$3) with dots notitle, \
    '' using ($26-$2):($27-$3) with dots notitle
