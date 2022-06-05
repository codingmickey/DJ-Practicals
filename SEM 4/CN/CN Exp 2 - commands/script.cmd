ipconfig

ipconfig -all

ping www.google.com

echo ----- Runs infinitely so output of these commands are here -----
echo ping -t www.google.com
echo D:\DJSCE\Practicals-ping -t www.google.com

echo Pinging www.google.com [142.251.42.36] with 32 bytes of data: 
echo Reply from 142.251.42.36: bytes=32 time=14ms TTL=118
echo Reply from 142.251.42.36: bytes=32 time=5ms TTL=118
echo Reply from 142.251.42.36: bytes=32 time=6ms TTL=118
echo Reply from 142.251.42.36: bytes=32 time=5ms TTL=118
echo Reply from 142.251.42.36: bytes=32 time=7ms TTL=118

echo Ping statistics for 142.251.42.36:
echo     Packets: Sent = 5, Received = 5, Lost = 0 (0% loss),
echo Approximate round trip times in milli-seconds:
echo     Minimum = 5ms, Maximum = 14ms, Average = 7ms
echo Control-C
echo ^C
echo ----------------------------------------------------------------

netstat

netstat -an

pathping www.google.com

arp -a

echo ----- Runs infinitely so output of these commands are here -----
echo nslookup
echo D:\DJSCE\Practicals-nslookup
echo Default Server:  UnKnown
echo Address:  192.168.0.1

echo - www.google.com
echo Server:  UnKnown
echo Address:  192.168.0.1

echo Non-authoritative answer:
echo Name:    www.google.com
echo Addresses:  2404:6800:4009:830::2004
echo           142.251.42.36

echo -
echo ----------------------------------------------------------------

tracert www.google.com