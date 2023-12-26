#Type of output and name of it
set terminal pdf
set output "Results/Gaussian.pdf"

plot 'Results/Variable_u_n.dat' w l title 'Initial condition', \
     'Results/Variable_u_np1.dat' w l title 'First Order Upwind', \
     'Results/Variable_u_np1_2nd_order.dat' w l title 'Second Order Lax-Wendroff', \
     'Results/Variable_u_ref.dat' w l title 'Exact solution'

pause -1 "Hit any key to continue"
