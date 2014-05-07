package main

import (
	"flag"
	"fmt"
	"log"
	"net"
)

func main() {
	ipPtr := flag.String("ip", "127.0.0.1:9001", "The IP and port to connect to.")
	toastingTimePtr := flag.String("time", "20", "The time to toast.")
	flag.Parse()

	conn, err := net.Dial("tcp", *ipPtr)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Fprintf(conn, *toastingTimePtr)
	fmt.Println("Sent ;)")
}
