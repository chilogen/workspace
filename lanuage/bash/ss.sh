echo "choose a route:"
echo "BGPUSA1(1)"
echo "BGPUSA2(2)"
echo "BGPHKE(3)"
echo "BGPHKS(4)"
echo "BGPJAP1(5)"
echo "BGPJAP2(6)"
echo "freehongkong(7)"
echo "close(8)##no finished"
echo "more route at /home/a/.config/sslocal"
read route
case $route in
	1)
	sslocal -c /home/a/.config/sslocal/BGPUSA1.json&;;
	2)
	sslocal -c /home/a/.config/sslocal/BGPUSA2.json&;;
	3)
	sslocal -c /home/a/.config/sslocal/BGPHKE.json&;;
	4)
	sslocal -c /home/a/.config/sslocal/BGPHKS.json&;;
	5)
	sslocal -c /home/a/.config/sslocal/BGPJAP1.json&;;
	6)
	sslocal -c /home/a/.config/sslocal/BGPJAP2.json&;;
	7)
	sslocal -c /home/a/.config/sslocal/freefonkong.json&;;
	
esac