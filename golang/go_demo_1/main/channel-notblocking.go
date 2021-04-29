package main

import "fmt"

func main() {
	messages := make(chan string, 1)
	signals := make(chan bool, 1)
	select {
	case msg := <-messages:
		fmt.Println("received message", msg)
	default:
		fmt.Println("no message received!")
	}
	msg := "hi"
	messages <- msg
	select {
	case messages <- msg:
		fmt.Println("sent message", msg)
	default:
		fmt.Println("no message send")
	}
	select {
	case msg := <-messages:
		fmt.Println("received message", msg)
	case signal := <-signals:
		fmt.Println("received signal", signal)
	default:
		fmt.Println("no anything is received")
	}
}
