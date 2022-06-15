make ft_printf
make printf
./ft_printf > ft_printf.txt
./printf > printf.txt
echo ---------- ft_printf ----------
cat ft_printf.txt
echo ---------- printf ----------
cat printf.txt
echo -----------------
diff -a --suppress-common-lines ft_printf.txt printf.txt
echo -----------------
make clean
rm -rf ft_printf.txt printf.txt