cd /home/a
rm * -r
cd /etc/apt
rm sources.list
cd /mnt/config
mv sources.list /etc/apt
apt-get update
apt-get install vim htop fcitx ifstat gdb
cp install /home/a -r
cp Download /home/a -r
cp book /home/a -r
cp config /home/a -r
cp system /home/a -r
cp code /home/a -r
cp netpasswd /home/a -r
cp network /home/a -r
cd /home/a
chown a * -R
cd /mnt
apt-get autoremove aisleriot four-in-a-row hitori iagno libgme0 lightsoff quadrapassel swell-foop gnome-calculator gnome-chess gnome-clocks gnome-contacts gnome-dictionary gnome-documents gnome-font-viewer gnome-games gnome-klotski gnome-logs gnome-mahjongg gnome-maps gnome-mines gnome-music gnome-nettool gnome-nibbles gnome-orca gnome-packagekit gnome-photos gnome-robots gnome-screenshot gnome-sound-recorder gnome-sudoku gnome-system-log gnome-system-monitor gnome-tetravex gnome-tweak-tool yelp imagemagick empathy polari tali hamster-applet simple-scan reportbug bijiben inkscape five-or-more xboard transmission-gtk rhythmbox iceweasel
dpkg -l|grep ^rc|awk '{print $2}'|xargs dpkg -P
apt-get upgrade
cd /home/a/install
dpkg -i sougou.deb
dpkg -i neteast.deb
apt-get -f install
