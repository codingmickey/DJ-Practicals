ipconfig

ipconfig -all

ping www.google.com

@REM ----- Runs infinitely so output of these commands are here -----
@REM ping -t www.google.com
@REM D:\DJSCE\Practicals>ping -t www.google.com

@REM Pinging www.google.com [142.251.42.36] with 32 bytes of data: 
@REM Reply from 142.251.42.36: bytes=32 time=14ms TTL=118
@REM Reply from 142.251.42.36: bytes=32 time=5ms TTL=118
@REM Reply from 142.251.42.36: bytes=32 time=6ms TTL=118
@REM Reply from 142.251.42.36: bytes=32 time=5ms TTL=118
@REM Reply from 142.251.42.36: bytes=32 time=7ms TTL=118

@REM Ping statistics for 142.251.42.36:
@REM     Packets: Sent = 5, Received = 5, Lost = 0 (0% loss),
@REM Approximate round trip times in milli-seconds:
@REM     Minimum = 5ms, Maximum = 14ms, Average = 7ms
@REM Control-C
@REM ^C
@REM ----------------------------------------------------------------

netstat

netstat -an

pathping www.google.com

arp -a

@REM ----- Runs infinitely so output of these commands are here -----
@REM nslookup
@REM D:\DJSCE\Practicals>nslookup
@REM Default Server:  UnKnown
@REM Address:  192.168.0.1

@REM > www.google.com
@REM Server:  UnKnown
@REM Address:  192.168.0.1

@REM Non-authoritative answer:
@REM Name:    www.google.com
@REM Addresses:  2404:6800:4009:830::2004
@REM           142.251.42.36

@REM -
@REM ----------------------------------------------------------------

tracert www.google.com