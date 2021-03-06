set ns [new Simulator]
set nf [open out.nam w]

$ns namtrace-all $nf


proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

set udp0 [new Agent/UDP]
set null0 [new Agent/Null]

$ns attach-agent $n1 $null0
$ns connect $udp0 $null0
$ns attach-agent $n0 $udp0

set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n0 $n3 1Mb 10ms DropTail
$ns duplex-link $n3 $n1 1Mb 10ms DropTail


$ns at 5.0 "finish"
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

$ns run
