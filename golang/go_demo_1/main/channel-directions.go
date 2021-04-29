package main

import "fmt"

func main() {
	pings := make(chan string, 1)
	pangs := make(chan string, 1)
	ping(pings, "我的消息")
	pong(pings, pangs)
	fmt.Println(<-pangs)
}

func ping(ping chan<- string, message string) {
	ping <- message
}
func pong(ping <-chan string, pang chan<- string) {
	msg := <-ping
	pang <- msg
}
