#!/in/bash

##This script used to config kali after install
##copyright  quantu_zo
##2017.10.19
##version 0.1

##This script need root access
ROOT_ID=0
if [ $UID != $ROOT_ID ]
then
	echo "Permission denied"
	exit
fi

##update sofeware sources and upgrade
if [ ! -e /etc/apt/sources.list.bac ]
then
	mv /etc/apt/sources.list /etc/apt/sources.list.bac
	mv ./etc/sources.list /etc/apt/sources.list
	apt update&&apt upgrade
fi

##install genneral software
apt install htop ifstat
apt install foremost

##install python modules

##add vpn support
apt install shadowsocks privoxy
if [! -e /etc/privoxy/config.bac ]
then
	mv /etc/privoxy/config /etc/config/config.bac
	mv ./etc/config /etc/privoxy/config
	service privoxy restart
fi

#install sougou pinyin
dpkg -i sogoupinyin_2.1.0.0082_amd64.deb
apt -f install

##add 32-base support
#dpkg --add-architecture i386
#apt upgrade
#fix -m32 problem
#apt install gcc-multilib g++-multilib
##


##system reboot
echo "system will reboot[Y/N]"
read rebootcommond
if [ $rebootcommond -eq "Y" ]
then	reboot
else echo "all work done,strongly suggess you reboot manually!!!"
	 echo "or just logout to enable sougou-pinyin"
fi