set datafile separator ','
set key off
set autoscale xy

splot ARG1 \
       every 30 using  ($8-$2): ($9-$3):($10-$4) with dots, \
    '' every 30 using ($14-$2):($15-$3):($16-$4) with dots, \
    '' every 30 using ($20-$2):($21-$3):($22-$4) with dots, \
    '' every 30 using ($26-$2):($27-$3):($28-$4) with dots, \
    '' every 30 using ($32-$2):($33-$3):($34-$4) with dots, \
    '' every 30 using ($38-$2):($39-$3):($40-$4) with dots, \
    '' every 30 using ($44-$2):($45-$3):($46-$4) with dots, \
    '' every 30 using ($50-$2):($51-$3):($52-$4) with dots, \
    '' every 30 using ($56-$2):($57-$3):($58-$4) with dots, \
    '' every 30 using ($62-$2):($63-$3):($64-$4) with dots

