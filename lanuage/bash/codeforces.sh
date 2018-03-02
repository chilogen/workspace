echo "Enter current date:"
read date
echo "use ss?"
echo "yes(y),no(n)"
read ans
if  ans=="y"; then
	echo "Which to choose:"
	echo "BGPUS1(1)"
	echo "BGPUS2(2)"
	read ss
	if ss=="1"; then
		sslocal -c /home/a/.config/sslocal/BGPUSA1.json&
	fi
	if ss=="2"; then
		sslocal -c /home/a/.config/sslocal/BGPUSA2.json&
	fi

fi
path1="/home/a/workspace/oj/codeforce/contest/"
path2="/home/a/Templates/"
infile="abc.in"
outfile="abc.out"
tpfile="template.cpp"
mkdir "$path1$date"
cp $path2$infile $path1$date
cp $path2$outfile $path1$date
cp $path2$tpfile $path1$date
dolphin $path1$date&
subl $path1$date/$tpfile $path1$date/$infile $path1$date/$outfile
cd $path1$date