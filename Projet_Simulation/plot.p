#Type of output and name of it
set terminal pdf
set output "Results/Gaussian.pdf"

list=system('ls -1B Results/*.dat')
plot for [file in list] file w l t file

pause -1 "Hit any key to continue"


#Global Name
#set title ''
#Style of plot (explicit)
#set style data histograms
#Parameters of plot
#set boxwidth 0.9 absolute
#set style fill solid 1.00 border lt -1
#set key noautotitle nobox
# Increase bottom margin to allow room for dates
#set bmargin at screen 0.3
#Set label Name
#set ylabel ''
#set xlabel ''
#Set x labels names
#set xtics border in scale 0,5 nomirror rotate by -45
#set xtics norangelimit
#set xtics ()
#plot 'Results/Compil_O0.dat' using 15:xticlabels(1) linecolor variable

