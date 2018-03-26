echo "choose a route:"
echo "BGPHK1(1)"
echo "BGPHK2(2)"
echo "BGPHK3(3)"
echo "BGPUSA(4)"
echo "BGPJAP1(5)"
echo "more route at /home/a/.config/sslocal"
read route
case $route in
	1)
	sslocal -c /home/a/.config/sslocal/BGPHK1.json&;;
	2)
	sslocal -c /home/a/.config/sslocal/BGPHK2.json&;;
	3)
	sslocal -c /home/a/.config/sslocal/BGPHK3.json&;;
	4)
	sslocal -c /home/a/.config/sslocal/BGPUSA1.json&;;
	5)
	sslocal -c /home/a/.config/sslocal/BGPJAP1.json&;;
	
esac
